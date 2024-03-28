cmake_minimum_required(VERSION 3.14) 

project(BuildLibHV VERSION 1.0 LANGUAGES C CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  libhv
  GIT_REPOSITORY https://github.com/ithewei/libhv.git
  GIT_TAG master 
)
FetchContent_MakeAvailable(libhv)

# Define client
add_executable(client client_ws.cc)
target_include_directories(client PRIVATE ${libhv_BINARY_DIR}/include)
target_link_libraries(client hv)

# Define server
add_executable(server server_ws.cc)
target_include_directories(server PRIVATE ${libhv_BINARY_DIR}/include)
target_link_libraries(server hv)
