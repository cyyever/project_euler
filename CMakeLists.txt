cmake_minimum_required(VERSION 3.18)

project(ProjectEuler LANGUAGES CXX)

include(cmake/all.cmake)

find_package(Boost REQUIRED)
find_package(Eigen3)
find_package(range-v3 REQUIRED)
find_package(CyyMathLib REQUIRED)

file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
foreach(source ${sources})
  get_filename_component(prog ${source} NAME_WE)
  add_executable(${prog} ${source})
  target_compile_definitions(
    ${prog} PRIVATE "DATA_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}/data\"")
  target_link_libraries(${prog} PRIVATE CyyMathLib)
  target_link_libraries(${prog} PRIVATE range-v3)
endforeach()
