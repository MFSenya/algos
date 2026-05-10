#pragma once

#include <cstddef>
#include <vector>
#include <algorithm>

namespace algos {
    template <typename UnaryPredType>
    void partition(std::vector<int> & array, int begin, int end, UnaryPredType pred){
        auto l_group_end = begin - 1;
        auto u_group_begin = begin;
        auto pivot = array[end];
        while (u_group_begin <= end){
            if(pred(array[u_group_begin])) {
                std::swap(array[l_group_end + 1], array[u_group_begin]); 
                ++l_group_end;
                }
            ++u_group_begin;
        }
    }
}
