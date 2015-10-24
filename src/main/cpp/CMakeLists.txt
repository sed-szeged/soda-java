cmake_minimum_required(VERSION 2.8)
project(SoDAJni)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Enable ExternalProject CMake module
include(ExternalProject)
# Set default ExternalProject root directory
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/ThirdParty)

# Add SoDA
include(${SoDAJni_SOURCE_DIR}/cmake/SoDA.cmake)

find_package(JNI)

file(GLOB_RECURSE lib_headers ./*.h)
file(GLOB_RECURSE lib_src ./*.cpp)

include_directories(${JNI_INCLUDE_DIRS})

add_library(SoDAJni SHARED ${lib_headers} ${lib_src} ${})
target_link_libraries(SoDAJni ${SoDA_LIB} ${JNI_LIBRARIES})