#include <gtest/gtest.h>

#include <vector>
#include <string>

#include <libalgos/partition/partition.hpp>

template <typename ElementType, template <typename...> class ContainerType>
struct PartitionTestParam {
  ContainerType<ElementType> data;
  ContainerType<ElementType> expected;
  std::string name;
};

template <typename ElementType, template <typename...> class ContainerType>
class PartitionParamTest : public ::testing::TestWithParam<PartitionTestParam<ElementType, ContainerType>> {};

using ActualPartitionParamTestType = PartitionParamTest<int, std::vector>;

// Name getter
struct GetName {
    template<typename ParamType>
    std::string operator()(const testing::TestParamInfo<ParamType> & info) const {
        return info.param.name;
    }
};


TEST_P(ActualPartitionParamTestType, ChecksAlgoCorrectness){
   auto param = GetParam();
   algos::partition(param.data, 0, param.data.size() - 1);
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
    GetName()
);
