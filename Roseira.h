//
// Created by shado on 14/10/2025.
//

#ifndef ROSEIRA_H
#define ROSEIRA_H

#include "Planta.h"
#include "Settings.h"
#include <string>

class Roseira : public Planta {
private:
    int instantesViva;
    int flores; // número de flores (para comportamento visual, opcional)

public:
    Roseira(int linha, int coluna);

    void atualizar(Solo& solo);
    void morrer(Solo& solo);
    std::string getNome() const;
};

#endif
