# syntax=docker/dockerfile:1

FROM mcr.microsoft.com/devcontainers/cpp:ubuntu-24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        ninja-build \
        clang-format \
        clang-tidy \
        cppcheck \
        lcov \
        gcovr \
        ccache \
        pkg-config \
    && rm -rf /var/lib/apt/lists/*

# Pre-create ccache directory for the vscode user
RUN mkdir -p /home/vscode/.ccache && chown -R vscode:vscode /home/vscode/.ccache

USER vscode

WORKDIR /workspaces/cpp_static_lib_template

