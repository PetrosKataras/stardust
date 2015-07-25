set(OF_INCLUDE_DIRS)
set(OF_LIBRARY_DEPENDS)
set(OF_LIB_PATH)
set(OF_LIB_PATH_SUFFIXES)

set(ARCH_POSTFIX)
if(CMAKE_SIZEOF_VOID_P MATCHES 8)
    set(ARCH_POSTFIX 64)
endif()

list(APPEND OF_INCLUDE_DIRS  ${OF_ROOT_DIRECTORY}/libs/openFrameworks
                             ${OF_ROOT_DIRECTORY}/libs/openFrameworks/app
                             ${OF_ROOT_DIRECTORY}/libs/openFrameworks/communication
                             ${OF_ROOT_DIRECTORY}/libs/openFrameworks/events
                             ${OF_ROOT_DIRECTORY}/libs/openFrameworks/gl
                             ${OF_ROOT_DIRECTORY}/libs/openFrameworks/graphics
                             ${OF_ROOT_DIRECTORY}/libs/openFrameworks/math
                             ${OF_ROOT_DIRECTORY}/libs/openFrameworks/3d
                             ${OF_ROOT_DIRECTORY}/libs/openFrameworks/sound
                             ${OF_ROOT_DIRECTORY}/libs/openFrameworks/types
                             ${OF_ROOT_DIRECTORY}/libs/openFrameworks/utils
                             ${OF_ROOT_DIRECTORY}/libs/openFrameworks/video
                             ${OF_ROOT_DIRECTORY}/libs/glfw/include
                             ${OF_ROOT_DIRECTORY}/libs/tess2/include
                             ${OF_ROOT_DIRECTORY}/libs/poco/include
                             ${OF_ROOT_DIRECTORY}/libs/utf8cpp/include
                             )

if( ${CMAKE_SYSTEM_NAME} MATCHES Linux )

    list(APPEND OF_INCLUDE_DIRS  ${OF_ROOT_DIRECTORY}/libs/kiss/include)

    set(OF_LIB_PATH linux${ARCH_POSTFIX})
    list(APPEND OF_LIB_PATH_SUFFIXES  lib/linux${ARCH_POSTFIX})

    set(ENABLE_X11_TARGET TRUE)

    find_package(X11 REQUIRED)
    find_package(Glib REQUIRED)
    find_package(GTK3 REQUIRED)
    find_package(OpenGL REQUIRED)
    find_package(OpenAL REQUIRED)
    find_package(Cairo REQUIRED)
    find_package(FreeImage REQUIRED)
    find_package(OpenSSL REQUIRED)
    find_package(GStreamer COMPONENTS gstreamer-app gstreamer-video REQUIRED)
    find_package(Freetype REQUIRED)
    find_package(Fontconfig REQUIRED)
    find_package(Threads REQUIRED)
    find_package(Sndfile REQUIRED)
    find_package(ALSA REQUIRED)
    find_package(ZLIB REQUIRED)
    find_package(MPG123 REQUIRED)

    list(APPEND OF_LIBRARY_DEPENDS    
                                ${OF_ROOT_DIRECTORY}/libs/glfw/lib/${OF_LIB_PATH}/libglfw3.a
                                ${OF_ROOT_DIRECTORY}/libs/kiss/lib/${OF_LIB_PATH}/libkiss.a
                                ${OF_ROOT_DIRECTORY}/libs/tess2/lib/${OF_LIB_PATH}/libtess2.a
                                ${OF_ROOT_DIRECTORY}/libs/poco/lib/${OF_LIB_PATH}/libPocoNet.a
                                ${OF_ROOT_DIRECTORY}/libs/poco/lib/${OF_LIB_PATH}/libPocoNetSSL.a
                                ${OF_ROOT_DIRECTORY}/libs/poco/lib/${OF_LIB_PATH}/libPocoCrypto.a
                                ${OF_ROOT_DIRECTORY}/libs/poco/lib/${OF_LIB_PATH}/libPocoUtil.a
                                ${OF_ROOT_DIRECTORY}/libs/poco/lib/${OF_LIB_PATH}/libPocoXML.a
                                ${OF_ROOT_DIRECTORY}/libs/poco/lib/${OF_LIB_PATH}/libPocoJSON.a
                                ${OF_ROOT_DIRECTORY}/libs/poco/lib/${OF_LIB_PATH}/libPocoFoundation.a
                                ${X11_LIBRARIES} 
                                ${X11_Xcursor_LIB} 
                                ${X11_Xxf86vm_LIB} 
                                ${X11_Xrandr_LIB} 
                                ${X11_Xi_LIB}
                                ${GLIB_LIBRARIES}
                                ${GTK3_LIBRARIES}
                                ${OPENGL_LIBRARIES}
                                ${OPENAL_LIBRARY}
                                ${CAIRO_LIBRARIES}
                                ${FREEIMAGE_LIBRARIES}
                                ${OPENSSL_LIBRARIES}
                                ${GSTREAMER_LIBRARIES}
                                ${GSTREAMER_BASE_LIBRARIES}
                                ${GSTREAMER_APP_LIBRARIES}
                                ${GSTREAMER_VIDEO_LIBRARIES}
                                ${FREETYPE_LIBRARIES}
                                ${FONTCONFIG_LIBRARIES}
                                ${CMAKE_THREAD_LIBS_INIT}
                                ${SNDFILE_LIBRARIES}
                                ${ALSA_LIBRARIES}
                                ${ZLIB_LIBRARIES}
                                ${MPG123_LIBRARY}
                                )

    list(APPEND OF_INCLUDE_DIRS ${X11_INCLUDE_DIR} 
                                ${X11_Xcursor_INCLUDE_PATH} 
                                ${X11_Xxf86vm_INCLUDE_PATH} 
                                ${X11_xi_INCLUDE_PATH}
                                ${GLIB_INCLUDE_DIRS}
                                ${GTK3_INCLUDE_DIRS}
                                ${OPENGL_INCLUDE_DIR}
                                ${OPENAL_INCLUDE_DIR}
                                ${CAIRO_INCLUDE_DIR}
                                ${FREEIMAGE_INCLUDE_DIRS}
                                ${OPENSSL_INCLUDE_DIR}
                                ${GSTREAMER_INCLUDE_DIRS}
                                ${GSTREAMER_BASE_INCLUDE_DIRS}
                                ${GSTREAMER_APP_INCLUDE_DIRS}
                                ${GSTREAMER_VIDEO_INCLUDE_DIRS}
                                ${FREETYPE_INCLUDE_DIRS}
                                ${FONTCONFIG_INCLUDE_DIR}
                                ${SNDFILE_INCLUDE_DIR}
                                ${ALSA_INCLUDE_DIRS}
                                ${ZLIB_INCLUDE_DIRS}
                                ${MPG123_INCLUDE_DIRS}
                                )
