cmake_minimum_required(VERSION 3.14)

project(simple_model)

if (MSVC)
  # warning level 4
  add_compile_options(/W4)
else()
  # additional warnings
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Add sanitizer flags for C++ compiler for "Debug" configuration
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,undefined")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories( ${CMAKE_SOURCE_DIR}/inc)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)

