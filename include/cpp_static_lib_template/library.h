#ifndef CPP_STATIC_LIB_TEMPLATE_LIBRARY_H
#define CPP_STATIC_LIB_TEMPLATE_LIBRARY_H

/**
 * @file library.h
 * @brief Public API for the cpp_static_lib_template library.
 */

namespace lib
{
    /**
     * @brief Log the project name and version to stdout.
     *
     * Writes a single line like: "<project_name> v<project_version>".
     */
    void log_version();
}

#endif //CPP_STATIC_LIB_TEMPLATE_LIBRARY_H
