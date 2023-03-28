cmake_minimum_required(VERSION 3.12)
project(GOL CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(GoL_lib src/static_board.cpp src/AlwaysNextTurn.cpp src/InputController.cpp src/UpdateController.cpp src/UserCommands.cpp src/view.cpp src/donut_board.cpp src/cylinder_board.cpp)
target_include_directories(GoL_lib PUBLIC include)

add_executable(GoL src/main.cpp)
target_link_libraries(GoL GoL_lib)



