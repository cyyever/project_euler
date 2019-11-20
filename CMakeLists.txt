cmake_minimum_required(VERSION 3.13)

project(ProjectEuler LANGUAGES C CXX)

include(cmake/all.cmake)

find_package(range-v3 REQUIRED)
find_package(MyMathLib REQUIRED)

file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
foreach(source ${sources})
  get_filename_component(prog ${source} NAME_WE)
  add_executable(${prog} ${source})
  target_compile_definitions(${prog} PRIVATE "DATA_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}/data\"")
  target_link_libraries(${prog} PRIVATE MyMathLib)
  target_link_libraries(${prog} PRIVATE range-v3)
endforeach()
