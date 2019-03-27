/*
Copyright 2018 Thomas Spitzer <doxyqml@astade.de>
All rights reserved.

This software is a fork of the doxyqml tool written in python, by Aurélien Gâteau
(https://github.com/agateau/doxyqml)

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.
*/

#include <stdio.h>
#include <argp.h>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <regex>
#include <fstream>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/classic_position_iterator.hpp>
#include <boost/spirit/repository/include/qi_confix.hpp>
#include <boost/spirit/include/qi_lexeme.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/spirit/include/qi_action.hpp>

#include "CRootElement.h"
#include "CQmlObject.h"
#include "CMultilineComment.h"
#include "CSinglelineComment.h"
#include "CImport.h"
#include "CObjectDeclaration.h"
#include "CProperty.h"
#include "CSignal.h"
#include "CFunction.h"
#include "CNamespaceImport.h"

namespace classic = boost::spirit::classic;
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

using boost::spirit::repository::confix;

/* This structure is used by main to communicate with parse_opt. */
struct Arguments
{
    Arguments(): debug(false) {}
    bool debug;
    std::string filename;
};

Arguments arguments;
doxyqml::CRootElement gRootObject;


void add_multiline_comment(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    doxyqml::CMultilineComment* p = new doxyqml::CMultilineComment(name);
    gRootObject.addChild(p);
}

void add_singleline_comment(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    doxyqml::CSinglelineComment* p = new doxyqml::CSinglelineComment(name);
    gRootObject.addChild(p);
}


void add_property(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    doxyqml::CProperty* p = new doxyqml::CProperty(name);
    gRootObject.addChild(p);
}

void add_signal(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    doxyqml::CSignal* p = new doxyqml::CSignal(name);
    gRootObject.addChild(p);
}

void add_function(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    doxyqml::CFunction* p = new doxyqml::CFunction(name);
    gRootObject.addChild(p);
}

void add_importline(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    doxyqml::CImport* p = new doxyqml::CImport(name);
    gRootObject.addChild(p);
}

void add_SubObject(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    doxyqml::CObjectDeclaration* o = new doxyqml::CObjectDeclaration(name);
    gRootObject.addSubObject(o);
}

void setBasename(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    gRootObject.setBaseClass(name);
    gRootObject.setMemberState();
}

void set_id(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    gRootObject.set_id(name);
}

void add_namespace(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    gRootObject.add_namespace(name);
}

std::string gNamespaceText;
void setNamespaceText(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    gNamespaceText = name;
}

std::string gNamespaceIdentifier;
void setNamespaceIdentifier(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    gNamespaceIdentifier = name;
}

void add_namespaceImport(const boost::spirit::unused_type& name, const boost::spirit::unused_type& it, bool& pass)
{
    doxyqml::CNamespaceImport* o = new doxyqml::CNamespaceImport(gNamespaceText, gNamespaceIdentifier);
    gRootObject.addChild(o);
}


