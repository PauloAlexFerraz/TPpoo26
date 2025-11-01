#include "Roseira.h"
#include <iostream>
using namespace std;

Roseira::Roseira(int linha, int coluna)
    : Planta(linha, coluna, 'r') {
    agua = Settings::Roseira::inicial_agua;
    nutrientes = Settings::Roseira::inicial_nutrientes;
    instantesViva = 0;
}

void Roseira::atualizar(Solo& solo) {
    if (!viva)
        return;

    instantesViva++;

    int aguaSolo = solo.getAgua();
    int nutrientesSolo = solo.getNutrientes();

    int absorvidaAgua = Settings::Roseira::absorcao_agua;
    int absorvidaNutrientes = (nutrientesSolo < Settings::Roseira::absorcao_nutrientes)? nutrientesSolo: Settings::Roseira::absorcao_nutrientes;

    solo.removerAgua(absorvidaAgua);
    solo.removerNutrientes(absorvidaNutrientes);

    agua += absorvidaAgua;
    nutrientes += absorvidaNutrientes;

    agua -= Settings::Roseira::perda_agua;
    nutrientes -= Settings::Roseira::perda_nutrientes;

    if (agua < Settings::Roseira::morre_agua_menor ||
        nutrientes < Settings::Roseira::morre_nutrientes_menor ||
        nutrientes > Settings::Roseira::morre_nutrientes_maior) {
        morrer(solo);
    }

}

bool Roseira::querMultiplicar() const {
    return nutrientes > Settings::Roseira::multiplica_nutrientes_maior;
}

void Roseira::multiplicar() {
    nutrientes = Settings::Roseira::original_nutrientes;
    agua = (agua * Settings::Roseira::original_agua_percentagem) / 100;
}

void Roseira::morrer(Solo& solo) {
    viva = false;
    solo.adicionarNutrientes(nutrientes / 2);
    solo.adicionarAgua(agua / 3);

    nutrientes = 0;
    agua = 0;

    cout << "Roseira morreu em "<< (char)('A' + linha)<< (char)('A' + coluna)<< "\n";
}

std::string Roseira::getNome() const {
    return "Roseira";
}
