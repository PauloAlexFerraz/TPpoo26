#include "Jardim.h"
using namespace std;

Jardim::Jardim(int nLinhas, int nColunas)
    : linhas(nLinhas), colunas(nColunas)
{
    // aloca a matriz dinâmica de solos
    solos = new Solo*[linhas];
    for (int i = 0; i < linhas; ++i)
        solos[i] = new Solo[colunas];
}

Jardim::~Jardim() {
    for (int i = 0; i < linhas; ++i)
        delete[] solos[i];
    delete[] solos;
}

char Jardim::numeroParaLetra(int n) const {
    return 'A' + n;
}

// Mostra apenas o mapa visual
void Jardim::imprimir() const {
    cout << " ";
    for (int j = 0; j < colunas; ++j)
        cout << numeroParaLetra(j);
    cout << endl;

    for (int i = 0; i < linhas; ++i) {
        cout << numeroParaLetra(i) << " ";
        for (int j = 0; j < colunas; ++j)
            cout << ' '; // mais tarde será planta/ferramenta/etc.
        cout << endl;
    }
}

// Mostra detalhes de todos os solos
void Jardim::listarArea() const {
    cout << "\n--- Informacao do Solo ---\n";
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cout << numeroParaLetra(i) << numeroParaLetra(j)
                 << " -> Agua: " << solos[i][j].getAgua()
                 << ", Nutrientes: " << solos[i][j].getNutrientes() << endl;
        }
    }
    cout << "-----------------------------------\n";
}

Solo& Jardim::getSolo(int linha, int coluna) {
    return solos[linha][coluna];
}

