#include <algorithm>

namespace algos::sort {
    template <typename RandomItType, typename CompType>
    void selection_sort(RandomItType begin, RandomItType end, CompType comp){
        // Check for an emty collection
        if (begin == end) return;
        for (auto it = begin; it < end - 1; ++it){
            auto selected = std::min_element(it, end, comp);
            std::iter_swap(selected, it);
        }
    }

    template <typename BidirectItType, typename CompType>
    void insertion_sort(BidirectItType begin, BidirectItType end, CompType comp){
        // Check for an emty collection
        if (begin == end) return;
        for (auto outer_it = begin + 1; outer_it < end; ++outer_it){
            auto inner_it = outer_it;
            while(inner_it != begin && comp(*inner_it, *(inner_it - 1))){
                std::iter_swap(inner_it, inner_it - 1);
                --inner_it;
            }
        }
    }
}