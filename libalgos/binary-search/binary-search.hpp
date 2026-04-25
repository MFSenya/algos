#include <iterator>

namespace algos::search {

    /// @brief Binary search in range [begin, end)
    /// @tparam RandomAccessIt iterator type
    /// @param begin range start
    /// @param end range end
    /// @param target element to search
    /// @return iterator on target, if found. Else range end
    template<typename RandomAccessItType>
    auto binary_search(RandomAccessItType begin, RandomAccessItType end, const auto& target){
        while(begin < end){
            auto mid = begin + (end - begin) / 2;
            if(*mid == target) return mid;
            else if (*mid > target) end = mid - 1;
            else begin = mid + 1;
        }
        // Haven't find target. Return end
        return end;
    }
}
