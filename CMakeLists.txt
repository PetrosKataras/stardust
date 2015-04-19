### =============================================================================================================== 
### Author: Petros Kataras <petroskataras@gmail.com> 
### =============================================================================================================== 

### =============================================================================================================== 
### Minimum required.
### =============================================================================================================== 
cmake_minimum_required( VERSION 2.8 FATAL_ERROR )

### =============================================================================================================== 
### User option for setting the install prefix.
### ===============================================================================================================
set( CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/install" CACHE STRING "Set your installation dest. here" )

### =============================================================================================================== 
### Project stardust.
### =============================================================================================================== 
project( stardust )

### =============================================================================================================== 
### Required for properly exposing the INTERFACE_LINK_LIBARIES target property.
### =============================================================================================================== 
cmake_policy(SET CMP0022 NEW)

### =============================================================================================================== 
### The path to your openFrameworks installation is a prerequisite. 
### =============================================================================================================== 
set( OF_ROOT_DIRECTORY CACHE PATH "Point this path to your openFrameworks root directory" )

if( EXISTS "$ENV{OF_ROOT_DIRECTORY}")
    file(TO_CMAKE_PATH "$ENV{OF_ROOT_DIRECTORY}" OF_ROOT_DIRECTORY)
endif()

if( NOT OF_ROOT_DIRECTORY )
    set(OF_ROOT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/libs/openFrameworks")
endif()

if( NOT EXISTS ${OF_ROOT_DIRECTORY} )
    message(FATAL_ERROR " The OF_ROOT_DIRECTORY path: ${OF_ROOT_DIRECTORY} does not exist! " 
                        " Either export the env variable OF_ROOT_DIRECTORY or use your favorite cmake gui to properly set this variable.."
    )
endif()

### =============================================================================================================== 
### Verbose.
### =============================================================================================================== 
option( CMAKE_VERBOSE_MAKEFILE "Toggle verbose makefile" ON )

### =============================================================================================================== 
### Minimal versioning...
### =============================================================================================================== 
set( Stardust_VERSION_MAJOR 0 ) 
set( Stardust_VERSION_MINOR 1 )
set( Stardust_VERSION_PATCH 0 )

### =============================================================================================================== 
### .cmake files directory for finding various dependencies.
### =============================================================================================================== 
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMake" )

### =============================================================================================================== 
### Locate global dependencies. These files provide some utilies for finding and including dependencies of stardust.
### StardustFindOF tries to find and include openFrameworks and its dependencies and defines OF_LIBRARIES and OF_INCLUDE_DIRS.
### StardustFindEQ tries to locate EQ config cmake files in order to pull EQ and its dependencies ( Lunchbox, Collage etc. )
### Check the individual files for more info on what is happening exactly...
### =============================================================================================================== 
include(StardustFindOF)
include(StardustFindEQ)

### =============================================================================================================== 
### Location of stardust in the build tree.
### =============================================================================================================== 
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib" )

### =============================================================================================================== 
### Stardust include dependencies.
### =============================================================================================================== 
set(STARDUST_DEPENDS_INCLUDES ${EQUALIZER_INCLUDE_DIRS} ${OF_INCLUDE_DIRS})

### =============================================================================================================== 
### Adds stardust as a target.
### =============================================================================================================== 
add_subdirectory( src )

### =============================================================================================================== 
### Create the install config file for finding stardust and its dependencies and copy relevant files to the install dir.
### This will need to be revised at some points but for the current purposes it seems to work.
### You can include the generated file directly from the install directory; 
### Defines STARDUST_FOUND, STARDUST_LIBRARIES, STARDUST_INCLUDE_DIRS .
### =============================================================================================================== 
include(CMakePackageConfigHelpers)
configure_package_config_file( "${CMAKE_CURRENT_SOURCE_DIR}/CMake/StardustConfig.cmake.in"
                               "${CMAKE_CURRENT_BINARY_DIR}/share/StardustConfig.cmake"
	INSTALL_DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}/cmake"
    PATH_VARS
    STARDUST_DEPENDS_INCLUDES
)

install( EXPORT stardustTargets   
         DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}/cmake"
)

install( FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/stardust/application.h"
               "${CMAKE_CURRENT_SOURCE_DIR}/include/stardust/renderer.h"
         DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME}
)

install( FILES "${CMAKE_CURRENT_BINARY_DIR}/share/StardustConfig.cmake"
         DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}/cmake"
)

