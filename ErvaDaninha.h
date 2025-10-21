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
    int instantesViva = 0;        // quantos instantes já passou viva
    bool madura = false;      // se está madura e pode espalhar-se

public:
    ErvaDaninha(int linha, int coluna);

    void atualizar(Solo& solo) override;     // comportamento por instante
    void morrer(Solo& solo);                 // comportamento ao morrer
    std::string getNome() const override;    // nome textual
};

#endif
