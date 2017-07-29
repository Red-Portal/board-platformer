 # protoc
 # --plugin=protoc-gen-grpc=/path-to/grpc_cpp_plugin
 # --cpp_out=
 # --grpc_out=
 # rpc_message.proto

 cmake_minimum_required(VERSION 3.8)
 project(board_platformer)

 set(CMAKE_CXX_STANDARD 17)

 set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

 set(CMAKE_MODULE_PATH
     ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

 # board_platformer
 include_directories(${PROJECT_SOURCE_DIR}/include)

 set(SOURCE_FILES
     ${SOURCE_DIR}/main.cpp
     ${SOURCE_DIR}/form.cpp
     ${SOURCE_DIR}/logger.cpp
     ${SOURCE_DIR}/server.cpp
     ${SOURCE_DIR}/rpc_message.pb.cc
     ${SOURCE_DIR}/rpc_message.grpc.pb.cc
     ${SOURCE_DIR}/player.cpp)

 message("Source Files = ${SOURCE_FILES}")

 set(BUILD_FLAGS
     "${CMAKE_CXX_FLAGS} -fPIC -Wall -Wextra -O3")
 message("C++ flags = ${BUILD_FLAGS}")

 add_executable(${PROJECT_NAME} ${SOURCE_FILES})

 # Grpc
 find_package(GRPC REQUIRED)
 include_directories(GRPC_INCLUDE_DIRS)

 # Boost
 find_package(Boost 1.64 COMPONENTS system filesystem REQUIRED)
 include_directories(${BOOST_INCLUDE_DIRS})

 # nana dependency X11
 find_package(X11 REQUIRED)
 include_directories(${X11_INCLUDE_DIR})
 message("found X11 for Unix.")

 # Thread library dependency
 find_package(Threads REQUIRED)

 # FonConfig Custom findModule
 find_package(FontConfig REQUIRED) 
 include_directories(${FontConfig_INCLUDE_DIR})
 message("found FontConfig for Unix.")

 # nana library
 set(NANA_ROOT_DIR "${SOURCE_DIR}/nana")
 set(CMAKE_INSTALL_PREFIX ${NANA_ROOT_DIR})
 # add_subdirectory(${NANA_ROOT_DIR})
 find_library(NANA_LIB NAME nana PATHS "${NANA_ROOT_DIR}")
 message("NANA_LIB = ${NANA_LIB}")
 include_directories(${NANA_ROOT_DIR}/include)

 # protobuf library
 find_package(Protobuf REQUIRED)
 include_directories(${PROTOBUF_INCLUDE_DIR})

 # nana linking
 # if nana is already built, just link. if not, build nana
 if(NOT NANA_LIB)
     message("lib nana not built. Adding as dependency.")
     add_dependencies(${PROJECT_NAME} nana)

     # nana's standard must be set to higher than C++1z
     # in order to use std filesystem
     set_target_properties(nana
	 PROPERTIES
	 CXX_STANDARD 17)

     # absolute path to libnana. Need something better than this
     set(NANA_LIB ${NANA_ROOT_DIR}/libnana.a)
 else()
     message("lib nana already built, skipping building nana.")
 endif()

 set_target_properties(${PROJECT_NAME}
     PROPERTIES COMPILE_FLAGS "${BUILD_FLAGS}")

 target_link_libraries(${PROJECT_NAME}
     ${FONTCONFIG_LIBRARIES}
     ${X11_LIBRARIES}
     ${X11_Xft_LIB}
     ${NANA_LIB}
     ${PROTOBUF_LIBRARY}
     ${CMAKE_THREAD_LIBS_INIT}
     ${Boost_SYSTEM_LIBRARY}
     ${Boost_FILESYSTEM_LIBRARY}
     ${GRPC_LIBRARIES}
     stdc++fs)
