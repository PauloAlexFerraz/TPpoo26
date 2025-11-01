//
// Created by shado on 11/10/2025.
//

#ifndef SOLO_H
#define SOLO_H

#include "Settings.h"
#include <cstdlib>

class Solo {
private:
    int agua;
    int nutrientes;
public:
    Solo();

    int getAgua() const;
    int getNutrientes() const;

    void adicionarAgua(int valor);
    void adicionarNutrientes(int valor);
    void removerAgua(int valor);
    void removerNutrientes(int valor);
};

#endif