elseif(APPLE)
    set(OF_LIB_PATH osx)
    list(APPEND OF_LIB_PATH_SUFFIXES  lib/osx)

    set(ENABLE_X11_TARGET TRUE)
    find_package(X11 REQUIRED)

    list(APPEND OF_INCLUDE_DIRS  ${OF_ROOT_DIRECTORY}/libs/freetype/include
                                 ${OF_ROOT_DIRECTORY}/libs/freetype/include/freetype2
                                 ${OF_ROOT_DIRECTORY}/libs/fmodex/include
                                 ${OF_ROOT_DIRECTORY}/libs/Freeimage/include
                                 ${OF_ROOT_DIRECTORY}/libs/cairo/include/cairo
                                 ${OF_ROOT_DIRECTORY}/libs/rtAudio/include
                                 ${OF_ROOT_DIRECTORY}/libs/openssl/include
                                 ${X11_INCLUDE_DIR} 
                                 ${X11_Xcursor_INCLUDE_PATH} 
                                 ${X11_Xxf86vm_INCLUDE_PATH} 
                                 ${X11_xi_INCLUDE_PATH}
                                 )





    find_library(ACCELERATE_LIBRARY Accelerate REQUIRED)
    find_library(AGL_LIBRARY AGL REQUIRED)
    find_library(APPKIT_LIBRARY AppKit REQUIRED)
    find_library(APPLICATION_SERVICES_LIBRARY ApplicationServices REQUIRED)
    find_library(AUDIO_TOOLBOX_LIBRARY AudioToolBox REQUIRED)
    find_library(AVFOUNDATION_LIBRARY AVFoundation REQUIRED)
    find_library(COCOA_LIBRARY Cocoa REQUIRED)
    find_library(CORE_AUDIO_LIBRARY CoreAudio REQUIRED)
    find_library(CORE_FOUNDATION_LIBRARY CoreFoundation REQUIRED)
    find_library(CORE_MEDIA_LIBRARY CoreMedia REQUIRED)
    find_library(CORE_SERVICES_LIBRARY CoreServices REQUIRED)
    find_library(CORE_VIDEO_LIBRARY CoreVideo REQUIRED)
    find_library(IO_KIT_LIBRARY IOKit REQUIRED)
    find_library(OGL_LIBRARY OpenGL REQUIRED)
    find_library(QUARTZ_CORE_LIBRARY QuartzCore REQUIRED)
    find_library(QUICKTIME_LIBRARY QuickTime REQUIRED)
    find_library(QTKIT_LIBRARY QTKit REQUIRED)
    find_library(GLUT_LIBRARY GLUT REQUIRED)

    list(APPEND OF_LIBRARY_DEPENDS    
                                ${OF_ROOT_DIRECTORY}/libs/poco/lib/${OF_LIB_PATH}/PocoNet.a
                                ${OF_ROOT_DIRECTORY}/libs/poco/lib/${OF_LIB_PATH}/PocoNetSSL.a
                                ${OF_ROOT_DIRECTORY}/libs/poco/lib/${OF_LIB_PATH}/PocoCrypto.a
                                ${OF_ROOT_DIRECTORY}/libs/poco/lib/${OF_LIB_PATH}/PocoUtil.a
                                ${OF_ROOT_DIRECTORY}/libs/poco/lib/${OF_LIB_PATH}/PocoXML.a
                                ${OF_ROOT_DIRECTORY}/libs/poco/lib/${OF_LIB_PATH}/PocoJSON.a
                                ${OF_ROOT_DIRECTORY}/libs/poco/lib/${OF_LIB_PATH}/PocoFoundation.a
                                ${OF_ROOT_DIRECTORY}/libs/fmodex/lib/${OF_LIB_PATH}/libfmodex.dylib
                                ${OF_ROOT_DIRECTORY}/libs/glfw/lib/${OF_LIB_PATH}/glfw3.a
                                ${OF_ROOT_DIRECTORY}/libs/freeimage/lib/${OF_LIB_PATH}/freeimage.a
                                ${OF_ROOT_DIRECTORY}/libs/freetype/lib/${OF_LIB_PATH}/freetype.a
                                ${OF_ROOT_DIRECTORY}/libs/rtAudio/lib/${OF_LIB_PATH}/rtAudio.a
                                ${OF_ROOT_DIRECTORY}/libs/tess2/lib/${OF_LIB_PATH}/tess2.a
                                ${OF_ROOT_DIRECTORY}/libs/cairo/lib/${OF_LIB_PATH}/cairo-script-interpreter.a
                                ${OF_ROOT_DIRECTORY}/libs/cairo/lib/${OF_LIB_PATH}/cairo.a
                                ${OF_ROOT_DIRECTORY}/libs/cairo/lib/${OF_LIB_PATH}/pixman-1.a
                                ${OF_ROOT_DIRECTORY}/libs/openssl/lib/${OF_LIB_PATH}/crypto.a
                                ${OF_ROOT_DIRECTORY}/libs/openssl/lib/${OF_LIB_PATH}/ssl.a
                                ${OF_ROOT_DIRECTORY}/libs/glut/lib/${OF_LIB_PATH}/GLUT.framework/Versions/A/GLUT
                                ${OF_ROOT_DIRECTORY}/libs/tess2/lib/${OF_LIB_PATH}/tess2.a
                                ${ACCELERATE_LIBRARY}
                                ${AGL_LIBRARY}
                                ${APPKIT_LIBRARY}
                                ${APPLICATION_SERVICES_LIBRARY}
                                ${AUDIO_TOOLBOX_LIBRARY}
                                ${AVFOUNDATION_LIBRARY}
                                ${COCOA_LIBRARY}
                                ${CORE_AUDIO_LIBRARY}
                                ${CORE_FOUNDATION_LIBRARY}
                                ${CORE_MEDIA_LIBRARY}
                                ${CORE_SERVICES_LIBRARY}
                                ${CORE_VIDEO_LIBRARY}
                                ${IO_KIT_LIBRARY}
                                ${OGL_LIBRARY}
                                ${QUARTZ_CORE_LIBRARY}
                                ${QUICKTIME_LIBRARY}
                                ${QTKIT_LIBRARY}
                                ${GLUT_LIBRARY}
                                ${X11_LIBRARIES} 
                                ${X11_Xcursor_LIB} 
                                ${X11_Xxf86vm_LIB} 
                                ${X11_Xrandr_LIB} 
                                ${X11_Xi_LIB}
                                )
else()
    message(FATAL_ERROR " Stardust is *not* implemented for : ${CMAKE_SYSTEM_NAME}") 
endif()

message(STATUS " PATH SUFF " ${OF_LIB_PATH_SUFFIXES} )
find_library( OF_LIBRARY
              NAMES openFrameworks
              PATHS ${OF_ROOT_DIRECTORY}/libs/openFrameworksCompiled
              PATH_SUFFIXES ${OF_LIB_PATH_SUFFIXES}
            )

find_library( OF_LIBRARY_D
              NAMES openFrameworksDebug
              PATHS ${OF_ROOT_DIRECTORY}/libs/openFrameworksCompiled
              PATH_SUFFIXES ${OF_LIB_PATH_SUFFIXES}
            )

if( NOT OF_LIBRARY AND NOT OF_LIBRARY_D )
    message( FATAL_ERROR "***______ Neither Release or Debug build of openFrameworks was found _____ !! Did you forgot to compile OF ?") 
endif()
