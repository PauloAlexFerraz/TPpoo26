#ifndef JARDIM_H
#define JARDIM_H

#include <iostream>

class Jardim {
private:
    int linhas;       // número de linhas do jardim
    int colunas;      // número de colunas do jardim
    char** area;      // matriz dinâmica que representa o conteúdo do jardim

    // converte número -> letra (0 -> 'A', 1 -> 'B', ...)
    char numeroParaLetra(int n) const;

public:
    // Construtor e destrutor
    Jardim(int nLinhas, int nColunas);
    ~Jardim();

    // Métodos principais
    void definirPosicao(int linha, int coluna, char simbolo); // define o símbolo numa posição
    void limparPosicao(int linha, int coluna);                // limpa a posição (coloca espaço)
    void imprimir() const;                                   // mostra o jardim na consola

    // Getters simples
    int getNumLinhas() const { return linhas; }
    int getNumColunas() const { return colunas; }
};

#endif