template <typename Iterator>
struct qml_parser
  : qi::grammar<Iterator>
{
    qml_parser() : qml_parser::base_type(rootElements)
    {
        rootElements    =   *(topElement > space)
                        >>  topObjectDeclaration
                        >>  space
                        ;
        
        comment         =   multilineComment[add_multiline_comment]
                        |   singlelineComment[add_singleline_comment]
                        ;
        
        topElement      =   comment
                        |   namespaceImportLine[add_namespaceImport]
                        |   importLine[add_importline]
                        ;
                        
        objectElement   =   comment
                        |   onCompletionHandler
                        |   -(qi::lit("readonly") >> space) >> property[add_property]
                        |   signal[add_signal]
                        |   function[add_function]
                        |   objectDeclaration
                        |   idText
                        |   slot
                        |   propertySetting
                        |   structPropertySetting
                        ;
        
        topObjectDeclaration    = uppercaseIdentifier[setBasename]
                                >>  *(qi::char_('.') >> uppercaseIdentifier[add_namespace])
                                > space
                                > *(qi::lit("on") > space > lowercaseIdentifier > space)
                                > qi::lit('{')
                                > space
                                > *(objectElement > space)
                                > qi::lit('}')
                                ;
        
        idText              =   "id:"
                            >>  space
                            >>  lowercaseIdentifier[set_id]
                            >>  space
                            >>  -qi::lit(';')
                            ;
        
        valueText           =   *(inCurlyBrackets | qi::lit('.') | (qi::char_ - qi::eol - qi::char_('}')))
                            ;
        
        propertySetting     =   -(uppercaseIdentifier >> qi::lit('.'))
                            >>  qualifiedIdentifier
                            >>  space
                            >>  qi::lit(':')
                            >>  space
                            >>  (valueText | objectDeclaration)
                            >>  space
                            >>  -qi::lit(';')
                            ;
                            
        structPropertySetting = lowercaseIdentifier
                            >>  space
                            >>  inCurlyBrackets
                            ;
        
        objectDeclaration   =   uppercaseIdentifier[add_SubObject]
                            >>  *(qi::char_('.') >> uppercaseIdentifier[add_namespace])
                            >>  space
                            >> *(qi::lit("on") > space > lowercaseIdentifier > space)
                            >>  qi::lit('{')
                            >>  space
                            >>  *(objectElement > space)
                            >>  qi::lit('}')
                            ;
        
        function            =   qi::lit("function")
                            >>  space
                            >>  -(lowercaseIdentifier >>  space)
                            >>  paramList
                            >>  space
                            >>  inCurlyBrackets
                            ;
                            
        quotedText          =   confix("\"", "\"")[*((qi::char_ - "\"" - "\\") | ("\\" > qi::char_))];

                            
        qualifiedIdentifier =   lowercaseIdentifier
                            >>  *(qi::lit('.') > lowercaseIdentifier)
                            ;
                            
        someText            =   qi::lit(' ') 
                            |   qi::lit('\n') 
                            |   qi::lit('\t')
                            |   inCurlyBrackets
                            |   quotedText
                            |   qi::alnum 
                            |   qi::char_("^,.;:_<>|~!*§$%&/()=?[]'-\\") 
                            ;
                            
        inCurlyBrackets     =   qi::lit('{')
                            >>  *someText
                            >>  qi::lit('}')
                            ;
                            
        paramList           =   qi::char_('(')
                            >>  *(qi::char_ - ")")
                            >>  qi::char_(')')
                            ;
        
        slot                =   -qi::lit("Component.")
                            >>  lowercaseIdentifier
                            >>  space
                            >>  qi::lit(':')
                            >>  space
                            >>  (function | inCurlyBrackets)
                            ;
                            
        onCompletionHandler =   (qi::lit("Component.onCompleted") | qi::lit("Component.onDestruction"))
                            >>  space
                            >>  qi::lit(':')
                            >>  space
                            >>  (inCurlyBrackets | *(qi::char_ - qi::eol - qi::char_('}')))
                            ;
        
        namespaceImportLine = qi::lit("import")
                            >>  space
                            >>  quotedText[setNamespaceText]
                            >>  space
                            >>  qi::lit("as")
                            >>  space
                            >>  uppercaseIdentifier[setNamespaceIdentifier]
                            ;
        
        property            = object_property | single_line_property;
        
        single_line_property  =  confix("property", qi::eol)[*(qi::char_ - qi::eol)];
        
        object_property     =   qi::lit("property")
                            >>  space
                            >>  uppercaseIdentifier
                            >>  qi::char_(" \t")
                            >>  space
                            >>  lowercaseIdentifier
                            >>  space
                            >>  qi::lit(':')
                            >>  space
                            >>  uppercaseIdentifier
                            >>  space
                            >>  inCurlyBrackets
                            ;
                           


        space = *(qi::lit(' ') | qi::lit('\n') | qi::lit('\t'));
        multilineComment = confix("/*", "*/")[*(qi::char_ - "*/")];
        singlelineComment = confix("//", qi::eol)[*(qi::char_ - qi::eol)];
        importLine = confix("import", qi::eol)[*(qi::char_ - qi::eol)];
        signal =  confix("signal", qi::eol)[*(qi::char_ - qi::eol)];
        uppercaseIdentifier = qi::char_("A-Z") > *qi::char_("_a-zA-Z0-9");
        lowercaseIdentifier = qi::char_("a-z") > *qi::char_("_a-zA-Z0-9");
    }
    
    qi::rule<Iterator, std::string()> multilineComment;
    qi::rule<Iterator, std::string()> singlelineComment;
    qi::rule<Iterator, std::string()> importLine;
    qi::rule<Iterator> namespaceImportLine;
    qi::rule<Iterator, std::string()> uppercaseIdentifier;
    qi::rule<Iterator, std::string()> lowercaseIdentifier;
    qi::rule<Iterator, std::string()> qualifiedIdentifier;
    
    qi::rule<Iterator> rootElements;
    qi::rule<Iterator, std::string()> topElement;
    qi::rule<Iterator> objectElement;
    qi::rule<Iterator> space;
    qi::rule<Iterator, std::string()> objectDeclaration;
    qi::rule<Iterator, std::string()> topObjectDeclaration;
    qi::rule<Iterator, std::string()> property;
    qi::rule<Iterator, std::string()> single_line_property;
    qi::rule<Iterator, std::string()> object_property;
    qi::rule<Iterator, std::string()> signal;
    qi::rule<Iterator, std::string()> quotedText;
    qi::rule<Iterator, std::string()> idText;
    qi::rule<Iterator, std::string()> valueText;
    qi::rule<Iterator> inCurlyBrackets;
    qi::rule<Iterator> propertySetting;
    qi::rule<Iterator> structPropertySetting;
    qi::rule<Iterator> slot;
    qi::rule<Iterator, std::string()> paramList;
    qi::rule<Iterator, std::string()> function;
    qi::rule<Iterator, std::string()> someText;
    qi::rule<Iterator> comment;
    qi::rule<Iterator> onCompletionHandler;
};

