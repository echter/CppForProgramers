cmake_minimum_required(VERSION 3.8)
project(Oving4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(Oving4 ${SOURCE_FILES})

set(CMAKE_CXX_STANDARD 17)
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES})