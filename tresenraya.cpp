#include <iostream>

/**
 * Array para contener el estado del tablero.
 */
int tablero[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

/**
 * Turno del jugador actual.
 */
int jugador = 1;


/**
 * Visualiza el estado del tablero.
 */
void mostrar_tablero() {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << tablero[i][j];
        }
        std::cout << std::endl;
    }
}


void solicitar_posicion(int& fila, int& columna) {
    std::cout << "Fila: ";
    std::cin >> fila;
    std::cout << "Columna: ";
    std::cin >> columna;
    fila--;
    columna--;    
}

bool casilla_ocupada(int fila, int columna) {
    return tablero[fila][columna] != 0;
}

int ganador() {
    for (int k = 0; k < 3; k++) {
        // comprobación de fila
        if (tablero[k][0] && tablero[k][0]==tablero[k][1] && tablero[k][0]==tablero[k][2]) return tablero[k][0];
        // comprobación de columna
        if (tablero[0][k] && tablero[0][k]==tablero[1][k] && tablero[0][k]==tablero[2][k]) return tablero[0][k];
    }

    // comprobación de diagonal directa
    if (tablero[0][0] && tablero[0][0]==tablero[1][1] && tablero[0][0]==tablero[2][2]) return tablero[0][0];

    // comprobación de diagonal inversa
    if (tablero[2][0] && tablero[2][0]==tablero[1][1] && tablero[2][0]==tablero[0][2]) return tablero[2][0];

    // en caso contrario, no hay ganador
    return 0;
}


int main() {

    for (int jugadas=0; jugadas<9 && !ganador(); jugadas++) {
        mostrar_tablero();
        std::cout << "Turno del jugador " << jugador << std::endl;
        while (true) {
            int fila, columna;
            solicitar_posicion(fila, columna);
            if (casilla_ocupada(fila, columna)) {
                std::cout << "Esa casilla ya está ocupada." << std::endl;
            } else {
                tablero[fila][columna] = jugador;
                break;
            }
        }
        jugador = 3 - jugador; //loca forma de cambiar de turno
    }

    mostrar_tablero();
    if (ganador()) {
        std::cout << "Gana el jugador " << ganador() << std::endl;
    } else {
        std::cout << "Empate." << std::endl;
    }

    system("pause");
    return 0;

}