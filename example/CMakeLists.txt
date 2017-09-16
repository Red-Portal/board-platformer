cmake_minimum_required(VERSION 3.8)
project(board_platformer_examples)

if(BUILD_EXAMPLE_TIC_TAC_TOE)
    add_subdirectory(${PROJECT_SOURCE_DIR}/tic-tac-toe)
endif(BUILD_EXAMPLE_TIC_TAC_TOE)
