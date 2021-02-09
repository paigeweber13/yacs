##############
# VARIABLES #
##############

# IMPORTANT: when you add source files, introduce them here
set(sourcesList "main.cpp" "hello.cpp")

# change these to match your project
project(HelloFullBuildSystem)
set(execName hello)

# if desired, change the source directory
set(sourceDirectory "src/")

###################
# Everything else #
###################

# you probably won't need to change anything in this section
cmake_minimum_required(VERSION 2.8.12)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# this automatically prepends each source in sourcesList with the 
# sourceDirectory
foreach(sourceFull IN LISTS sourcesList)
  string(PREPEND sourceFull ${sourceDirectory})
  list(APPEND sourcesListFull ${sourceFull})
endforeach()

message(STATUS "sources: ${sourcesListFull}")
add_executable(${execName} ${sourcesListFull})
target_link_libraries(${execName} ${CONAN_LIBS})
