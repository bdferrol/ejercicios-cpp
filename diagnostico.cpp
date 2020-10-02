#include <iostream>

int main() {

    float temperatura;
    char tos_seca, falta_de_aire;
    int sintomas = 0;

    std::cout << "Introduzca temperatura en ºC:" << std::endl;
    std::cin >> temperatura;

    std::cout << "¿Tiene tos seca? (s/n)" << std::endl;
    std::cin >> tos_seca;

    std::cout << "¿Siente falta de aire? (s/n)" << std::endl;
    std::cin >> falta_de_aire;

    if (temperatura > 37.0) { sintomas++; }
    if (tos_seca == 's' || tos_seca == 'S') { sintomas++; }
    if (falta_de_aire == 's' || falta_de_aire == 'S') { sintomas++; }

    if (sintomas >= 2) {
        char contacto;
        std::cout << "¿Ha mantenido contacto con personas portadoras? (s/n)" << std::endl;
        std::cin >> contacto;

        if (contacto == 's' || contacto == 'S') {
            std::cout << "Probablemente tenga COVID-19. Debe permanecer en su domicilio." << std::endl;
        } else {
            std::cout << "Contacte con su médico para realizar una prueba PCR." << std::endl;
        }
    } else {

        std::cout << "No hay riesgo." << std::endl;
    }
    
    #ifdef _WIN32
    system("pause");
    #elif
    system("read -r");
    #endif    
}