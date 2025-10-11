#include <iostream>
#include "Jardim.h"
using namespace std;

int main() {
    Jardim jardim(6, 13);

    jardim.definirPosicao(1, 2, 'c');
    jardim.definirPosicao(1, 3, 'c');
    jardim.definirPosicao(2, 2, 'c');
    jardim.definirPosicao(3, 5, 'r');
    jardim.definirPosicao(4, 7, 'e');
    jardim.definirPosicao(4, 8, 'e');
    jardim.definirPosicao(5, 7, 'e');
    jardim.definirPosicao(5, 8, 'e');
    jardim.definirPosicao(5, 9, 'e');

    jardim.imprimir();

    return 0;
}
