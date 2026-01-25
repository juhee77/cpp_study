#include  <iostream>

int main() {
    int number = 100;
    int *ptr = &number;

    std::cout << "1. number의 값: " << number << std::endl;
    std::cout << "2. number의 주소 (&number): " << &number << std::endl;
    std::cout << "3. 포인터가 가진 값 (ptr): " << ptr << std::endl; // 2번과 같아야 함
    std::cout << "4. 포인터가 가리키는 값 (*ptr): " << *ptr << std::endl; // 1번과 같아야 함

    std::cout << "--------------------------------" << std::endl;

    // 3. 포인터를 통한 원본 조작 (Java에서는 불가능했던 것!)
    std::cout << ">> 포인터를 이용해 값을 500으로 변경합니다..." << std::endl;
    *ptr = 500; // "ptr이 가리키는 곳으로 가서 500을 넣어라"

    std::cout << "5. 변경 후 number의 값: " << number << std::endl; // number가 바뀌어 있음!

    return 0;
}