//
// Created by shado on 11/10/2025.
//

#ifndef CACTO_H
#define CACTO_H

#include "Planta.h"
#include "Settings.h"
#include <string>

class Cacto : public Planta {
private:
    int instantesAguaAlta = 0;
    int instantesNutrientesZero = 0;

public:
    Cacto(int linha, int coluna);

    void atualizar(Solo& solo) override;     // comportamento por instante
    std::string getNome() const override;    // nome textual
};

#endif
