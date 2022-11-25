# Sources and Headers
set(LIBRARY_SOURCES
    library.cpp
    )

set(LIBRARY_HEADERS
        ../include/cpp_static_lib_template/library.h
    )

set(LIBRARY_INCLUDES
    ../include
    )

add_library(cpp_static_lib_template
        ${LIBRARY_SOURCES}
        ${LIBRARY_HEADERS})

target_include_directories(cpp_static_lib_template PUBLIC
        ${LIBRARY_INCLUDES})