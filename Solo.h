//
// Created by shado on 11/10/2025.
//

#ifndef SOLO_H
#define SOLO_H

#include <cstdlib>

class Solo {
private:
    int agua;        // unidades de água
    int nutrientes;  // unidades de nutrientes

public:
    Solo();

    // getters
    int getAgua() const;
    int getNutrientes() const;

    // operações
    void adicionarAgua(int valor);
    void adicionarNutrientes(int valor);
    void removerAgua(int valor);
    void removerNutrientes(int valor);
};

#endif
