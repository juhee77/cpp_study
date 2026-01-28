#include <iostream>
#include <string>

int main() {
    int a;
    std::string st;
    std::cin >> a;
    std::cin >> st;
    if (st.find("gori") != std::string::npos) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
