
cmake_minimum_required( VERSION 3.14 )
project( app LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED YES )

add_subdirectory(dependencies/GNDStk)

add_executable(app src/app.cpp)
target_link_libraries(app PUBLIC GNDStk)
