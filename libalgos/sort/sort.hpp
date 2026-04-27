#include <algorithm>

namespace algos::sort {
    template <typename RandomItType, typename CompType>
    void selection_sort(RandomItType begin, RandomItType end, CompType comp){
        for (auto it = begin; it < end - 1; ++it){
            auto selected = std::min_element(it, end, comp);
            std::iter_swap(selected, it);
        }
    }
}