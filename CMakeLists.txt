cmake_minimum_required(VERSION 3.8)
project(BoardPlatformer)

set(CMAKE_CXX_STANDARD 17) 

if(MSVC)
	set(CMAKE_CXX_FLAGS "/WX- /Wall /O2 /Ob2")
else()
	set(CMAKE_CXX_FLAGS "-pthread -Wall -O3")
endif()

# example project source directories
set(SOURCE ${PROJECT_SOURCE_DIR}/src)

set(SOURCE_FILES
  ${SOURCE}/main.cpp) 


add_executable(BoardPlatformer ${SOURCE_FILES})


