#include "partition.hpp"

#include <algorithm>
#include <vector>

void algos::partition(std::vector<int> & array, int begin, int end){
    auto l_group_end = begin - 1;
    auto u_group_begin = begin;
    auto pivot = array[end];
    while (u_group_begin <= end){
        if(array[u_group_begin] <= pivot) {
             std::swap(array[l_group_end + 1], array[u_group_begin]); 
             ++l_group_end;
            }
        ++u_group_begin;
    }
}