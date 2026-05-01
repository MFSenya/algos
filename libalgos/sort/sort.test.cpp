#include <libalgos/sort/sort.hpp>

#include <gtest/gtest.h>


TEST(SelectionSortTest, NormalCollection){
    std::vector<int> sample = {1, 5, 1, 2};
    algos::sort::selection_sort(sample.begin(), sample.end(), [](auto lhs, auto rhs) { return lhs < rhs;});
    EXPECT_EQ(std::vector<int>({1, 1, 2, 5}), sample);
}

TEST(SelectionSortTest, EmptyCollection){
    std::vector<int> sample = {};
    algos::sort::selection_sort(sample.begin(), sample.end(), [](auto lhs, auto rhs) { return lhs < rhs;});
    EXPECT_EQ(std::vector<int>({}), sample);
}

TEST(SelectionSortTest, AlreadySortedCollection){
    std::vector<int> sample = {1, 2, 3, 4};
    algos::sort::selection_sort(sample.begin(), sample.end(), [](auto lhs, auto rhs) { return lhs < rhs;});
    EXPECT_EQ(std::vector<int>({1, 2, 3, 4}), sample);
}

TEST(SelectionSortTest, OneElementCollection){
    std::vector<int> sample = {1};
    algos::sort::selection_sort(sample.begin(), sample.end(), [](auto lhs, auto rhs) { return lhs < rhs;});
    EXPECT_EQ(std::vector<int>({1}), sample);
}

TEST(SelectionSortTest, ReverseOrderSortedCollection) {
    std::vector<int> sample = {4, 3, 2, 1};
    algos::sort::selection_sort(sample.begin(), sample.end(), [](auto lhs, auto rhs) { return lhs < rhs;});
    EXPECT_EQ(std::vector<int>({1, 2, 3, 4}), sample);
}