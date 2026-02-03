cmake_minimum_required(VERSION 4.1)
project(01_basics)

set(CMAKE_CXX_STANDARD 20)

add_executable(01_basics_memory_hack memory_hack.cpp)
add_executable(01_basics_array_pointer array_pointer.cpp)
add_executable(01_basics_15999 19599_이진삼진탐색.cpp)
add_executable(01_basics_30030 30030_스위트콘가격구하기_basic.cpp)
add_executable(01_basics_input_output input_output.cpp)
add_executable(01_basics_heap_memory heap_memory.cpp)
add_executable(header_test main.cpp IntArray.cpp IntArray.h)

# --- 자동 등록 스크립트 ---
# 폴더 내의 모든 .cpp 파일을 찾아서
file(GLOB ALL_CPP_FILES "*.cpp")

foreach(SOURCE_FILE ${ALL_CPP_FILES})
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)
    
    # 제외할 파일 목록 (수동으로 등록했거나, main이 없는 파일들)
    set(EXCLUDE_FILES "main" "IntArray")
    
    # 이미 등록된 타겟인지, 혹은 제외 목록에 있는지 확인
    list(FIND EXCLUDE_FILES ${FILE_NAME} EXCLUDE_INDEX)
    if(NOT TARGET 01_basics_${FILE_NAME} AND ${EXCLUDE_INDEX} EQUAL -1)
        # main 함수가 있는 파일만 실행 파일로 등록 (단순 텍스트 검색)
        file(READ ${SOURCE_FILE} FILE_CONTENT)
        if("${FILE_CONTENT}" MATCHES "int[ \t\n\r]+main")
            add_executable(01_basics_${FILE_NAME} ${SOURCE_FILE})
        endif()
    endif()
endforeach()

