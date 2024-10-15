cmake_minimum_required(VERSION 3.18)

include(FetchContent)
FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG        stable
)




project(go LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
FetchContent_MakeAvailable(pybind11)
#add_subdirectory(pybind11)

add_executable(go main.cpp)
target_link_libraries(go PRIVATE pybind11::embed)

add_custom_command(TARGET go POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy mysum.py ${CMAKE_BINARY_DIR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
