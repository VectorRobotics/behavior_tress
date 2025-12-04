cmake_minimum_required(VERSION 3.10)
project(humanoid_bt LANGUAGES CXX)

# Single standalone executable from test_bt.cpp
set(TEST_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/test_bt.cpp)
add_executable(test_bt ${TEST_SRCS})

# Modern C++
target_compile_features(test_bt PRIVATE cxx_std_17)
target_compile_options(test_bt PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -Wpedantic>
)

# Make parent dir available for headers (adjust if your headers live elsewhere)
target_include_directories(test_bt PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# Link libraries if needed — uncomment/adjust to your project
# find_package(Threads REQUIRED)
# target_link_libraries(test_bt PRIVATE Threads::Threads)
# find_package(GTest REQUIRED)     # only if this binary actually depends on GTest
# target_link_libraries(test_bt PRIVATE GTest::gtest)

# Optional: install or export if you want to package this target
# install(TARGETS test_bt RUNTIME DESTINATION bin)
