add_library(custom_gtest_helpers INTERFACE)

target_include_directories(custom_gtest_helpers INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)