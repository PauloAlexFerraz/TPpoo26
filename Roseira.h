//
// Created by shado on 14/10/2025.
//

#ifndef ROSEIRA_H
#define ROSEIRA_H

#include "Planta.h"
#include "Settings.h"

class Roseira : public Planta {
private:
    int instantesViva; // contador de tempo de vida (para evoluções futuras)

public:
    Roseira(int linha, int coluna);

    void atualizar(Solo& solo) override;
    std::string getNome() const override { return "Roseira"; }
};

#endif
