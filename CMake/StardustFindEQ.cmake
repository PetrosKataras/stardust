find_package(Servus CONFIG REQUIRED PATHS ${PROJECT_SOURCE_DIR}/libs/install/share/Servus/CMake 
                        ${PROJECT_SOURCE_DIR}/libs/equalizer/install/share/Servus/CMake
                        $ENV{EQ_ROOT}/install/share/Servus/CMake )

find_package(Lunchbox CONFIG REQUIRED PATHS ${PROJECT_SOURCE_DIR}/libs/install/share/Lunchbox/CMake 
                        ${PROJECT_SOURCE_DIR}/libs/equalizer/install/share/Lunchbox/CMake 
					    $ENV{EQ_ROOT}/install/share/Lunchbox/CMake )

find_package(vmmlib CONFIG REQUIRED PATHS ${PROJECT_SOURCE_DIR}/libs/install/share/vmmlib/CMake 
                        ${PROJECT_SOURCE_DIR}/libs/equalizer/install/share/vmmlib/CMake 
					    $ENV{EQ_ROOT}/install/share/vmmlib/CMake )

find_package(Pression CONFIG REQUIRED PATHS ${PROJECT_SOURCE_DIR}/libs/install/share/Pression/CMake 
                        ${PROJECT_SOURCE_DIR}/libs/equalizer/install/share/Pression/CMake 
                        $ENV{EQ_ROOT}/install/share/Pression/CMake  )

find_package(Collage CONFIG REQUIRED PATHS ${PROJECT_SOURCE_DIR}/libs/install/share/Collage/CMake 
                        ${PROJECT_SOURCE_DIR}/libs/equalizer/install/share/Collage/CMake 
					    $ENV{EQ_ROOT}/install/share/Collage/CMake  )

find_package(Equalizer CONFIG REQUIRED  PATHS ${PROJECT_SOURCE_DIR}/libs/install/share/Equalizer/CMake 
                        ${PROJECT_SOURCE_DIR}/libs/equalizer/install/share/Equalizer/CMake 
					    $ENV{EQ_ROOT}/install/share/Equalizer/CMake  )
