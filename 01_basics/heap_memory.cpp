#include <iostream>

int main() {
    std::cout << "--- 단일 변수 동적 할당 ---" << std::endl;
    // 1. 힙에 int 공간 하나 빌리기 (Java: Integer p = new Integer(10);)
    int* p = new int; 
    *p = 10;

    std::cout << "힙에 저장된 값: " << *p << std::endl;

    // 2. 다 썼으면 반납하기 (매우 중요!)
    delete p; 
    // 주의: p 변수 자체는 남아있지만, p가 가리키던 집은 철거되었습니다.
    // 이제 p를 다시 쓰면 큰일 납니다 (Dangling Pointer).

    std::cout << "--- 배열 동적 할당 ---" << std::endl;
    int size;
    std::cout << "배열 크기를 입력하세요: ";
    std::cin >> size; // 런타임에 크기 결정 가능!

    // 3. 힙에 배열 빌리기 (Java: int[] arr = new int[size];)
    int* arr = new int[size];

    for(int i = 0; i < size; i++) {
        arr[i] = i * 10;
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    // 4. 배열 반납하기 (반드시 []를 붙여야 함!)
    delete[] arr; 

    std::cout << "메모리 해제 완료!" << std::endl;

    return 0;
}