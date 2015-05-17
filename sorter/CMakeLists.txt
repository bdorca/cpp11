cmake_minimum_required(VERSION 2.8.11)

project(sorter)



include_directories(
    C:/BME/6.felev/cpp11/codelite/sorter/
    C:/BME/6.felev/cpp11/codelite/sorter/

)

# Linker options
set(CMAKE_LDFLAGS "${CMAKE_LDFLAGS}  ")

# Library path
set(CMAKE_LDFLAGS "${CMAKE_LDFLAGS} -L\".\" ")

# Define the CXX sources
set ( CXX_SRCS
    main.cpp
)

set_source_files_properties(
    ${CXX_SRCS} PROPERTIES COMPILE_FLAGS 
    " -g -O0 -Wall")

add_executable(sorter ${CXX_SRCS} ${C_SRCS})

target_link_libraries(sorter
    SDL2main
    SDL2
)

