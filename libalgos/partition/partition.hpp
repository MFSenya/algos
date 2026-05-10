#pragma once

#include <cstddef>
#include <vector>
#include <algorithm>

namespace algos {

    /// @brief Simple partition implementation in range [begin, end), using unary predicate.
    /// @brief All elements that satisfy predicate go first.
    /// @tparam ForwrdItType iterator type
    /// @tparam UnaryPredType unary predicate type
    /// @param begin partiton range begin
    /// @param end partiton range end
    /// @param pred unary predicate
    /// @return iterator on a separation point (last element that satisfy predicate)
    template <typename ForwrdItType, typename UnaryPredType>
    ForwrdItType partition(ForwrdItType begin, ForwrdItType end, UnaryPredType pred){
        // During partition algorithm separate elements into groups
        // L - elements that satisfy predicate
        // R - elements that don't satisfy the predicate
        // U - yet unchecked elements

        // L group start from begin - 1
        auto l_group_end = begin - 1;
        auto u_group_begin = begin;
        while (u_group_begin < end){
            if(pred(*u_group_begin)) {
                // If element satisfy, it goes to the end of left group
                std::iter_swap(l_group_end + 1, u_group_begin); 
                ++l_group_end;
                }
            // If element doesn't satisfy it goes to the end of R group implicitly
            // Move to next element
            ++u_group_begin;
        }
        // Separation point
        return l_group_end;
    }
}
