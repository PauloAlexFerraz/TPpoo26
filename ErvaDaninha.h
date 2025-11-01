//
// Created by shado on 11/10/2025.
//

#ifndef ERVADANINHA_H
#define ERVADANINHA_H

#include "Planta.h"
#include "Settings.h"
#include <string>

class ErvaDaninha : public Planta {
private:
    int instantesViva = 0;
    int instantesDesdeUltimaMultiplicacao;
    bool quer_multiplicar;

public:
    ErvaDaninha(int linha, int coluna);

    void atualizar(Solo& solo);
    bool querMultiplicar() const override;
    void multiplicar() override;
    void morrer(Solo& solo);
    std::string getNome() const override;
};

#endif
