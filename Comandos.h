//
// Created by shado on 11/10/2025.
//

#ifndef COMANDOS_H
#define COMANDOS_H


#include <string>
#include "Jardim.h"


class Comandos {
private:
    Jardim* jardim;  // ponteiro para o jardim atual (criado dinamicamente)

public:
    Comandos();
    ~Comandos();

    void interpretar(const std::string& linha); // interpreta uma linha de comando
    void cicloPrincipal();                      // loop principal de leitura de comandos
};

#endif
