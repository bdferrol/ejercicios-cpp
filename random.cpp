#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {


    srand(time(NULL));
    int secreto = rand() % 1000;
    int intentos;

    for (intentos = 10; intentos > 0; intentos--) {
        int numero;

        cout << "Te quedan " << intentos << " intentos." << endl;
        cout << "Adivina el número secreto: " << endl;
        cin >> numero;
        
        if (numero > secreto) {
            cout << "Te pasas." << endl;
        } else if (numero < secreto) {
            cout << "Te quedas corto." << endl;
        } else {
            cout << "¡Acertaste!" << endl;
            break;
        }
    }

    if (!intentos) {
        cout << "No te quedan más intentos. Mala suerte." << endl;
        cout << "El número secreto era el " << secreto << endl;
    }

    #ifdef _WIN32
    system("pause");
    #elif
    system("read -r");
    #endif  

    return 0;
}