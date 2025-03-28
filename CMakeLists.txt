# CMake 최소 버전 설정
#cmake_minimum_required(VERSION 3.22.1)
cmake_minimum_required(VERSION 3.16.3)

# 프로젝트 이름 설정
project(MyProject)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# g++ 최소 버전 확인
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "11.4.0")
      message(FATAL_ERROR "g++ version must be 11.4.0 or higher. Current version: ${CMAKE_CXX_COMPILER_VERSION}")
    endif()
endif()

# 소스 파일 추가
add_executable(${PROJECT_NAME} main.cpp)
