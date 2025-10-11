//
// Created by shado on 11/10/2025.
//
#ifndef PLANTA_H
#define PLANTA_H

#include <string>
#include "Solo.h"

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
    virtual ~Planta() = default;

    virtual void atualizar(Solo& solo) = 0; // agora recebe referência ao solo
    virtual std::string getNome() const = 0;

    char getSimbolo() const { return simbolo; }
    bool estaViva() const { return viva; }
};

#endif
