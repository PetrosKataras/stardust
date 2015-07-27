### =============================================================================================================== 
### Author: Petros Kataras <petroskataras@gmail.com> 
### =============================================================================================================== 

### =============================================================================================================== 
### Minimum required.
### =============================================================================================================== 
cmake_minimum_required( VERSION 2.8 FATAL_ERROR )

project( Simple2DApp )

### =============================================================================================================== 
### Quiet.
### =============================================================================================================== 
option( CMAKE_VERBOSE_MAKEFILE "Toggle verbose makefile" ON )

### =============================================================================================================== 
### .cmake files directory for finding various dependencies.
### =============================================================================================================== 
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMake" )

### Uncomment the following include if you want to build the example standalone and not as part of the stardust build.
### You must have either Stardust_DIR ( your stardust build directory ) OR STARDUST_ROOT ( the root dir of your stardust installation ) set if you decide to go down that road.
#include(FindStardust)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )

add_subdirectory( src )
