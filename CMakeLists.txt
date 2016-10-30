cmake_minimum_required(VERSION 3.2)
set(PROJECT_NAME "ToneGenerator")
project(${PROJECT_NAME})


# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif()


# enable C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Define sources and executable
include_directories("src/*")
set(EXECUTABLE_NAME "${PROJECT_NAME}")
set(SOURCE_FILES src/main.cpp
                 src/Sinusoid.hpp
                 src/Triangle.hpp
                 src/Sawtooth.hpp
                 )

# when we are on MacOS create a bundle and
# put the rescources in it
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

  file(GLOB_RECURSE RESOURCE_FILES "data/*")

  add_executable(${EXECUTABLE_NAME} MACOSX_BUNDLE ${SOURCE_FILES} ${RESOURCE_FILES})

  set_source_files_properties(${RESOURCE_FILES}
    PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
else()
  # on windows there are no bundles
  add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
endif()


# Add our CMake scripts
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})


# Detect and add any version 2.X of SFML
# See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 COMPONENTS system window graphics network audio REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
