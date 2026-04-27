#include <libalgos/sort/sort.hpp>

#include <gtest/gtest.h>


TEST(SelectionSortTest, NormalCollection){
    std::vector<int> sample = {1, 5, 1, 2};
    algos::sort::selection_sort(sample.begin(), sample.end(), [](auto lhs, auto rhs) { return lhs < rhs;});
    EXPECT_EQ(std::vector<int>({1, 1, 2, 5}), sample);
}