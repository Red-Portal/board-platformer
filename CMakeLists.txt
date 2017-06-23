cmake_minimum_required(VERSION 3.8)
project(QuineMccluskeyExample)

set(CMAKE_CXX_STANDARD 14)

if(MSVC)
	set(CMAKE_CXX_FLAGS "/WX- /Wall /O2 /Ob2")
else()
	set(CMAKE_CXX_FLAGS "-pthread -Wall -O3")
endif()

set(BOOST_INCLUDEDIR ~/libraries/boost)

# header only library
add_library(QuineMccluskey INTERFACE)
target_include_directories(QuineMccluskey INTERFACE include/)

# example project source directories
set(EXAMPLES ${PROJECT_SOURCE_DIR}/examples)

set(SOURCE_FILES
  ${EXAMPLES}/main.cpp) 


# Boost dependency
set(Boost_USE_STATIC_LIBS OFF)
find_package(Boost 1.64.0 REQUIRED)
find_package(Boost 1.64.0 COMPONENTS REQUIRED)

if(Boost_FOUND)
  message("found BOOST: " ${BOOST_ROOT})
  include_directories(${Boost_INCLUDE_DIR})
  add_executable(QuineMccluskeyExample ${SOURCE_FILES})
  #target_link_libraries(QuineMccluskeyExample Boost::exception)
else()
  message("couldn't find boost")
endif()

