cmake_minimum_required(VERSION 3.8)
project(board_platformer)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

# nana dependency X11
find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIR})

#
set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)
find_package(FontConfig REQUIRED) 
include_directories(${FontConfig_INCLUDE_DIR})

# nana library
set(NANA_ROOT_DIR "${SOURCE_DIR}/nana")
set(CMAKE_INSTALL_PREFIX ${NANA_ROOT_DIR})
add_subdirectory(${NANA_ROOT_DIR})
find_library(NANA_LIB NAME nana PATHS "${NANA_ROOT_DIR}")
message("NANA_LIB = ${NANA_LIB}")
include_directories(${NANA_ROOT_DIR}/include)

# board_platformer
set(SOURCE_FILES ${SOURCE_DIR}/main.cpp)
set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3 -pthread")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# nana linking
# if nana is already built, just link. if not, build nana
if(NOT NANA_LIB)
    message("lib nana not built. Adding as dependency.")
    add_dependencies(${PROJECT_NAME} nana)

    set_target_properties(nana
	PROPERTIES
	CXX_STANDARD 17)

    set(NANA_LIB ${NANA_ROOT_DIR}/libnana.a)
else()
    message("lib nana already built")
endif()

target_link_libraries(${PROJECT_NAME}
    ${FONTCONFIG_LIBRARIES}
    ${X11_LIBRARIES}
    ${X11_Xft_LIB}
    ${NANA_LIB}
    stdc++fs)
