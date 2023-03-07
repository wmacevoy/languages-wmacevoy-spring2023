#include <iostream>
#include <iterator>
#include <string>
#include <regex>

#include "gtest/gtest.h"

TEST(RegEx,AOk) {
  std::basic_regex re("a");
  std::string candidate = "a";
  bool ans = std::regex_match(candidate.begin(),candidate.end(),re);

  ASSERT_TRUE(ans);
}

TEST(RegEx,BNotOk) {
  std::basic_regex re("a");
  std::string candidate = "b";
  bool ans = std::regex_match(candidate.begin(),candidate.end(),re);

  ASSERT_FALSE(ans);
}

TEST(RegEx,Apple) {
  std::basic_regex re("a");
  std::string candidate = "apple";
  bool ans = std::regex_match(candidate.begin(),candidate.end(),re);

  ASSERT_FALSE(ans);
}

TEST(RegEx,NyanCatKing) {
  std::basic_regex re(".*cat.*");
  std::string candidate = "nyan cat is king";
  bool ans = std::regex_match(candidate.begin(),candidate.end(),re);

  ASSERT_TRUE(ans);
}


TEST(RegEx,CatsAndDogs) {
  std::basic_regex re("(cat|dog)(|s)");
  std::match_results<std::string::iterator> results;
  std::string candidate = "the cats is dog dogs cat dog";
  bool ans = std::regex_search(candidate.begin(),candidate.end(),results,re);
  ASSERT_TRUE(ans);

  std::string prefix = results.prefix();
  ASSERT_EQ(prefix,"the ");

  for (size_t i = 0; i < results.size(); ++i) 
    std::cout << "match " << i << ": " << results[i] << std::endl;
}

TEST(RegEx,PhoneNum) {
  std::basic_regex re("your ad here");

  std::vector<std::string> pass = {
    "907-255-1234",
    "(907) 255-1234",
    "9072551234" };

  std::vector<std::string> fail = {
    "07-255-1234",
    "(907 255-1234",
    "90725512345"
  };

  for (auto ok : pass) {
    ASSERT_TRUE(std::regex_match(ok.begin(),ok.end(),re));
  }

  for (auto bad : fail) {
    ASSERT_FALSE(std::regex_match(bad.begin(),bad.end(),re));
  }
}


