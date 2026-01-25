#include <iostream>
#include <string> // 간점 포함

int main() {
    std::string name;
    int javaYears;
    int csharpYears;

    std::cout << "개발자 닉네임을 입력하세요 : ";
    std::cin >> name;
    std::cout << "Java 경력(개월)을 입력하세요 : ";
    std::cin >> javaYears;
    std::cout << "C# 경력을(개월) 입력하세요 : ";
    std::cin >> csharpYears;

    double totalYears = javaYears / 12 + csharpYears / 12;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "[" << name << "] 님의 총 개발 경력은 약 "
            << totalYears << "년 입니다." << std::endl;
    std::cout << "이제 C++ 마스터를 향해 출발합시다!" << std::endl;
    return 0;
}
