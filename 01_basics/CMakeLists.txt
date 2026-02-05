cmake_minimum_required(VERSION 4.1)
project(01_basics)


set(CMAKE_CXX_STANDARD 20)
# --- 1. 여러 파일이 합쳐져야 하는 경우 (수동 등록) ---
add_executable(header_test main.cpp IntArray.cpp IntArray.h)

# --- 2. 나머지 파일 자동 등록 (알고리즘 문제 풀이용) ---
file(GLOB ALL_CPP_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

foreach(SOURCE_FILE ${ALL_CPP_FILES})
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)
    
    # 제외 파일 목록 (header_test에 포함된 파일들)
    set(EXCLUDED_FILES "main" "IntArray")
    list(FIND EXCLUDED_FILES ${FILE_NAME} INDEX)
    
    if(${INDEX} EQUAL -1)
        # 중요: 타겟 이름(실행 설정 이름)에는 한글/특수문자를 쓸 수 없습니다.
        # 파일명에서 영어, 숫자, 언더바(_)만 남기고 나머지는 제거합니다.
        string(REGEX REPLACE "[^a-zA-Z0-9_]" "" SAFE_NAME "${FILE_NAME}")
        
        # 만약 한글로만 된 파일이라 이름이 다 지워질 수도 있고, 중복될 수도 있으니
        # 파일명의 고유값(Hash) 앞 4글자를 붙여서 구분을 확실히 합니다.
        string(MD5 FILE_HASH "${FILE_NAME}")
        string(SUBSTRING "${FILE_HASH}" 0 4 SHORT_HASH)
        
        set(TARGET_NAME "01_${SAFE_NAME}_${SHORT_HASH}")

        if(NOT TARGET ${TARGET_NAME})
            add_executable(${TARGET_NAME} ${SOURCE_FILE})
        endif()
    endif()
endforeach()

