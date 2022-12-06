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

add_library(${LIB_PROJECT_NAME}::${LIB_PROJECT_NAME} ALIAS ${LIB_PROJECT_NAME})

if (${LIB_ENABLE_WARNINGS})
    target_set_warnings(TARGET ${LIB_PROJECT_NAME} ENABLE ON AS_ERROR OFF)
endif ()

add_target_static_analyers(${LIB_PROJECT_NAME})
