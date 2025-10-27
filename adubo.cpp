//
// Created by guilh on 27/10/2025.
//

#include "adubo.h"


Adubo::Adubo() : quantidade(100) {} // começa com 100 unidades

void Adubo::aplicar(Solo &solo) {
    if (quantidade >= 10) {
        solo.adicionarNutrientes(10);
        quantidade = quantidade - 10;
        std::cout << "Adubo aplicado! Restam " << quantidade << " unidades.\n";
    } else if (quantidade > 0) {
        solo.adicionarNutrientes(quantidade);
        quantidade = 0;
        std::cout << "Últimas unidades de adubo aplicadas! Pacote vazio.\n";
    } else {
        std::cout << "Pacote de adubo vazio! Levado pelo vento.\n";
    }
}

bool Adubo::vazio() const { return quantidade == 0; }