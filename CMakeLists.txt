cmake_minimum_required(VERSION 3.15)
project(XNAlaraLib)

set(CMAKE_CXX_STANDARD 20)


add_library(XNAlaraLib SHARED src/library.cpp src/binary_xps.cpp src/binary_io.cpp include/xps/header.hpp src/xps/header.cpp src/xps/model.cpp src/xps/bone.cpp include/xps/bone.hpp src/xps/mesh.cpp include/xps/mesh.hpp)

add_executable(XNAlaraTest src/main.cpp src/binary_xps.cpp src/binary_io.cpp src/xps/header.cpp src/xps/model.cpp src/xps/bone.cpp include/xps/bone.hpp src/xps/mesh.cpp include/xps/mesh.hpp)

target_include_directories(XNAlaraLib PUBLIC include include)
target_include_directories(XNAlaraTest PUBLIC include include)
