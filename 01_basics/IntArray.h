// #pragma once는 헤더 파일이 중복으로 포함되는 것을 막아주는 국룰 가드입니다.
#pragma once

class IntArray {
private:
    int* data; // 힙 메모리를 가리킬 포인터
    int size;

public:
    // 생성자: 객체가 태어날 때 호출
    IntArray(int size);

    // 소멸자: 객체가 죽을 때(scope를 벗어날 때) 자동 호출! (물결표 ~ 가 특징)
    ~IntArray();

    // 데이터를 넣고 빼는 함수
    void set(int index, int value);
    int get(int index);
};