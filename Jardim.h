#ifndef JARDIM_H
#define JARDIM_H

#include <iostream>
#include "Solo.h"

class Jardim {
private:
    int linhas;
    int colunas;
    Solo** solos; // matriz de solos

    char numeroParaLetra(int n) const;

public:
    Jardim(int nLinhas, int nColunas);
    ~Jardim();

    void imprimir() const;
    void listarArea() const; // novo método

    int getNumLinhas() const { return linhas; }
    int getNumColunas() const { return colunas; }

    Solo& getSolo(int linha, int coluna);
};

#endif

