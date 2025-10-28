#ifndef PLANTA_H
#define PLANTA_H

#include "Solo.h"
#include <string>

class Planta {
protected:
    int linha;
    int coluna;
    int agua;
    int nutrientes;
    bool viva;
    char simbolo;


public:
    Planta(int l, int c, char simb);
    ~Planta(); // destrutor normal

    virtual void atualizar(Solo& solo)=0;
    virtual std::string getNome() const=0;

    bool estaViva() const { return viva; }
    char getSimbolo() const { return simbolo; }

    static Planta* criarPlanta(char tipo, int linha, int coluna);
};

#endif