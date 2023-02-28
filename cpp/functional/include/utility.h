#pragma once

#include <ranges>
#include <iostream>
#include <vector>

template<typename T>
concept ConstIterable = requires(T a)
{
    { std::cbegin<T>(a) } -> std::convertible_to<typename T::const_iterator>;
    { std::cend<T>(a) } -> std::convertible_to<typename T::const_iterator>;
    not std::convertible_to<T,std::basic_string<typename T::value_type>>;
};

template <ConstIterable CI>
std::ostream& operator<<(std::ostream &out, const CI &ci) {
  const char *pfx = "[";
  for (const auto &x : ci) {
    out << pfx << x; 
    pfx=",";
  }
  return out << "]";
}

// number of arrangements of length m from items (duplication ok)
template <typename T>
int arrangements(const std::vector<T> &items, int len) {
    return (int) pow(items.size(),len);
}

// i'th arrangment
template <typename T>
std::vector < T > arrangement(const std::vector< T > &items, int len, int i) {
  std::vector < std::string > ans(len,"");
  for (int k=0; k<len; ++k) {
    ans[k] = items[i % items.size()];
    i = i / items.size();
  }
  return ans;
}

#define STRING(x) ([&]() { std::ostringstream oss; oss << x; return oss.str(); })()
