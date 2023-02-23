#include "sort_func.h"

std::vector<std::string>  sort_func(const std::vector<std::string> &items) {
  auto ans = items;
  std::sort(ans.begin(),ans.end());
  return ans;
}
