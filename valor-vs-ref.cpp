#include <iostream>
using namespace std;


void por_valor(int a) {
    a++;
    cout << "Nuevo valor de a: " << a << endl;
}



void por_referencia(int& a) {
    a++;
    cout << "Nuevo valor de a: " << a << endl;
}



int main() {
    int a1 = 1, a2 = 1;

    // antes
    cout << "a1 vale " << a1 << " y a2 vale " << a2 << endl;

    por_valor(a1);
    por_referencia(a2);

    // después
    cout << "a1 vale " << a1 << " y a2 vale " << a2 << endl;

    system("pause");
}