//
// Created by guilh on 27/10/2025.
//

#ifndef ADUBO_H
#define ADUBO_H

#include "Solo.h"
#include <iostream>

class Adubo {
private:
    int quantidade; // unidades restantes do pacote
public:
    Adubo(); // construtor
    void aplicar(Solo &solo); // aplica 10 unidades ao solo
    bool vazio() const;       // retorna true se o pacote estiver vazio
};

#endif //ADUBO_H
