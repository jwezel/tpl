#include <ostream>
#include <string>
#include <iostream>

#include "boost/spirit/home/qi/nonterminal/rule.hpp"
#include "boost/spirit/home/qi/numeric/int.hpp"
#include "boost/spirit/home/qi/numeric/real.hpp"
#include "boost/spirit/home/qi/parse.hpp"
#include "boost/spirit/home/qi/parser.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/support_multi_pass.hpp>


using icsi = std::istreambuf_iterator<char>;
using rule = boost::spirit::qi::rule<icsi>;

int main(int argc, char const *argv[])
{
  int value = 0;
  rule root{boost::spirit::qi::double_ | boost::spirit::qi::int_};
  auto begin{boost::spirit::make_default_multi_pass(icsi{std::cin})};
  boost::spirit::qi::parse(begin, boost::spirit::make_default_multi_pass(icsi{}), &root, value);
  std::cout << value << std::endl;
  return 0;
}
