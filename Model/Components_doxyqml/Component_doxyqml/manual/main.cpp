#include <stdio.h>
#include <argp.h>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/classic_position_iterator.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/spirit/include/qi_action.hpp>

#include "CRootElement.h"

namespace classic = boost::spirit::classic;
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

/* This structure is used by main to communicate with parse_opt. */
struct Arguments
{
    Arguments(): verbose(false) {}
    bool verbose;
};

Arguments arguments;

template <typename Iterator>
struct qml_parser
  : qi::grammar<Iterator>
{
    qml_parser() : qml_parser::base_type(rootElements)
    {
        rootElements = *(qi::char_("a-zA-Z_") > space);
        
        space = *(qi::lit(' ') | qi::lit('\n') | qi::lit('\t'));
    }
    
    qi::rule<Iterator> rootElements;
    qi::rule<Iterator> space;
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

        qml_parser<pos_iterator_type> p;       // create instance of parser

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
  {"verbose", 'v', 0,            0, "verbose info aboout parsing."},
  {0}
};

static error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    Arguments* arguments = (Arguments*) state->input;

    switch (key)
    {
    case 'v':
        arguments->verbose = true;
        break;
    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static char doc[] =
"doxyqml -- A program to convert qml to pseudo C++ for doxygen.";

static struct argp argp = {options, parse_opt, 0, doc};

int main (int argc, char **argv)
{
    /* Where the magic happens */
    argp_parse (&argp, argc, argv, 0, 0, &arguments);


    return 0;
}
