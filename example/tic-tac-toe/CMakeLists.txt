cmake_minimum_required(VERSION 3.8)
project(tic_tac_toe)

set(BUILD_FLAGS
    "${CMAKE_CXX_FLAGS} -g -fPIC -Wall -Wextra")
message("C++ flags = ${BUILD_FLAGS}")

set(TICTACTOE_SOURCE_FILES ${PROJECT_SOURCE_DIR}/main.cpp)

message("[ Source files for board_platformer ]")
foreach(TICTACTOE_FILE ${TICTACTOE_SOURCE_FILES})
    message(STATUS "${TICTACTOE_FILE}")
endforeach()

add_executable(${PROJECT_NAME} ${TICTACTOE_SOURCE_FILES})

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${INCLUDE_PATH})

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    board_platformer)

set_target_properties(${PROJECT_NAME}
    PROPERTIES COMPILE_FLAGS "${BUILD_FLAGS}")

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)
