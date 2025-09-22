set(TEST_MAIN ${LIB_PROJECT_NAME}_unit_tests)
set(TEST_SOURCES library.cpp)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1)
FetchContent_MakeAvailable(googletest)

add_executable(${TEST_MAIN} ${TEST_SOURCES})

target_link_libraries(${TEST_MAIN} PUBLIC ${LIB_PROJECT_NAME})
target_link_libraries(${TEST_MAIN} PRIVATE GTest::gtest_main)

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
            "${PROJECT_SOURCE_DIR}/app/*"
            "${PROJECT_SOURCE_DIR}/cmake/*"
            "${PROJECT_SOURCE_DIR}/docs/*"
            "${PROJECT_SOURCE_DIR}/external/*"
            "${PROJECT_SOURCE_DIR}/tests/*"
            "/usr/include/*")

    # Produce HTML report under build/coverage and Cobertura XML at build/coverage/coverage.cobertura.xml
    # Tests are executed via ctest to ensure proper discovery.
    set(GCOVR_ADDITIONAL_ARGS "--xml coverage/coverage.cobertura.xml")
    setup_target_for_coverage_gcovr_html(
            NAME ${COVERAGE_MAIN}
            EXECUTABLE ctest
            EXECUTABLE_ARGS -j 2 --output-on-failure
            DEPENDENCIES ${TEST_MAIN}
    )
endif()
