cmake_minimum_required(VERSION 3.27)
project(game-of-life LANGUAGES CXX)

set(SOURCES 
  src/main.cpp
  src/grid.cpp
  src/cell.cpp
  src/life.cpp
)

add_executable(game-of-life ${SOURCES})
target_include_directories(game-of-life PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_compile_features(game-of-life PRIVATE cxx_std_20)
