#include <iostream>
#include <iterator>
#include <string>
#include <regex>

#include "gtest/gtest.h"


TEST(RegEx,JsonStrings) {
  std::basic_regex re(R"=(your-ad-here)=",std::regex::extended);    

  std::vector<std::string> pass = {
    R"=("")=",
    R"=("x")=",
    R"=("'")=",
    R"=(" ")=",
    R"=("\"")=",
    R"=("\\")=",
    R"=("\/")=",
    R"=("\b")=",
    R"=("\n")=",
    R"=("\r")=",
    R"=("\t")=",
    R"=("\uAD7F)=",
    R"=("\\x")=",
    R"=("\"'")=",
    R"=(" \/")=",
    R"=("\"\"")=",
    R"=("\b\\")=",
    R"=("\/")=",
    R"=("\uAD7F\b")=",
    R"=("\nx")=",
    R"=("x\r")="
  };

  std::vector<std::string> fail = {
    R"=(")=",
    R"=('x')=",
    R"=(""")=",
    R"=(" )=",
    R"=("""")=",
    R"=("\z")=",
    R"=("\1")="
  };

  for (auto ok : pass) {
     std::match_results<std::string::iterator> results;
     bool ans = std::regex_search(ok.begin(),ok.end(),results,re);
     ASSERT_TRUE(ans);
  }

  for (auto bad : fail) {
    ASSERT_FALSE(std::regex_match(bad.begin(),bad.end(),re)) << " for " << bad;
  }
}
