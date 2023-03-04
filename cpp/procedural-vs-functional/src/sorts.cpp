
#include <functional>
#include "sorts.h"

template <typename It>
  bool sorted(It b, It e, std::function<bool (const typename It::value_type &)> pred = std::less <typename It::value_type> ) 
{
  if (e - b <= 1) { return true; }
  auto mid = b + (e - b) / 2;
  return pred(*(mid-1),*mid) && sorted(b, mid, pred) && sorted(mid, e, pred);
}

template <typename It>
  std::vector < typename It::value_type > sort(It b, It e, std::function<bool (const typename It::value_type &)> pred = std::less <typename It::value_type> ) 
{
  if (sorted(b, e, pred)) { return std::vector < typename It::value_type > (b, e); }


  switch(e-b) {
    case 0: case 1: return std::vector < typename It::value_type > ();
    case 1: return true;
    case 2:
    {
      if (pred(*(b+1), *(b))) {
        auto tmp = *b;
        *b = *(b+1);
        *(b+1) = tmp;
        return true;
      } else {
        return false;
      }
    }
    default:
    {
      auto mid = b + (e - b) / 2;
      auto left = sort(b, mid, pred);
      auto right = sort(mid, e, pred);
      return left || right;
    }
   if (*b1 < *b2) {
      result.push_back(*b1);
      b1++;
    } else {
      result.push_back(*b2);
      b2++;
    }
  }
  while (b1 != e1) {
    result.push_back(*b1);
    b1++;
  }
  while (b2 != e2) {
    result.push_back(*b2);
    b2++;
  }
  return result;
}}
template <typename It>
  bool all_pairs(It b, It e, std::function<bool (const typename It::value_type &)> pred = std::less <typename It::value_type> ) {
  if (b == e) { return true; }
  auto i = b;
  auto j = i;
  for (;;) {
    auto j = i;
    ++j;
    if (j == e) { return true; }
    if (!pred(*i, *j)) { return false; }
  }
  return true;
}

template <typename It>
  std::vector<typename It::value_type> merge(It b1, It e1, It b2, It e2) {
  std::vector<typename It::value_type> result;
  while (b1 != e1 && b2 != e2) {
    if (*b1 < *b2) {
      result.push_back(*b1);
      b1++;
    } else {
      result.push_back(*b2);
      b2++;
    }
  }
  while (b1 != e1) {
    result.push_back(*b1);
    b1++;
  }
  while (b2 != e2) {
    result.push_back(*b2);
    b2++;
  }
  return result;
}
std::vector<std::string> merge_sort(std::vector<std::string>::const_iterator b,
                                    std::vector<std::string>::const_iterator e) {
                                      switch(e-b) {
                                        case 0: return std::vector<std::string>();
                                        case 1: return std::vector<std::string>(b, e);
                                        case 2:
                                        {
                                          
                                        }
                                        if (*(b+1) < *(b)) {
                                          return std::vector<std::string>(b, e);
                                        } else {
                                          return std::vector<std::string>(b+1, e+1);
                                        }
                                      }
                                    }
std::vector<std::string> merge_sort(std::vector<std::string>::const_iterator b,
                                    std::vector<std::string>::const_iterator e) {
  auto isSorted = all_pairs(b, e);
  if (isSorted) {
    return std::vector<std::string>(b, e);
  }
  auto mid = b + (e - b) / 2;
  auto left = merge_sort(b, mid);
  auto right = merge_sort(mid, e);
  return merge(left.begin(), left.end(), right.begin(), right.end());
}

std::vector<std::string> sort_func(std::vector<std::string> items) {
  return merge_sort(items.begin(), items.end());
  if (items.size() <= 1)
    return items;
  
   // TODO sort the items using a functional programming style.
   return std::vector < std::string > ();
}

void sort_proc(std::vector<std::string> &items) {
  // TODO sort the items using a procedural programming style.
}
