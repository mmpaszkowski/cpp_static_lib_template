set(TEST_MAIN cpp_static_lib_template_unit_tests)

set(TEST_SOURCES
    library.cpp
    )

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1)
FetchContent_MakeAvailable(googletest)

add_executable(${TEST_MAIN} ${TEST_SOURCES})

target_link_libraries(${TEST_MAIN} PUBLIC cpp_static_lib_template GTest::gtest_main)
