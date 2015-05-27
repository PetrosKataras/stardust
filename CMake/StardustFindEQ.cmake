add_subdirectory(libs/Equalizer)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR}/libs)
find_package(Equalizer CONFIG REQUIRED)
