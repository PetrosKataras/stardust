### ===============================================================================================================
### Author: Petros Kataras <petroskataras@gmail.com>
### ===============================================================================================================

### ===============================================================================================================
### *Dust
### ===============================================================================================================
add_library( stardust ${PROJECT_SOURCE_DIR}/src/stardust/application.cpp
  ${PROJECT_SOURCE_DIR}/src/stardust/renderer.cpp
  ${PROJECT_SOURCE_DIR}/src/stardust/viewData.cpp
  ${PROJECT_SOURCE_DIR}/src/stardust/internal/renderer.cpp
  ${PROJECT_SOURCE_DIR}/src/stardust/internal/window.cpp)

### ===============================================================================================================
### Include Directories.
### ===============================================================================================================
target_include_directories( stardust PRIVATE ${OF_INCLUDE_DIRS} ${EQUALIZER_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include/stardust ${PROJECT_SOURCE_DIR}/include/stardust/internal)
target_include_directories( stardust PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include> )

### ===============================================================================================================
### Stardust Properties.
### ===============================================================================================================
set_target_properties( stardust PROPERTIES LINKER_LANGUAGE CXX
                                DEBUG_POSTFIX "_D"
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

### ===============================================================================================================
### This allows for the link line of stardust to appear on the link line of other targets linking with stardust
### through the INTERFACE_LINK_LIBRARIES property.
### ===============================================================================================================
target_link_libraries( stardust INTERFACE debug "${OF_LIBRARY_D}" "${OF_LIBRARY_DEPENDS}" "${EQUALIZER_LIBRARIES}"
                                        optimized "${OF_LIBRARY}" "${OF_LIBRARY_DEPENDS}" "${EQUALIZER_LIBRARIES}")


### ===============================================================================================================
### Export install stardust.
### ===============================================================================================================
install( TARGETS stardust
         EXPORT stardustTargets
         ARCHIVE DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}"
         INCLUDES DESTINATION "${CMAKE_INSTALL_PREFIX}/include"
)

### ===============================================================================================================
### Export for usage directly from the build tree.
### ===============================================================================================================
export( TARGETS stardust FILE "${PROJECT_BINARY_DIR}/stardustTargets.cmake" )


### ===============================================================================================================
### The config file for finding and using stardust from the build tree directly without having to install.
### You can include the generated file directly from the build tree;
### Defines STARDUST_FOUND, STARDUST_LIBRARIES, STARDUST_INCLUDE_DIRS .
### ===============================================================================================================
configure_file( "${PROJECT_SOURCE_DIR}/CMake/StardustConfig.buildtree.cmake.in"
                "${PROJECT_BINARY_DIR}/StardustConfig.cmake"
)
