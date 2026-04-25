#include <libalgos/binary-search/binary-search.hpp>

#include <vector>
#include <iterator>

#include <gtest/gtest.h>

TEST(BinarySearchTest, TestOnNonEmptyVector) {

  std::vector<int> sample = {1, 7, 2, 4};
  auto target_it = std::next(sample.begin(), 2);
  auto search_result = algos::search::binary_search(sample.begin(), sample.end(), *target_it);
  EXPECT_EQ(target_it, search_result);
}

TEST(BinarySearchTest, TestOnEmptyVector) {
  std::vector<int> sample;
  auto search_result = algos::search::binary_search(sample.begin(), sample.end(), 2);
  EXPECT_EQ(sample.end(), search_result);
}

TEST(BinarySearchTest, TestOnPlainArray) {
    double arr [] = {2.0, 3.4, 3.1415, 8.0};
    auto target_it = std::next(std::begin(arr), 2);
    auto search_result = algos::search::binary_search(std::begin(arr), std::end(arr), *target_it);
    EXPECT_EQ(target_it, search_result);
}

TEST(BinarySearchTest, TestOnOneElementRange) {
    double arr [] = {2.0};
    auto target_it = std::begin(arr);
    auto search_result = algos::search::binary_search(std::begin(arr), std::end(arr), *target_it);
    EXPECT_EQ(target_it, search_result);
}