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

 set(BUILD_FLAGS
     "${CMAKE_CXX_FLAGS} -g -fPIC -Wall -Wextra")
 message("C++ flags = ${BUILD_FLAGS}")

 ### TARGET ###
 ## board_platformer main process
 set(MAIN_SOURCE_FILES
     ${SOURCE_DIR}/main.cpp
     ${SOURCE_DIR}/form.cpp
     ${SOURCE_DIR}/logger.cpp
     ${SOURCE_DIR}/server.cpp
     ${SOURCE_DIR}/rpc_message.pb.cc
     ${SOURCE_DIR}/rpc_message.grpc.pb.cc
     ${SOURCE_DIR}/player.cpp)

 message("[ Source files for board_platformer ]")
 foreach(MAIN_FILE ${MAIN_SOURCE_FILES})
     message(STATUS "${MAIN_FILE}")
 endforeach()

 add_executable(board_platformer ${MAIN_SOURCE_FILES})

 set_target_properties(board_platformer
     PROPERTIES COMPILE_FLAGS "${BUILD_FLAGS}")

 target_include_directories(board_platformer
     PUBLIC
     ${PROJECT_SOURCE_DIR}/include)
 
 target_link_libraries(board_platformer
     PRIVATE
     stdc++fs)


 ### TARGET ###
 ## board_platformer logger process
 set(LOGGER_SOURCE_DIR ${SOURCE_DIR}/logger)

 set(LOGGER_SOURCE_FILES
     ${LOGGER_SOURCE_DIR}/logger.cpp
     ${LOGGER_SOURCE_DIR}/main.cpp) 

 add_executable(board_platformer_logger ${LOGGER_SOURCE_FILES})

 target_link_libraries(board_platformer_logger
     PRIVATE
     pthread
     stdc++fs)

 set_target_properties(board_platformer_logger
     PROPERTIES COMPILE_FLAGS "${BUILD_FLAGS}")

 ## protobuf library
 find_package(Protobuf REQUIRED)

 target_link_libraries(board_platformer
     PRIVATE
     ${PROTOBUF_LIBRARY})

 target_include_directories(board_platformer
     PRIVATE
     ${PROTOBUF_INCLUDE_DIR})


 ## Grpc
 find_package(GRPC REQUIRED)

 target_include_directories(board_platformer
     PRIVATE
     ${GRPC_INCLUDE_DIR})

 target_link_libraries(board_platformer
     PRIVATE
     ${GRPC_LIBRARY}
     ${GRPC_GRPC++_LIBRARY})

 ## Boost
 find_package(Boost 1.64 COMPONENTS system filesystem REQUIRED)

 target_link_libraries(board_platformer
     PRIVATE
     ${Boost_SYSTEM_LIBRARY}
     ${Boost_FILESYSTEM_LIBRARY})

 target_link_libraries(board_platformer_logger
     PRIVATE
     ${Boost_SYSTEM_LIBRARY}
     ${Boost_FILESYSTEM_LIBRARY})

 target_include_directories(board_platformer
     PRIVATE
     ${BOOST_INCLUDE_DIRS})

 target_include_directories(board_platformer_logger
     PRIVATE
     ${BOOST_INCLUDE_DIRS})


 ## nana dependency X11
 find_package(X11 REQUIRED)
 message("[ found X11 for Unix ]")

 target_link_libraries(board_platformer
     PRIVATE
     ${X11_LIBRARIES}
     ${X11_Xft_LIB})

 target_include_directories(board_platformer
     PRIVATE
     ${X11_INCLUDE_DIR})

 ## Thread library dependency
 find_package(Threads REQUIRED)

 target_link_libraries(board_platformer
     PRIVATE
     ${CMAKE_THREAD_LIBS_INIT})

 target_link_libraries(board_platformer_logger
     PRIVATE
     ${CMAKE_THREAD_LIBS_INIT})

 ## FonConfig Custom findModule
 find_package(FontConfig REQUIRED) 
 message("[ found FontConfig for Unix ]")

 target_link_libraries(board_platformer
     PRIVATE
     ${FONTCONFIG_LIBRARIES})

 target_include_directories(board_platformer
     PRIVATE
     ${FontConfig_INCLUDE_DIR})

 ## nana library
 set(NANA_ROOT_DIR "${SOURCE_DIR}/nana")
 set(CMAKE_INSTALL_PREFIX ${NANA_ROOT_DIR})
 find_library(NANA_LIB NAME nana PATHS "${NANA_ROOT_DIR}")

 target_include_directories(board_platformer
     PRIVATE
     ${NANA_ROOT_DIR}/include)

 # if nana is already built, just link. if not, build nana from scratch
 if(NOT NANA_LIB)
     message("[ lib nana not built or not found ]")
     message(STATUS "Building nana.")
     add_subdirectory(${NANA_ROOT_DIR})
     add_dependencies(board_platformer nana)

     # nana's standard must be set to higher than C++1z
     # in order to use std filesystem
     set_target_properties(nana
	 PROPERTIES
	 CXX_STANDARD 17)


     # absolute path to libnana. Need something better than this
     set(NANA_LIB ${NANA_ROOT_DIR}/libnana.a)
 else()
     message("[ lib nana found ]")
     message(STATUS "PATH = ${NANA_LIB}")
     message(STATUS "skipping building nana.")
 endif()

 # set_target_properties(nana
 # 	   PROPERTIES LINK_INTERFACE_LIBRARIES
 # 	   stdc++fs)

 target_link_libraries(board_platformer
     PRIVATE
     ${NANA_LIB})

 # adding stdc++fs dependency again because nana required this linking order
 # do not delete this
 target_link_libraries(board_platformer
     PRIVATE
     stdc++fs)

 ## include directories status 
 message("[ board_platformer include directories ]")
 get_target_property(MAIN_INCLUDE_DIRS board_platformer INCLUDE_DIRECTORIES)
 foreach(MAIN_INCLUDE_DIR ${MAIN_INCLUDE_DIRS})
     message(STATUS "${MAIN_INCLUDE_DIR}")
 endforeach()

 install(TARGETS board_platformer board_platformer_logger
     RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin/)
