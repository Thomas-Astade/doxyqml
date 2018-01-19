#include <stdio.h>
#include <argp.h>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/classic_position_iterator.hpp>
#include <boost/spirit/repository/include/qi_confix.hpp>

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
std::vector<doxyqml::CQmlObject*> gObjectStack; // holds the current objets during parsing

void add_multiline_comment(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    doxyqml::CMultilineComment* p = new doxyqml::CMultilineComment(name);
    gObjectStack.back()->addChild(p);
}

void add_singleline_comment(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    doxyqml::CSinglelineComment* p = new doxyqml::CSinglelineComment(name);
    gObjectStack.back()->addChild(p);
}

void add_property(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    doxyqml::CProperty* p = new doxyqml::CProperty(name);
    gObjectStack.back()->addChild(p);
}

void add_importline(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    doxyqml::CImport* p = new doxyqml::CImport(name);
    gObjectStack.back()->addChild(p);
}

void add_Object(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    doxyqml::CRootElement* p = dynamic_cast<doxyqml::CRootElement*>(gObjectStack.back());
    if (p)
        p->setBaseClass(name);
    doxyqml::CObjectDeclaration* o = new doxyqml::CObjectDeclaration(name);
    gObjectStack.back()->addChild(o);
    gObjectStack.push_back(o);
}

template <typename Iterator>
struct qml_parser
  : qi::grammar<Iterator>
{
    qml_parser() : qml_parser::base_type(rootElements)
    {
        rootElements    =   *(topElement > space)
                        >   objectDeclaration
                        >   space
                        ;
        
        comment         =   multilineComment[add_multiline_comment]
                        |   singlelineComment[add_singleline_comment]
                        ;
        
        comments        =   *(comment > space);
        
        topElement      =   comment
                        |   importLine[add_importline]
                        ;
                        
        objectElement   =   comment
                        |   property[add_property]
                        ;
        
        objectDeclaration   = uppercaseIdentifier[add_Object]
                            > space
                            > qi::lit('{')
                            > space
                            > *(objectElement > space)
                            > qi::lit('}')
                            ;
        
        quotedText          = qi::lit('"')
                            > *(qi::lit("\\\\") | qi::lit("\\\"") | qi::alnum | qi::char_(" ,.;:_<>|~!§$%&/()=?{[]}'-"))
                            >  qi::lit('"')
                            ;
                            
        someText            = qi::lit(' ') 
                            | qi::lit('\n') 
                            | qi::lit('\t')
                            | qi::alnum 
                            | qi::char_(",.;:_<>|~!*§$%&/()=?[]'-\\\"") 
                            | inCurlyBrackets
                            ;
                            
        inCurlyBrackets     = qi::lit('{')
                            > *someText
                            >  qi::lit('}')
                            ;
                            
        
        space = *(qi::lit(' ') | qi::lit('\n') | qi::lit('\t'));
        multilineComment = confix("/*", "*/")[*(qi::char_ - "*/")];
        singlelineComment = confix("//", qi::eol)[*(qi::char_ - qi::eol)];
        importLine = confix("import", qi::eol)[*(qi::char_ - qi::eol)];
        property =  confix("property", qi::eol)[*(qi::char_ - qi::eol)];
        uppercaseIdentifier = qi::char_("A-Z") > *qi::char_("_a-zA-Z0-9");
        lowercaseIdentifier = qi::char_("a-z") > *qi::char_("_a-zA-Z0-9");
    }
    
    qi::rule<Iterator, std::string()> multilineComment;
    qi::rule<Iterator, std::string()> singlelineComment;
    qi::rule<Iterator, std::string()> importLine;
    qi::rule<Iterator, std::string()> uppercaseIdentifier;    
    qi::rule<Iterator, std::string()> lowercaseIdentifier;    
    qi::rule<Iterator> rootElements;
    qi::rule<Iterator, std::string()> topElement;
    qi::rule<Iterator> objectElement;
    qi::rule<Iterator> space;
    qi::rule<Iterator, std::string()> objectDeclaration;
    qi::rule<Iterator, std::string()> property;
    qi::rule<Iterator, std::string()> quotedText;
    qi::rule<Iterator, std::string()> inCurlyBrackets;
    qi::rule<Iterator, std::string()> someText;
    qi::rule<Iterator> comment;
    qi::rule<Iterator> comments;
};

// wrap forward iterator with position iterator, to record the position
typedef classic::position_iterator2<boost::spirit::istream_iterator> pos_iterator_type;

bool load(const std::string& filename)
{
    try
    {
        // open file, disable skipping of whitespace
        std::ifstream in(filename.c_str());
        in.unsetf(std::ios::skipws);

        // wrap istream into iterator
        boost::spirit::istream_iterator begin(in);
        boost::spirit::istream_iterator end;

        pos_iterator_type position_begin(begin, end, filename.c_str());
        pos_iterator_type position_end;

        qml_parser<pos_iterator_type> p;                                // create instance of parser
        gObjectStack.push_back(new doxyqml::CRootElement(filename));    // initialize the object stack

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
"doxyqml 2.0";

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
"doxyqml -- A program to convert qml to pseudo C++ for doxygen.";

/* A description of the arguments we accept. */
static char args_doc[] = "qml_file";

static struct argp argp = {options, parse_opt, args_doc, doc};

int main (int argc, char **argv)
{
    /* Where the magic happens */
    argp_parse (&argp, argc, argv, 0, 0, &arguments);
    if (!arguments.filename.empty())
        load(arguments.filename);
    if (!gObjectStack.empty())
        gObjectStack.front()->print();
    return 0;
}
