#include <iostream>
#include <string>

using namespace std;

int main() {
    int mes, dia;
    int dias[] = {20, 19, 20, 20, 21, 21, 23, 23, 23, 23, 22, 21}; 
    string zodiaco[] = {"Capricornio", "Acuario", "Piscis", "Aries", "Tauro", "Geminis", "Cancer", "Leo", "Virgo", "Libra", "Escorpio", "Sagitario"};

    cout << "Introduzca mes (1-12): " << endl;
    cin >> mes;
    --mes;

    cout << "Introduzca día (0-31): " << endl;
    cin >> dia;
    if (dia <= dias[mes]) {
        cout << zodiaco[mes] << endl;
    } else {
        cout << "Su signo del zodiaco es " << zodiaco[(mes + 1) % 12] << endl;
    }


    #ifdef _WIN32
    system("pause");
    #elif
    system("read -r");
    #endif       
}