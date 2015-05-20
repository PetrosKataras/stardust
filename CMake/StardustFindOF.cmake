set(OF_INCLUDE_DIRS)

set(ARCH_POSTFIX)
if(CMAKE_SIZEOF_VOID_P MATCHES 8)
  set(ARCH_POSTFIX 64)
endif()

set(ENABLE_X11_TARGET TRUE)

if(${CMAKE_SYSTEM_NAME} MATCHES Linux)
  set(OF_LIB_PATH linux${ARCH_POSTFIX})
  find_package(ALSA REQUIRED)
elseif(APPLE)
  set(OF_LIB_PATH osx)
endif()

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
find_package(ZLIB REQUIRED)
find_package(MPG123 REQUIRED)

find_library( OF_LIBRARY
  NAMES openFrameworks
  PATHS ${OF_ROOT_DIRECTORY}/libs/openFrameworksCompiled
  PATH_SUFFIXES lib/${OF_LIB_PATH}
  )

find_library( OF_LIBRARY_D
  NAMES openFrameworksDebug
  PATHS ${OF_ROOT_DIRECTORY}/libs/openFrameworksCompiled
  PATH_SUFFIXES lib/${OF_LIB_PATH}
  )

if( NOT OF_LIBRARY AND NOT OF_LIBRARY_D )
  message( FATAL_ERROR "***______ Neither Release or Debug build of openFrameworks was found _____ !! Did you forgot to compile OF ?")
endif()

list(APPEND OF_LIBRARY_DEPENDS
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
  ${OF_ROOT_DIRECTORY}/libs/openFrameworks
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
  ${OF_ROOT_DIRECTORY}/libs/kiss/include
  ${OF_ROOT_DIRECTORY}/libs/poco/include
  ${OF_ROOT_DIRECTORY}/libs/fmodex/include
  )
