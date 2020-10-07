#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {

    // Abrir fichero y notificar error en caso de no conseguirlo.
    ifstream datos("datos.csv");
    if (!datos) {
        cerr << "Error al leer el archivo de datos." << endl;
        return -1;
    }

    // Declaración de variables necesarias para el cálculo.
    int n = 0;
    double suma = 0.0;
    double suma_cuadrados = 0.0;

    // Leer indefinidamente datos hasta alcanzar fin de fichero.
    while (!datos.eof()) {
        double x;
        // Leer dato
        datos >> x;

        // Procesar dato
        n++;
        suma += x; //Añade a suma el valor de x
        suma_cuadrados += x*x; // Añade el cuadrado de x
    }

    // Cerrar el fichero.
    datos.close();

    // Mostrar resultados.
    cout << "Número de muestras: " << n << endl;
    cout << "Suma: " << suma << endl;

    // Si hay al menos 1 muestra, calculamos la media.
    if (n > 0) {
        double media = suma / n;
        cout << "Media: " << media << endl;


        // Si hay al menos 2 muestras, calculamos la desv. típica.
        if (n > 1) {
            double desv_tipica = sqrt((suma_cuadrados - n*media*media)/(n - 1));
            cout << "Desv. tipica: " << desv_tipica << endl;
        }

    }

    #ifdef _WIN32
    system("pause");
    #elif
    system("read -r");
    #endif   

    return 0;
}
