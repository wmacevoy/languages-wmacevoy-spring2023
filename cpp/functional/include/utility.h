#pragma once

#include <ranges>
#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream &out, const std::vector <T> &v) {
  const char *pfx = "[";
  for (typename std::vector<T>::const_iterator i=v.begin(); i != v.end(); ++i) {
    const typename std::vector<T>::value_type &x = *i;
    out << pfx;
    out << x; 
    pfx=",";
  }
  out << "]";
  return out;
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
