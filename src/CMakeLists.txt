# SOURCES AND HEADERS
set(LIBRARY_SOURCES
    library.cpp)

set(LIBRARY_HEADERS
    ../include/cpp_static_lib_template/library.h)

set(LIBRARY_INCLUDES
    ../include
    "${CMAKE_BINARY_DIR}/configured_files/include")


add_library(${PROJECT_NAME} STATIC
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

target_include_directories(${PROJECT_NAME} PUBLIC ${LIBRARY_INCLUDES})

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

if (${LIB_ENABLE_WARNINGS})
    target_set_warnings(TARGET ${PROJECT_NAME} ENABLE ON AS_ERROR OFF)
endif ()

add_target_static_analyers(${PROJECT_NAME})
