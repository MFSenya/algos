#include <libalgos/sort/sort.hpp>

#include <vector>
#include <functional>
#include <algorithm>
#include <string>

#include <gtest/gtest.h>

#include <tests/custom_gtest_helpers.hpp>

// Generic sort functional object interface
template<typename ItType, typename CompType>
using SortFuncInterface = std::function<void(ItType, ItType, CompType)>;

// Iterator and Comparator 
using ItType = std::vector<int>::iterator;
auto test_comparator = [](int lhs, int rhs) { return lhs < rhs; };
using CompType = decltype(test_comparator);

// Helper for nice names for tests
struct SortInstance {
    SortFuncInterface<ItType, CompType> func;
    std::string name;
};


class SortTest: public ::testing::TestWithParam<SortInstance> {};

INSTANTIATE_TEST_SUITE_P(
    SortTests,
    SortTest,
    ::testing::Values(
        SortInstance{algos::sort::insertion_sort<ItType, CompType>, "insertion_sort"},
        SortInstance{algos::sort::selection_sort<ItType, CompType>, "selection_sort"},
        SortInstance{algos::sort::merge_sort<ItType, CompType>, "merge_sort"}
    ),
    custom_gtest_helpers::GetName()
);


TEST_P(SortTest, UnsortedCollection){
    std::vector<int> sample = {1, 5, 1, 2};
    auto& instance = GetParam();
    instance.func(sample.begin(), sample.end(), test_comparator);
    EXPECT_TRUE(std::is_sorted(sample.begin(), sample.end(), test_comparator));
}

TEST_P(SortTest, EmptyCollection){
    std::vector<int> sample = {};
    auto& instance = GetParam();
    instance.func(sample.begin(), sample.end(), test_comparator);
    EXPECT_TRUE(std::is_sorted(sample.begin(), sample.end(), test_comparator));
}

TEST_P(SortTest, AlreadySortedCollection){
    std::vector<int> sample = {1, 2, 3, 4};
    auto& instance = GetParam();
    instance.func(sample.begin(), sample.end(), test_comparator);
    EXPECT_TRUE(std::is_sorted(sample.begin(), sample.end(), test_comparator));
}

TEST_P(SortTest, OneElementCollection){
    std::vector<int> sample = {1};
    auto& instance = GetParam();
    instance.func(sample.begin(), sample.end(), test_comparator);
    EXPECT_TRUE(std::is_sorted(sample.begin(), sample.end(), test_comparator));
}

TEST_P(SortTest, ReverseOrderSortedCollection) {
    std::vector<int> sample = {4, 3, 2, 1};
    auto& instance = GetParam();
    instance.func(sample.begin(), sample.end(), test_comparator);
    EXPECT_TRUE(std::is_sorted(sample.begin(), sample.end(), test_comparator));
}



