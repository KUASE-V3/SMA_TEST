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
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "9.4.0")
      message(FATAL_ERROR "g++ version must be 11.4.0 or higher. Current version: ${CMAKE_CXX_COMPILER_VERSION}")
    endif()
endif()

# 모든 소스(.c) 파일 자동 수집
file(GLOB SRC_FILES "src/*.cpp")

# 모든 헤더(.h) 파일 자동 수집 (선택적 – 관리용)
file(GLOB HEADER_FILES "include/*.hpp")

# 정적 라이브러리 생성
add_library(mylib STATIC ${SRC_FILES})

# 헤더 디렉토리 추가
target_include_directories(mylib PUBLIC ${CMAKE_SOURCE_DIR}/include)

# main.cpp 실행 파일 생성
add_executable(MyProject main.cpp)

# 실행파일에 라이브러리 링크
target_link_libraries(MyProject mylib)

# main에서도 헤더 참조하도록 include 디렉토리 추가
target_include_directories(MyProject PRIVATE ${CMAKE_SOURCE_DIR}/include)