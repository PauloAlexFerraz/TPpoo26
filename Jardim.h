#ifndef JARDIM_H
#define JARDIM_H

#include <iostream>
#include "Solo.h"


class Planta;
class Jardineiro;

class Jardim {
private:
    int linhas;
    int colunas;
    Solo** solos;
    Planta** plantas;
    Jardineiro* jardineiro;

    char numeroParaLetra(int n) const;

public:
    Jardim(int nLinhas, int nColunas);
    ~Jardim();

    void imprimir() const;
    void listarArea() const;
    void listarSolo(int lin, int col, int raio = 0) const;


    bool adicionarPlanta(int linha, int coluna, Planta* p);
    bool criarPlantaAdjacente(Planta* p);
    bool removePlanta(int linha, int coluna);
    Planta* getPlanta(int linha, int coluna) const;
    Solo& getSolo(int linha, int coluna);

    void setJardineiro(Jardineiro* j) { jardineiro = j; }
    Jardineiro* getJardineiro() const { return jardineiro; }

    int getNumLinhas() const { return linhas; }
    int getNumColunas() const { return colunas; }
};

#endif
