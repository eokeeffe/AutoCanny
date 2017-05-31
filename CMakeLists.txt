cmake_minimum_required (VERSION 2.8)
project (AutoCanny)

find_package(OpenCV 3.1 REQUIRED)

find_package(OpenMP)

## Compiler flags
#if(CMAKE_COMPILER_IS_GNUCXX)
#    set(CMAKE_CXX_FLAGS "-O3")        ## Optimize
#    set(CMAKE_EXE_LINKER_FLAGS "-s")  ## Strip binary
#endif()

if (OPENMP_FOUND)
    set (HAVE_OPENMP TRUE)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
else()
    set (HAVE_OPENMP FALSE)
endif()

include_directories(
    ${OPENCV_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include/
)

add_definitions(-std=c++11)

add_executable(main src/main.cpp)
target_link_libraries(main ${OpenCV_LIBS})
