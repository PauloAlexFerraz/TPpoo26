//
// Created by shado on 11/10/2025.
//

#ifndef COMANDOS_H
#define COMANDOS_H


#include <string>
#include "Jardim.h"
#include "adubo.h"
#include "Jardineiro.h"

class Comandos {
private:
    Jardim* jardim;
    Jardineiro* jardineiro;
    Adubo pacote;

public:
    Comandos();
    ~Comandos();

    void interpretar(const std::string& linha);
    void cicloPrincipal();
};

#endif
