#include "sort_func.h"

// pcode sort first half, sort second half, then return merged version

std::vector<std::string>  merge(const std::vector<std::string> &first, const std::vector<std::string> &second) {
  auto i = first.begin();
  auto j = second.begin();

  std::vector<std::string> ans;

  while (i != first.end() && j != second.end()) {
    if (*j < *i) {
      ans.push_back(*j);
      ++j;
    } else {
      ans.push_back(*i);
      ++i;
    }
  }

  ans.insert(ans.end(),i,first.end());
  ans.insert(ans.end(),j,second.end());

  return ans;

}

std::vector<std::string>  sort_func(std::vector<std::string>::const_iterator begin, std::vector<std::string>::const_iterator end) {
  size_t size =  end - begin;
  if (size <= 1) {
    return std::vector < std::string > (begin,end);
  }

  // int a[10];
  // it b = 0; e = 10;  sort(&a[0],&a[10])
  auto firstBegin = begin;
  auto firstEnd = firstBegin + size/2;
  auto secondBegin = firstEnd;
  auto secondEnd = end;

  auto firstSorted = sort_func(firstBegin,firstEnd);
  auto secondSorted = sort_func(secondBegin,secondEnd);

  return merge(firstSorted,secondSorted);  

}

std::vector<std::string>  sort_func(const std::vector<std::string> &items) {
  return sort_func(items.begin(),items.end());
}