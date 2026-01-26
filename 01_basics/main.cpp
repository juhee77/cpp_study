#include <iostream>
#include "IntArray.h"

void testFunction() {
    std::cout << "--- 함수 시작 ---" << std::endl;

    // 객체 생성 -> 생성자 호출 (메모리 할당)
    IntArray myArray(5);

    myArray.set(0, 100);
    std::cout << "값: " << myArray.get(0) << std::endl;

    std::cout << "--- 함수 끝 (이제 myArray가 사라집니다) ---" << std::endl;

    // 함수가 끝나면 지역 변수 myArray가 스택에서 사라짐
    // 이때! 자동으로 소멸자(~IntArray)가 호출되면서 delete가 실행됨!
}

int main() {
    testFunction();
    std::cout << "메인 함수 종료" << std::endl;
    return 0;
}