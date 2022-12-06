#include <gtest/gtest.h>
#include <cpp_static_lib_template/library.h>

TEST(cpp_template, mul)
{
    GTEST_ASSERT_EQ(lib::multiply(3.0, 4.0), 12.0);
}

TEST(cpp_template, hello)
{
    lib::hello();
}