// wrap forward iterator with position iterator, to record the position
typedef classic::position_iterator2<boost::spirit::istream_iterator> pos_iterator_type;

bool load(const std::string& filename)
{
    try
    {
        // open file, disable skipping of whitespace
        std::ifstream in(filename.c_str());
        
        if (arguments.debug)
             std::cerr
                << "doxyqml: Parsing file: "
                << filename
                << std::endl;
                
        in.unsetf(std::ios::skipws);

        // wrap istream into iterator
        boost::spirit::istream_iterator begin(in);
        boost::spirit::istream_iterator end;

        pos_iterator_type position_begin(begin, end, filename.c_str());
        pos_iterator_type position_end;

        qml_parser<pos_iterator_type> p;  // create instance of parser
        gRootObject.setFilename(filename);

        qi::phrase_parse(position_begin, position_end, p, qi::space);

        if (position_begin != position_end)
            throw qi::expectation_failure<pos_iterator_type>(position_begin, position_end,boost::spirit::info("general error"));
    }
    
    catch(const qi::expectation_failure<pos_iterator_type> e)
    {
        const classic::file_position_base<std::string>& pos = e.first.get_position();
        std::cerr   << pos.file << ':'
                    << pos.line << ": error: "
                    << e.what_  << std::endl;
        return false;    
    }
    
    return true;
}


const char *argp_program_version =
"doxyqml 2.2";

const char *argp_program_bug_address =
"<t.spitzer@astade.de>";

static struct argp_option options[] =
{
  {"debug", 'd', 0,            0, "Log debug info to stderr"},
  {0}
};

static error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    Arguments* arguments = (Arguments*) state->input;

    switch (key)
    {
    case 'd':
        arguments->debug = true;
        break;
    case ARGP_KEY_ARG:
        if (state->arg_num >= 1)
            argp_usage (state);
        else
            arguments->filename = arg;
        break;
    case ARGP_KEY_END:
      if (state->arg_num < 1)
        /* Not enough arguments. */
        argp_usage (state);
      break;
    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static char doc[] =
"doxyqml -- A program to convert qml to pseudo C++ for doxygen.\n"
"\n"
"doxyqml generates namespaces from filepath.\n"
"If you want to strip some path information\nyou can define an environment variable \"doxyqml_strip\"\n"
"If the variable is not defined,\n    \"/qml/\" is assumed\n"
"So a file \"/home/thomas/myProg/src/qml/main.qml\" results in a\n    classname: \"qml::main\"\n"
"if you use \"export doxyqml_strip=/myProg/\" it'll results in the\n    classname: \"myProg::qml::main\"\n"
"\n"
;

/* A description of the arguments we accept. */
static char args_doc[] = "qml_file";

static struct argp argp = {options, parse_opt, args_doc, doc};

int main (int argc, char **argv)
{
    /* Where the magic happens */
    argp_parse (&argp, argc, argv, 0, 0, &arguments);
    
    if (!arguments.filename.empty())
    {
        std::string qmldir(arguments.filename);
        size_t pos = qmldir.rfind('/');
        if (pos != std::string::npos)
            qmldir.erase(pos);

        qmldir += "/qmldir";
        std::ifstream qmldirText;
        qmldirText.open(qmldir.c_str());
        
        if (qmldirText.good())
        {
            std::string line;
            std::regex e("^module\\s+((?:\\w|\\.)+)\\s*$"); // the pattern
            while (getline(qmldirText, line))
            {
                std::cmatch cm;
                bool match = regex_search(line.c_str(), cm, e);
                if (match)
                {
                    std::string s(cm[1]);
                    gRootObject.setNamespace(s);
                }
            }
        }

        qmldirText.close();

        load(arguments.filename);
    }
    gRootObject.print();
    return 0;
}
