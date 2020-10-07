#include <fstream>
#include <iostream>

int main() {
    int histograma[10] = {0,0,0,0,0,0,0,0,0,0};
    std::ifstream datos("datos.csv");

    if (!datos) {
        std::cerr << "Error leyendo datos." << std::endl;
        return -1;
    }

    while (datos) {
        double x;
        datos >> x;

        /*
        if (x >= 0.0 && x <= 0.5) histograma[0]++;
        if (x >= 0.5 && x <= 1.0) histograma[1]++;
        if (x >= 1.0 && x <= 1.5) histograma[2]++;
        if (x >= 1.5 && x <= 2.0) histograma[3]++;
        if (x >= 2.0 && x <= 2.5) histograma[4]++;
        if (x >= 2.5 && x <= 3.0) histograma[5]++;
        if (x >= 3.0 && x <= 3.5) histograma[6]++;
        if (x >= 3.5 && x <= 4.0) histograma[7]++;
        if (x >= 4.0 && x <= 4.5) histograma[8]++;
        if (x >= 4.5 && x <= 5.0) histograma[9]++;
        */

        /*
        for (int i = 0; i < 10; i++) {
            if (x >= 0.5*i && x <= 0.5*(i+1)) {
                histograma[i]++;
                break;
            }
        }
        */

        int k = (int) (x * 2);
        histograma[k]++; 
        

    }

    datos.close();

    for (int i = 0; i < 10; i++)
    {
        std::cout << histograma[i] << std::endl;
    }
    
    system("pause");

    return 0;
}