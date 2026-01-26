#include "IntArray.h"
#include <iostream>

// 생성자 구현
IntArray::IntArray(int size) {
    this->size = size;
    // 여기서 힙 메모리 할당!
    data = new int[size]; 
    std::cout << "[생성자] 메모리 " << size << "개 할당됨!" << std::endl;
}

// 소멸자 구현 (가장 중요!)
IntArray::~IntArray() {
    // 여기서 메모리 해제!
    // 사용자가 깜빡해도 객체가 사라질 때 무조건 실행됨.
    if (data != nullptr) {
        delete[] data;
        std::cout << "[소멸자] 메모리 해제 완료! 뒷정리 끝." << std::endl;
    }
}

void IntArray::set(int index, int value) {
    if (index >= 0 && index < size) {
        data[index] = value;
    }
}

int IntArray::get(int index) {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return -1; // 에러 처리 대충
}