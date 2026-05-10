#include <gtest/gtest.h>

namespace custom_gtest_helpers{
    // Generic TestParamInfo name getter
    struct GetName {
        template<typename ParamType>
        std::string operator()(const testing::TestParamInfo<ParamType> & info) const {
            return info.param.name;
        }
    };
}
