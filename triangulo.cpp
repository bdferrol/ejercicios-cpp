#include <iostream>

int main() {
    float b, h, s;
    std::cout << "Introduzca base" << std::endl;
    std::cin >> b;
    std::cout << "Introduzca altura" << std::endl;
    std::cin >> h;
    s = b * h / 2;
    std::cout << "Superficie: " << s << " m^2" << std::endl;

    #ifdef _WIN32
    system("pause");
    #elif
    system("read -r");
    #endif

}