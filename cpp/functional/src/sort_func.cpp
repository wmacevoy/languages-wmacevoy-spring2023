#include <iostream>
#include "sort_func.h"
#include "utility.h"
#include "merger.h"

template <typename T, typename Ordered = std::less < T > >
std::vector<T>  sort_func(typename std::vector<T>::const_iterator begin, 
                          typename std::vector<T>::const_iterator end) {
  typename std::vector<T>::difference_type size =  end - begin;
  if (size <= 1) {
    return std::vector<T>(begin,end);
  }

  auto a0 = begin;
  auto a1 = a0 + size/2;
  auto b0 = a1;
  auto b1 = end;

  auto a = sort_func<T,Ordered>(a0,a1);
  auto b = sort_func<T,Ordered>(b0,b1);

  merger<typename std::vector<T>::const_iterator,typename std::vector<T>::const_iterator,Ordered> m(a.begin(),a.end(),b.begin(),b.end());
  return std::vector < T > (m.begin(),m.end());
}

std::vector<std::string>  sort_func(const std::vector<std::string> &items) {
  return sort_func<std::string>(items.cbegin(),items.cend());
}