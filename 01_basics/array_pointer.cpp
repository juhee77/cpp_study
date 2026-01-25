#include <iostream>

int main() {
    // 1. 배열 선언 (C#의 int[] arr = new int[5]; 와 다름)
    // 스택(Stack) 메모리에 연속된 5개의 int 공간을 잡습니다.
    int arr[5] = {10, 20, 30, 40, 50};

    // 2. 포인터가 배열의 첫 번째를 가리킴
    int* ptr = arr; // arr은 &arr[0]과 같음!

    std::cout << "--- 포인터 연산의 마법 ---" << std::endl;

    // 첫 번째 값
    std::cout << "*ptr     : " << *ptr << std::endl;     // 10

    // 두 번째 값 (주소를 한 칸 이동 후 역참조)
    std::cout << "*(ptr+1) : " << *(ptr + 1) << std::endl; // 20

    // 세 번째 값
    std::cout << "*(ptr+2) : " << *(ptr + 2) << std::endl; // 30

    std::cout << "-------------------------" << std::endl;

    // 반복문으로 돌리기 (i를 더해서 주소를 이동)
    for (int i = 0; i < 5; i++) {
        // arr[i]는 내부적으로 *(arr + i)로 변환되어 실행됩니다!
        std::cout << "arr[" << i << "] = " << *(ptr + i) << std::endl;
    }

    return 0;
}