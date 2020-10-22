#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


double calc( int a, int b ) {
    if (b == 0) throw logic_error("División entre cero.");
    return (double)a / b;
}


int main() {
    int x, y;
    double res;

    try {
        cout << "Introduzca dos números enteros: ";
        cin >> x >> y;
        res = calc(x, y);
        cout << x << "/" << y << " = " << res << endl;
    } 
    catch( string& s) {
        cerr << s << endl;
    } 
    catch( logic_error& error) {
        cerr << error.what() << endl;
    }
    catch(...) {
        cerr << "Error inesperado. \n";
        exit(1);
    }

    return 0; 
}
 
