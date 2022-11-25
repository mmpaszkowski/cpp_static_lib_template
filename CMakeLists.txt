cmake_minimum_required(VERSION 3.16.8)

# PROJECT
# name and version
project(cpp_static_lib_template VERSION 0.0.1 LANGUAGES CXX)

# Global CMake variables
set(CMAKE_CXX_STANDARD              20)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS   ON)

# MAIN_PROJECT CHECK
# determine if cpp_static_lib_template is built as a subproject (using add_subdirectory) or if it is the main project
set(MAIN_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(MAIN_PROJECT ON)
endif()

# OPTIONS
if(${MAIN_PROJECT})
    set(CPP_STATIC_LIB_TEMPLATE_BuildTests_INIT ON)
else()
    set(CPP_STATIC_LIB_TEMPLATE_BuildTests_INIT OFF)
endif()

option(CPP_STATIC_LIB_TEMPLATE_BuildTests "Build the unit tests when BUILD_TESTING is enabled." ${CPP_STATIC_LIB_TEMPLATE_BuildTests_INIT})

#
# CMAKE PLUGINS
# include cmake plugins
#
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
include(CodeCoverage)
append_coverage_compiler_flags()
include(FetchContent)

# SUBDIRECTIORIES
add_subdirectory(src)

# TESTS
# create and configure the unit test target
if (CPP_STATIC_LIB_TEMPLATE_BuildTests)
    add_subdirectory(tests)
endif()

