find_package(Lunchbox CONFIG REQUIRED PATHS ${PROJECT_SOURCE_DIR}/libs/equalizer/install/share/Lunchbox/CMake 
					    $ENV{EQ_ROOT}/install/share/Lunchbox/CMake )

find_package(vmmlib CONFIG REQUIRED PATHS ${PROJECT_SOURCE_DIR}/libs/equalizer/install/share/vmmlib/CMake 
					  $ENV{EQ_ROOT}/install/share/vmmlib/CMake )

find_package(Pression CONFIG REQUIRED PATHS ${PROJECT_SOURCE_DIR}/libs/equalizer/install/share/Pression/CMake 
				            $ENV{EQ_ROOT}/install/share/Pression/CMake  )

find_package(Collage CONFIG REQUIRED PATHS ${PROJECT_SOURCE_DIR}/libs/equalizer/install/share/Collage/CMake 
					   $ENV{EQ_ROOT}/install/share/Collage/CMake  )

find_package(Equalizer CONFIG REQUIRED  PATHS ${PROJECT_SOURCE_DIR}/libs/equalizer/install/share/Equalizer/CMake 
					      $ENV{EQ_ROOT}/install/share/Equalizer/CMake  )
