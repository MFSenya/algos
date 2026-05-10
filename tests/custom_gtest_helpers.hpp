#include <gtest/gtest.h>

namespace custom_gtest_helpers{
    // Generic TestParamInfo name getter
    struct GetName {
        template<typename ParamType>
        std::string operator()(const testing::TestParamInfo<ParamType> & info) const {
            return info.param.name;
        }
    };

    template <typename Container>
    void PrintContainer(const Container& c, const std::string& label = "Container") {
        std::cout << "[  DEBUG   ] " << label << ": [ ";
        for (auto it = std::begin(c); it != std::end(c); ++it) {
            std::cout << *it << (std::next(it) != std::end(c) ? ", " : "");
        }
        std::cout << " ]" << std::endl;
    }
}
