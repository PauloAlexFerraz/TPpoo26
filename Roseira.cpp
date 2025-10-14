//
// Created by shado on 14/10/2025.
//

#include "Roseira.h"
#include <iostream>
using namespace std;

Roseira::Roseira(int l, int c)
    : Planta(l, c, 'r'), instantesViva(0)
{
    agua = Settings::Roseira::inicial_agua;
    nutrientes = Settings::Roseira::inicial_nutrientes;
    viva = true;
}

void Roseira::atualizar(Solo& solo) {
    if (!viva)
        return;

    instantesViva++;

    // Perda natural de água e nutrientes
    agua -= Settings::Roseira::perda_agua;
    nutrientes -= Settings::Roseira::perda_nutrientes;

    // Absorção de água e nutrientes do solo
    agua += Settings::Roseira::absorcao_agua;
    nutrientes += Settings::Roseira::absorcao_nutrientes;

    // Atualiza o solo (usa os nomes corretos)
    solo.removerAgua(Settings::Roseira::absorcao_agua);
    solo.removerNutrientes(Settings::Roseira::absorcao_nutrientes);

    // Verifica condições de morte
    if (agua < Settings::Roseira::morre_agua_menor ||
        nutrientes < Settings::Roseira::morre_nutrientes_menor ||
        nutrientes > Settings::Roseira::morre_nutrientes_maior) {

        viva = false;
        cout << "Roseira morreu em ("
             << char('A' + linha)
             << char('A' + coluna)
             << ")\n";
        }
}
