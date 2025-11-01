//
// Created by guilh on 27/10/2025.
//

#include "adubo.h"


Adubo::Adubo() : quantidade(Settings::Adubo::capacidade) {} // começa com 100 unidades

void Adubo::aplicar(Solo &solo) {
    if (quantidade >= Settings::Adubo::dose) {
        solo.adicionarNutrientes(Settings::Adubo::dose);
        quantidade = quantidade - Settings::Adubo::dose;
        std::cout << "Adubo aplicado! Restam " << quantidade << " unidades\n";
    } else if (quantidade > 0) {
        solo.adicionarNutrientes(quantidade);
        quantidade = 0;
        std::cout << "Ultimas unidades de adubo aplicadas! Pacote vazio\n";
    } else {
        std::cout << "Pacote de adubo vazio! foi levado pelo vento\n";
    }
}

bool Adubo::vazio() const { return quantidade == 0; }