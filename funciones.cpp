#include <iostream>


double media(double a, double b) {
    return (a + b)/2;
}

/**
 * Esta función solicita un número por la entrada estándar
 * dentro del intervalo delimitado por desde y hasta. En el
 * caso de introducir un número fuera de ese rango, volverá a
 * solicitarlo.
 * La función trabaja con números enteros.
 */
int introducir_numero(int desde, int hasta) {
    int numero;

    do {
        std::cout << "Introduzca número entre " << desde << " y " << hasta << std::endl;
        std::cin >> numero;
    } while (numero < desde || numero > hasta);

    return numero;
}


int main() {
    //std::cout << media(5, 7) << std::endl;
    //std::cout << media(2.3, 2.6) << std::endl;
    int n = introducir_numero(1, 10);
    std::cout << "Número introducido: " << n << std::endl;

    system("pause");
}