# SOURCES AND HEADERS
set(LIBRARY_SOURCES
    library.cpp)

set(LIBRARY_HEADERS
    ../include/cpp_static_lib_template/library.h)

set(LIBRARY_INCLUDES
    ../include
    "${CMAKE_BINARY_DIR}/configured_files/include")


add_library(${LIB_PROJECT_NAME} STATIC
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS})

target_link_libraries(${LIB_PROJECT_NAME} PRIVATE fmt::fmt)

target_include_directories(${LIB_PROJECT_NAME} PUBLIC ${LIBRARY_INCLUDES})

# Silence warnings from external headers and CRT nags (esp. on MSVC)
target_compile_definitions(${LIB_PROJECT_NAME} PRIVATE _CRT_SECURE_NO_WARNINGS _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS NOMINMAX WIN32_LEAN_AND_MEAN)

# Treat dependency include dirs as SYSTEM to avoid third-party warnings
if(TARGET fmt)
    get_target_property(FMT_INCLUDES fmt INTERFACE_INCLUDE_DIRECTORIES)
    if(FMT_INCLUDES)
        target_include_directories(${LIB_PROJECT_NAME} SYSTEM PRIVATE ${FMT_INCLUDES})
    endif()
endif()

add_library(${LIB_PROJECT_NAME}::${LIB_PROJECT_NAME} ALIAS ${LIB_PROJECT_NAME})

if (${LIB_ENABLE_WARNINGS})
    target_set_warnings(TARGET ${LIB_PROJECT_NAME} ENABLE ON AS_ERROR OFF)
endif ()

add_target_static_analyers(${LIB_PROJECT_NAME})
