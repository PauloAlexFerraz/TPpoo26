//
// Created by shado on 11/10/2025.
//

#include "Planta.h"

Planta::Planta(int l, int c, char simb)
    : linha(l), coluna(c), agua(0), nutrientes(0), viva(true), simbolo(simb) {
    // Nenhum comportamento específico aqui — as subclasses (como Cacto)
    // definem os seus próprios valores iniciais e lógica de crescimento/morte.
}

