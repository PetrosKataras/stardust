### =============================================================================================================== 
### Include dirs.
### =============================================================================================================== 
include_directories(
                ${PROJECT_SOURCE_DIR}/src
                ${STARDUST_INCLUDE_DIRS}   
)

### =============================================================================================================== 
### Source files.
### =============================================================================================================== 
set( src_files application.cpp 
               renderer.cpp 
               frameData.cpp        
               main.cpp 
)

### =============================================================================================================== 
### Compile the executable.
### =============================================================================================================== 
if( ${CMAKE_SYSTEM_NAME} MATCHES Linux )
    add_executable( simple3DApp ${src_files})
elseif(APPLE)
    add_executable( simple3DApp MACOSX_BUNDLE ${src_files} ${FMOD_LIBRARY})

    set_source_files_properties( ${FMOD_LIBRARY} PROPERTIES MACOSX_PACKAGE_LOCATION "MacOS" )
    add_custom_command( TARGET simple3DApp POST_BUILD COMMAND 
                                ${CMAKE_INSTALL_NAME_TOOL} -change "./libfmodex.dylib" "@executable_path/libfmodex.dylib" 
                                $<TARGET_FILE:simple3DApp>) 
else()

endif()

### =============================================================================================================== 
### Target properties.
### =============================================================================================================== 
set_target_properties( simple3DApp PROPERTIES DEBUG_POSTFIX "_D" )

### =============================================================================================================== 
### Finally link with stardust.
### =============================================================================================================== 
target_link_libraries( simple3DApp stardust )


