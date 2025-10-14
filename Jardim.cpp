#include "Jardim.h"
#include "Planta.h"  // 👈 IMPORTANTE: para o compilador saber o que é Planta
using namespace std;

Jardim::Jardim(int nLinhas, int nColunas)
    : linhas(nLinhas), colunas(nColunas)
{
    // aloca a matriz dinâmica de solos
    solos = new Solo*[linhas];
    plantas = new Planta**[linhas]; // 👈 nova matriz de plantas

    for (int i = 0; i < linhas; ++i) {
        solos[i] = new Solo[colunas];
        plantas[i] = new Planta*[colunas];

        for (int j = 0; j < colunas; ++j)
            plantas[i][j] = nullptr; // 👈 inicializa a posição sem planta
    }
}

Jardim::~Jardim() {
    // liberta as plantas e o solo
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j)
            delete plantas[i][j]; // 👈 apaga cada planta criada dinamicamente

        delete[] plantas[i]; // liberta linha de ponteiros
        delete[] solos[i];   // liberta linha de solos
    }

    delete[] plantas; // 👈 liberta o array principal
    delete[] solos;
}

char Jardim::numeroParaLetra(int n) const {
    return 'A' + n;
}

// Mostra o mapa visual
void Jardim::imprimir() const {
    cout << "  ";
    for (int j = 0; j < colunas; ++j)
        cout << numeroParaLetra(j);
    cout << endl;

    for (int i = 0; i < linhas; ++i) {
        cout << numeroParaLetra(i) << " ";
        for (int j = 0; j < colunas; ++j) {
            if (plantas[i][j] != nullptr)
                cout << plantas[i][j]->getSimbolo(); // 👈 mostra o símbolo da planta
            else
                cout << ' ';
        }
        cout << endl;
    }
}

bool Jardim::adicionarPlanta(int linha, int coluna, Planta* p) {
    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas)
        return false;

    if (plantas[linha][coluna] != nullptr)
        return false; // já existe planta aqui

    plantas[linha][coluna] = p;
    return true;
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

Planta* Jardim::getPlanta(int linha, int coluna) const {
    return plantas[linha][coluna];
}
