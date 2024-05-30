# ${PROJECT_ROOT}/Plain/Grain/CMakeLists.txt

cmake_minimum_required(VERSION 3.12)

project(Grain CXX)

add_library(grain INTERFACE)

target_include_directories(grain PUBLIC INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
