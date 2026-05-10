#include <gtest/gtest.h>

#include <vector>
#include <string>

#include <libalgos/partition/partition.hpp>
#include <tests/custom_gtest_helpers.hpp>

template <typename ElementType, template <typename...> class ContainerType>
struct PartitionTestParam {
  ContainerType<ElementType> data;
  ElementType pivot;
  std::string name;
};

template <typename ElementType, template <typename...> class ContainerType>
class PartitionParamTest : public ::testing::TestWithParam<PartitionTestParam<ElementType, ContainerType>> {};

using ActualPartitionParamTestType = PartitionParamTest<int, std::vector>;


TEST_P(ActualPartitionParamTestType, ChecksAlgoCorrectness){
   auto param = GetParam();
   const auto & pivot = param.pivot;
   auto & data = param.data;
   auto sep_point = algos::partition(std::begin(data), std::end(data), [&pivot](const auto & element){ return element <= pivot; });
   // Separation point should be equal to pivot
   EXPECT_EQ(*sep_point, pivot);
   // All elements before separation point <= pivot
   EXPECT_TRUE(std::all_of(std::begin(data), sep_point, [&pivot](const auto & element){ return element <= pivot; }));
   // All elements after separation point > pivot
   EXPECT_TRUE(std::all_of(sep_point + 1, std::end(data), [&pivot](const auto & element){ return element > pivot; }));
}

INSTANTIATE_TEST_SUITE_P(
    PartitionTests,
    ActualPartitionParamTestType,
    ::testing::Values(
        PartitionTestParam(std::vector{1}, 1, "one_element"),
        PartitionTestParam(std::vector{1,3}, 3, "two_elements"),
        PartitionTestParam(std::vector{2,5,3}, 3, "three_elements"),
        PartitionTestParam(std::vector{1,5,6,1,2,5,6}, 6, "many_elements")
    ),
    custom_gtest_helpers::GetName()
);
