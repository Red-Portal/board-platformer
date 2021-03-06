 # protoc
 # --plugin=protoc-gen-grpc=/path-to/grpc_cpp_plugin
 # --cpp_out=
 # --grpc_out=
 # rpc_message.proto

 cmake_minimum_required(VERSION 3.8)
 project(board_platformer)

 # Build Options
 option(BUILD_EXAMPLE_TIC_TAC_TOE
     "build example tic-tac-toe" ON)

 # Global Configurations
 set(CMAKE_CXX_STANDARD 17)

 set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
 set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)

 set(CMAKE_MODULE_PATH
     ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

 set(BUILD_FLAGS
     "${CMAKE_CXX_FLAGS} -g -fPIC -Wall -Wextra")
 message("C++ flags = ${BUILD_FLAGS}")

 ### TARGET ###
 ## board_platformer main process
 set(MAIN_SOURCE_FILES
     # ${SOURCE_DIR}/main.cpp
     ${SOURCE_DIR}/form.cpp
     ${SOURCE_DIR}/logger.cpp
     ${SOURCE_DIR}/rpc_message.pb.cc
     ${SOURCE_DIR}/rpc_message.grpc.pb.cc
     ${SOURCE_DIR}/player.cpp)

 message("[ Source files for board_platformer ]")
 foreach(MAIN_FILE ${MAIN_SOURCE_FILES})
     message(STATUS "${MAIN_FILE}")
 endforeach()

 # add_executable(board_platformer ${MAIN_SOURCE_FILES})
 add_library(board_platformer STATIC ${MAIN_SOURCE_FILES})

 set_target_properties(board_platformer
     PROPERTIES COMPILE_FLAGS "${BUILD_FLAGS}")

 target_include_directories(board_platformer
     PUBLIC
     ${INCLUDE_PATH})
 
 target_link_libraries(board_platformer
     PUBLIC
     stdc++fs)

 ### TARGET ###
 ## board_platformer logger process
 set(LOGGER_SOURCE_DIR ${SOURCE_DIR}/logger)

 set(LOGGER_SOURCE_FILES
     ${LOGGER_SOURCE_DIR}/logger.cpp
     ${LOGGER_SOURCE_DIR}/main.cpp) 

 add_executable(board_platformer_logger ${LOGGER_SOURCE_FILES})

 target_link_libraries(board_platformer_logger
     PUBLIC
     pthread
     stdc++fs)

 set_target_properties(board_platformer_logger
     PROPERTIES COMPILE_FLAGS "${BUILD_FLAGS}")

 ## protobuf library
 find_package(Protobuf REQUIRED)

 target_link_libraries(board_platformer
     PUBLIC
     ${PROTOBUF_LIBRARY})

 target_include_directories(board_platformer
     PUBLIC
     ${PROTOBUF_INCLUDE_DIR})


 ## Grpc
 find_package(GRPC REQUIRED)

 target_include_directories(board_platformer
     PUBLIC
     ${GRPC_INCLUDE_DIR})

 target_link_libraries(board_platformer
     PUBLIC
     ${GRPC_LIBRARY}
     ${GRPC_GRPC++_LIBRARY})

 ## Boost
 find_package(Boost 1.64 COMPONENTS system filesystem REQUIRED)

 target_link_libraries(board_platformer
     PUBLIC
     ${Boost_SYSTEM_LIBRARY}
     ${Boost_FILESYSTEM_LIBRARY})

 target_link_libraries(board_platformer_logger
     PUBLIC
     ${Boost_SYSTEM_LIBRARY}
     ${Boost_FILESYSTEM_LIBRARY})

 target_include_directories(board_platformer
     PUBLIC
     ${BOOST_INCLUDE_DIRS})

 target_include_directories(board_platformer_logger
     PUBLIC
     ${BOOST_INCLUDE_DIRS})


 ## nana dependency X11
 find_package(X11 REQUIRED)
 message("[ found X11 for Unix ]")

 target_link_libraries(board_platformer
     PUBLIC
     ${X11_LIBRARIES}
     ${X11_Xft_LIB})

 target_include_directories(board_platformer
     PUBLIC
     ${X11_INCLUDE_DIR})

 ## Thread library dependency
 find_package(Threads REQUIRED)

 target_link_libraries(board_platformer_logger
     PUBLIC
     ${CMAKE_THREAD_LIBS_INIT})

 target_link_libraries(board_platformer
     PUBLIC
     ${CMAKE_THREAD_LIBS_INIT})

 ## FonConfig Custom findModule
 find_package(FontConfig REQUIRED) 
 message("[ found FontConfig for Unix ]")

 target_link_libraries(board_platformer
     PUBLIC
     ${FONTCONFIG_LIBRARIES})

 target_include_directories(board_platformer
     PUBLIC
     ${FontConfig_INCLUDE_DIR})

 ## nana library
 set(NANA_ROOT_DIR "${SOURCE_DIR}/nana")
 set(CMAKE_INSTALL_PREFIX ${NANA_ROOT_DIR})
 find_library(NANA_LIB NAME nana PATHS "${NANA_ROOT_DIR}")

 target_include_directories(board_platformer
     PUBLIC
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

 target_link_libraries(board_platformer
     PUBLIC
     ${NANA_LIB})

 # adding stdc++fs dependency again because nana required this linking order
 # please do not delete this
 target_link_libraries(board_platformer
     PUBLIC
     stdc++fs)

 ## include directories status 
 message("[ board_platformer include directories ]")
 get_target_property(MAIN_INCLUDE_DIRS board_platformer INCLUDE_DIRECTORIES)
 foreach(MAIN_INCLUDE_DIR ${MAIN_INCLUDE_DIRS})
     message(STATUS "${MAIN_INCLUDE_DIR}")
 endforeach()

 # EXAMPLES
 add_subdirectory(${PROJECT_SOURCE_DIR}/example)

 install(TARGETS board_platformer board_platformer_logger
     RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
     ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib
     LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib)
