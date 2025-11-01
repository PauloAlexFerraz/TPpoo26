//
// Created by guilh on 27/10/2025.
//

#ifndef ADUBO_H
#define ADUBO_H

#include "Solo.h"
#include "Settings.h"
#include <iostream>

class Adubo {
private:
    int quantidade;
public:
    Adubo();
    void aplicar(Solo &solo);
    bool vazio() const;
};

#endif //ADUBO_H
