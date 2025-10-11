#include "Jardim.h"
using namespace std;

// Construtor
Jardim::Jardim(int nLinhas, int nColunas) {
    linhas = nLinhas;
    colunas = nColunas;

    // Alocação dinâmica da matriz
    area = new char*[linhas];
    for (int i = 0; i < linhas; ++i) {
        area[i] = new char[colunas];
        for (int j = 0; j < colunas; ++j)
            area[i][j] = ' '; // inicia tudo vazio
    }
}

// Destrutor
Jardim::~Jardim() {
    for (int i = 0; i < linhas; ++i)
        delete[] area[i];
    delete[] area;
}

// Converte número -> letra (0 -> 'A', 1 -> 'B', ...)
char Jardim::numeroParaLetra(int n) const {
    return 'A' + n;
}

// Define o símbolo de uma posição (ex: planta, ferramenta, jardineiro)
void Jardim::definirPosicao(int linha, int coluna, char simbolo) {
    if (linha < linhas && coluna < colunas)
        area[linha][coluna] = simbolo;
}

// Limpa uma posição
void Jardim::limparPosicao(int linha, int coluna) {
    if (linha < linhas &&  coluna < colunas)
        area[linha][coluna] = ' ';
}

// Imprime o jardim na consola com a régua de letras
void Jardim::imprimir() const {
    cout << "  "; // canto superior esquerdo
    for (int j = 0; j < colunas; ++j)
        cout << numeroParaLetra(j);
    cout << endl;

    for (int i = 0; i < linhas; ++i) {
        cout << numeroParaLetra(i) << " "; // régua lateral esquerda
        for (int j = 0; j < colunas; ++j)
            cout << area[i][j];
        cout << endl;
    }
}
