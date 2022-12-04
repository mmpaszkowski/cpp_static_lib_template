## cpp_static_lib_template
[![Build Status](https://app.travis-ci.com/mmpaszkowski/cpp_static_lib_template.svg?branch=master)](https://app.travis-ci.com/mmpaszkowski/cpp_static_lib_template)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/9a6dd51b5c5d4cada9ff157daa136035)](https://www.codacy.com/gh/mmpaszkowski/cpp_static_lib_template/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=mmpaszkowski/cpp_static_lib_template&amp;utm_campaign=Badge_Grade)
[![codecov](https://codecov.io/gh/mmpaszkowski/cpp_static_lib_template/branch/master/graph/badge.svg?token=S2PIG8LUCW)](https://codecov.io/gh/mmpaszkowski/cpp_static_lib_template)

### Project structure
```
.
├── cmake
│   ├── AddGitSubmodule.cmake
│   ├── CodeCoverage.cmake
│   ├── ConfigSafeGuards.cmake
│   ├── Docs.cmake
│   ├── LTO.cmake
│   ├── Tools.cmake
│   └── Warnings.cmake
├── CMakeLists.txt
├── configured
│   ├── CMakeLists.txt
│   └── config.h.in
├── include
│   └── cpp_static_lib_template
│       └── library.h
├── README.md
├── src
│   ├── CMakeLists.txt
│   └── library.cpp
└── tests
    ├── CMakeLists.txt
    └── library.cpp
```