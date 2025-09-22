/**
 * @file library.cpp
 * @brief Implementation of the public API declared in library.h
 */

#include "../include/cpp_static_lib_template/library.h"

#include <fmt/color.h>
#include <cpp_static_lib_template/config.h>

namespace lib
{
    void log_version()
    {
        fmt::print(fg(fmt::color::white), project_name);
        fmt::print(fg(fmt::color::green), " v");
        fmt::print(fg(fmt::color::green), project_version);
        fmt::print(fg(fmt::color::green), "\n");
    }
}
