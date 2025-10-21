#ifndef JARDIM_H
#define JARDIM_H

#include <iostream>
#include "Solo.h"

class Planta; // 👈 forward declaration

class Jardim {
private:
    int linhas;
    int colunas;
    Solo** solos;
    Planta*** plantas; // 👈 adiciona esta linha

    char numeroParaLetra(int n) const;

public:
    Jardim(int nLinhas, int nColunas);
    ~Jardim();

    void imprimir() const;
    void listarArea() const;
    void listarSolo(int lin, int col, int raio = 0) const;


    bool adicionarPlanta(int linha, int coluna, Planta* p);
    Planta* getPlanta(int linha, int coluna) const;
    Solo& getSolo(int linha, int coluna);

    int getNumLinhas() const { return linhas; }
    int getNumColunas() const { return colunas; }
};

#endif
