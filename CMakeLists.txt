# ${PROJECT_ROOT}/Plain/Grain/CMakeLists.txt

cmake_minimum_required(VERSION 3.12)

project(Grain CXX)

add_library(Grain INTERFACE)
target_include_directories(Grain INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}
)
