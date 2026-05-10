#include <gtest/gtest.h>

#include <vector>
#include <string>
#include <iterator>

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


template <typename ElementType, template <typename...> class ContainerType>
void generic_test_logic(PartitionTestParam<ElementType, ContainerType> param, bool enable_debug = false){
   const auto & pivot = param.pivot;
   auto & data = param.data;
   auto sep_point = algos::partition(std::begin(data), std::end(data), [&pivot](const auto & element){ return element <= pivot; });
   // Separation point should be equal to pivot
   EXPECT_EQ(*sep_point, pivot);
   // All elements before separation point <= pivot
   EXPECT_TRUE(std::all_of(std::begin(data), sep_point, [&pivot](const auto & element){ return element <= pivot; }));
   // All elements after separation point > pivot
   EXPECT_TRUE(std::all_of(sep_point + 1, std::end(data), [&pivot](const auto & element){ return element > pivot; }));
   if (enable_debug) custom_gtest_helpers::PrintContainer(data, "After Partition (" + param.name + ")");
}

using PartitionParamTestVectorInt = PartitionParamTest<int, std::vector>;
TEST_P(PartitionParamTestVectorInt, ChecksAlgoCorrectness){
   generic_test_logic(GetParam());
}

INSTANTIATE_TEST_SUITE_P(
    PartitionTests,
    PartitionParamTestVectorInt,
    ::testing::Values(
        PartitionTestParam(std::vector{1}, 1, "one_element"),
        PartitionTestParam(std::vector{1,3}, 3, "two_elements"),
        PartitionTestParam(std::vector{2,5,3}, 3, "three_elements"),
        PartitionTestParam(std::vector{1,5,6,1,7,5,6}, 6, "many_elements")
    ),
    custom_gtest_helpers::GetName()
);

using PartitionParamTestVectorString = PartitionParamTest<std::string, std::vector>;
TEST_P(PartitionParamTestVectorString, ChecksAlgoCorrectness){
   generic_test_logic(GetParam());
}

INSTANTIATE_TEST_SUITE_P(
    PartitionTests,
    PartitionParamTestVectorString,
    ::testing::Values(
        PartitionTestParam(std::vector<std::string>{
          "Шефнер В. Сестра печали",
          "Шолохов М. Поднятая целина",
          "Васильев Б. А зори здесь тихие",
          "Островский Н. Как закалялась сталь",
          "Аламович А. Блокадная книга",
          "Шукшин В. Калина красная",
          "Казакевич Э. Звезда"
        },
        std::string("Казакевич Э. Звезда"),
        "book_example")
    ),
    custom_gtest_helpers::GetName()
);
