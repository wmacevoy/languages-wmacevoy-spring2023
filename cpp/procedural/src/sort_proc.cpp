#include "sort_proc.h"

void swap(std::vector<std::string> &items, size_t i, size_t j) {
  if (i != j) {
    std::string tmp = items[i];
    items[i]=items[j];
    items[j]=tmp;
  }
}

void bubble_sort(std::vector<std::string> &items) {
  for (size_t i=1; i<items.size(); ++i) {
    for (size_t j=1; j <= items.size()-i; ++j) {
      if (items[j]<items[j-1]) {
	swap(items,j,j-1);
      }
    }
  }
}

void sort_proc(std::vector<std::string> &items) {
  // TODO sort the items using a procedural programming style in (N log(N)).
  bubble_sort(items);
}
