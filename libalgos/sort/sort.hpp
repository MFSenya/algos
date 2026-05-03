#include <algorithm>
#include <iterator>
#include <vector>

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

    template <typename RandomItType, typename CompType>
    void merge_sort(RandomItType begin, RandomItType end, CompType comp) {

        auto merge = [comp](auto begin, auto mid, auto end){
            using ValueType = typename std::iterator_traits<RandomItType>::value_type;
            std::vector<ValueType> temp;
            temp.reserve(end - begin);
            // current elements in left/right halfs
            auto lh_cur = begin;
            auto rh_cur = mid;
            while (lh_cur != mid && rh_cur != end){
                if(comp(*lh_cur, *rh_cur)) {
                    temp.push_back(*lh_cur);
                    ++lh_cur;
                }
                else{
                    temp.push_back(*rh_cur);
                    ++rh_cur;
                }

            }
            if (lh_cur == mid) temp.insert(temp.end(), rh_cur, end);
            else temp.insert(temp.end(), lh_cur, mid);
            std::transform(temp.begin(), temp.end(), begin, [](const auto & val) {
                return val; 
            });
        };

        // If range [begin; end) contains one or zero element, than it's sorted
        if (end - begin < 2) return;
        auto mid = begin + (end - begin) / 2;
        merge_sort(begin, mid, comp);
        merge_sort(mid, end, comp);
        merge(begin, mid, end);
    }
}