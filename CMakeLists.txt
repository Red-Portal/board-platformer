cmake_minimum_required(VERSION 3.8)
project(BoardPlatformer)

set(CMAKE_CXX_STANDARD 17) 

if(MSVC)
	set(CMAKE_CXX_FLAGS "/WX- /Wall /O2 /Ob2")
else()
	set(CMAKE_CXX_FLAGS "-pthread -Wall -O3")
endif()

set(BOOST_INCLUDEDIR ~/libraries/boost)

# example project source directories
set(EXAMPLES ${PROJECT_SOURCE_DIR}/examples)

set(SOURCE_FILES
  ${EXAMPLES}/main.cpp) 


add_executable(BoardPlatformer ${SOURCE_FILES})


