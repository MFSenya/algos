#include <gtest/gtest.h>

#include <vector>
#include <string>

#include <libalgos/partition/partition.hpp>
#include <tests/custom_gtest_helpers.hpp>

template <typename ElementType, template <typename...> class ContainerType>
struct PartitionTestParam {
  ContainerType<ElementType> data;
  ContainerType<ElementType> expected;
  std::string name;
};

template <typename ElementType, template <typename...> class ContainerType>
class PartitionParamTest : public ::testing::TestWithParam<PartitionTestParam<ElementType, ContainerType>> {};

using ActualPartitionParamTestType = PartitionParamTest<int, std::vector>;


TEST_P(ActualPartitionParamTestType, ChecksAlgoCorrectness){
   auto param = GetParam();
   const auto & pivot = param.data.back();
   algos::partition(param.data, 0, param.data.size() - 1, [&pivot](const auto & element){ return element <= pivot; });
   EXPECT_EQ(param.data, param.expected);
}

INSTANTIATE_TEST_SUITE_P(
    PartitionTests,
    ActualPartitionParamTestType,
    ::testing::Values(
        PartitionTestParam(std::vector{1}, std::vector{1}, "one_element"),
        PartitionTestParam(std::vector{1,3}, std::vector{1,3}, "two_elements"),
        PartitionTestParam(std::vector{2,5,3}, std::vector{2,3,5}, "three_elements")
    ),
    custom_gtest_helpers::GetName()
);
