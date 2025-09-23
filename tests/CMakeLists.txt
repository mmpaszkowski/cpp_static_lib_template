set(TEST_MAIN ${LIB_PROJECT_NAME}_unit_tests)
set(TEST_SOURCES
        library.cpp
)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1)
FetchContent_MakeAvailable(googletest)

add_executable(${TEST_MAIN} ${TEST_SOURCES})

target_link_libraries(${TEST_MAIN} PUBLIC ${LIB_PROJECT_NAME})
target_link_libraries(${TEST_MAIN} PRIVATE GTest::gtest_main)

# Silence common Windows CRT deprecation and min/max macro warnings
target_compile_definitions(${TEST_MAIN} PRIVATE _CRT_SECURE_NO_WARNINGS _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS NOMINMAX WIN32_LEAN_AND_MEAN)

# Mark GTest/GMock headers as SYSTEM on the tests target to reduce noise
if(TARGET GTest::gtest)
    get_target_property(GTEST_INCLUDES GTest::gtest INTERFACE_INCLUDE_DIRECTORIES)
    if(GTEST_INCLUDES)
        target_include_directories(${TEST_MAIN} SYSTEM PRIVATE ${GTEST_INCLUDES})
    endif()
endif()
if(TARGET GTest::gmock)
    get_target_property(GMOCK_INCLUDES GTest::gmock INTERFACE_INCLUDE_DIRECTORIES)
    if(GMOCK_INCLUDES)
        target_include_directories(${TEST_MAIN} SYSTEM PRIVATE ${GMOCK_INCLUDES})
    endif()
endif()

# Register tests with CTest (GoogleTest discovery)
include(GoogleTest)
gtest_discover_tests(${TEST_MAIN})

if (${LIB_ENABLE_WARNINGS})
    target_set_warnings(TARGET ${TEST_MAIN} ENABLE ON AS_ERROR OFF)
endif ()

add_target_static_analyers(${TEST_MAIN})

if (LIB_ENABLE_COVERAGE)
    set(COVERAGE_MAIN "coverage")
    set(COVERAGE_EXCLUDES
            "${PROJECT_SOURCE_DIR}/tests/*" # exclude test sources from coverage
            "${PROJECT_SOURCE_DIR}/app/*"
            "${PROJECT_SOURCE_DIR}/cmake/*"
            "${PROJECT_SOURCE_DIR}/docs/*"
            "${PROJECT_SOURCE_DIR}/external/*"
            "${PROJECT_BINARY_DIR}/_deps/*" # exclude vendored deps (e.g., googletest)
            "${PROJECT_BINARY_DIR}/CMakeFiles/*" # exclude CMake compiler id and build stubs
            "/usr/include/*")

    # Produce HTML report under build/coverage and Cobertura XML at build/coverage/coverage.cobertura.xml
    # Use gcovr's --xml=FILE form to avoid argument splitting issues.
    # Tests are executed via ctest to ensure proper discovery.
    # Use explicit separate args for broader gcovr compatibility (older/newer):
    #   --xml enables Cobertura output, and --output selects the file.

    set(GCOVR_ADDITIONAL_ARGS --xml --output coverage/coverage.cobertura.xml
            --exclude-throw-branches --exclude-unreachable-branches)
    setup_target_for_coverage_gcovr_html(
            NAME ${COVERAGE_MAIN}
            EXECUTABLE ctest
            EXECUTABLE_ARGS -j 2 --output-on-failure
            DEPENDENCIES ${TEST_MAIN}
    )
endif()
