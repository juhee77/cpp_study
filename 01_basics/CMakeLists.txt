cmake_minimum_required(VERSION 4.1)
project(01_basics)

set(CMAKE_CXX_STANDARD 20)
# --- 1. 여러 파일이 합쳐져야 하는 경우 (수동 등록) ---
add_executable(header_test main.cpp IntArray.cpp IntArray.h)

# --- 2. 나머지 파일 자동 등록 (알고리즘 문제 풀이용) ---
# 현재 폴더의 모든 .cpp 파일을 찾습니다.
file(GLOB ALL_CPP_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

foreach(SOURCE_FILE ${ALL_CPP_FILES})
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)
    
    # 수동으로 등록했거나, 실행 파일이 되면 안 되는 파일들 제외
    # main: header_test에 포함됨
    # IntArray: header_test에 포함됨 (main 없음)
    set(EXCLUDED_FILES "main" "IntArray")
    
    list(FIND EXCLUDED_FILES ${FILE_NAME} INDEX)
    
    # 제외 목록에 없고, 아직 타겟으로 등록되지 않았다면 추가
    if(${INDEX} EQUAL -1 AND NOT TARGET 01_basics_${FILE_NAME})
        # main 함수가 있는지 정밀 검사 대신, 일단 알고리즘 파일로 간주하고 추가
        # (컴파일 에러가 나면 main이 없는 파일임)
        add_executable(01_basics_${FILE_NAME} ${SOURCE_FILE})
    endif()
endforeach()

