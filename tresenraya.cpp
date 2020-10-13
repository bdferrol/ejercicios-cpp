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


char simbolo(int v) {
    switch (v) {
        case 0: return ' ';
        case 1: return 'O';
        case 2: return 'X';
    }
}


/**
 * Visualiza el estado del tablero.
 */
void mostrar_tablero() {
    for (int i = 0; i < 3; i++)
    {
        std::cout << "+---+---+---+" << std::endl;
        for (int j = 0; j < 3; j++)
        {
            std::cout << "| " << simbolo(tablero[i][j]) << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "+---+---+---+" << std::endl;
}


/**
 * Pide por teclado dos valores entre 1 y 3, entregándolos en
 * las variables fila y columna (pasadas por referencia).
 * Si el usuario introduce valores fuera de rango, vuelve a pedirselo.
 * Al final, los valores son corregidos: el valor final de ambos estará
 * entre 0 y 2.
 */
void solicitar_posicion(int& fila, int& columna) {
    do {
        std::cout << "Introduzca fila: " << std::endl;
        std::cin >> fila;
    } while(fila < 1 || fila > 3);
    fila--;

    do {
        std::cout << "Introduzca columna: " << std::endl;
        std::cin >> columna;
    } while(columna < 1 || columna > 3);
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