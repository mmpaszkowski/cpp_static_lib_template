# SOURCES AND HEADERS
set(LIBRARY_SOURCES
    library.cpp)

set(LIBRARY_HEADERS
    ../include/cpp_static_lib_template/library.h)

set(LIBRARY_INCLUDES
    ../include
    "${CMAKE_BINARY_DIR}/configured_files/include")


add_library(${PROJECT_NAME}_lib STATIC
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS})

target_link_libraries(${PROJECT_NAME}_lib PRIVATE cpp_static_lib_template::cpp_static_lib_template)

target_include_directories(${PROJECT_NAME}_lib PUBLIC ${LIBRARY_INCLUDES})

if (${ENABLE_WARNINGS})
    target_set_warnings(TARGET ${PROJECT_NAME}_lib ENABLE ON AS_ERROR OFF)
endif ()

add_target_static_analyers(${PROJECT_NAME}_lib)
