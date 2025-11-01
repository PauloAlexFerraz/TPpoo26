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

    void atualizar(Solo& solo) override;
    void morrer(Solo& solo) override;
    bool querMultiplicar() const override;
    void multiplicar() override;
    std::string getNome() const override;
};

#endif
