#include "Orquidia.h"
#include <iostream>
using namespace std;

const int Orquidia::ABSORCAO_AGUA = 8;
const int Orquidia::ABSORCAO_NUTRIENTES = 10;
const int Orquidia::PERDA_AGUA = 3;
const int Orquidia::PERDA_NUTRIENTES = 2;
const int Orquidia::MORRE_AGUA_MAIOR = 120;
const int Orquidia::MORRE_AGUA_INSTANTES = 2;
const int Orquidia::MORRE_NUTRIENTES_MENOR = 2;
const int Orquidia::MORRE_NUTRIENTES_INSTANTES = 3;
const int Orquidia::MULTIPLICA_AGUA_MAIOR = 50;
const int Orquidia::MULTIPLICA_NUTRIENTES_MAIOR = 70;
const int Orquidia::NOVA_AGUA_PERCENTAGEM = 50;
const int Orquidia::NOVA_NUTRIENTES = 20;

Orquidia::Orquidia(int linha, int coluna)
    : Planta(linha, coluna, 'x') {
    agua = 20;
    nutrientes = 25;
    instantesViva = 0;
    instantesAguaAlta = 0;
    instantesNutrientesBaixos = 0;
}

void Orquidia::atualizar(Solo& solo) {
    if (!viva)
        return;

    instantesViva++;

    int aguaSolo = solo.getAgua();
    int nutrientesSolo = solo.getNutrientes();

    int absorvidaAgua = (aguaSolo < ABSORCAO_AGUA) ? aguaSolo : ABSORCAO_AGUA;
    int absorvidaNutrientes = (nutrientesSolo < ABSORCAO_NUTRIENTES)
                              ? nutrientesSolo
                              : ABSORCAO_NUTRIENTES;

    solo.removerAgua(absorvidaAgua);
    solo.removerNutrientes(absorvidaNutrientes);

    agua += absorvidaAgua - PERDA_AGUA;
    nutrientes += absorvidaNutrientes - PERDA_NUTRIENTES;

    if (aguaSolo > MORRE_AGUA_MAIOR)
        instantesAguaAlta++;
    else
        instantesAguaAlta = 0;

    if (nutrientesSolo < MORRE_NUTRIENTES_MENOR)
        instantesNutrientesBaixos++;
    else
        instantesNutrientesBaixos = 0;

    if (instantesAguaAlta >= MORRE_AGUA_INSTANTES ||
        instantesNutrientesBaixos >= MORRE_NUTRIENTES_INSTANTES) {
        morrer(solo);
    }

}

bool Orquidia::querMultiplicar() const {
    return viva && agua > MULTIPLICA_AGUA_MAIOR && nutrientes > MULTIPLICA_NUTRIENTES_MAIOR;
}

void Orquidia::multiplicar() {
    agua = (agua * NOVA_AGUA_PERCENTAGEM) / 100;
    nutrientes = NOVA_NUTRIENTES;
}

void Orquidia::morrer(Solo& solo) {
    viva = false;
    solo.adicionarNutrientes(nutrientes / 2);
    solo.adicionarAgua(agua / 4);
    nutrientes = 0;
    agua = 0;

    cout << "Orquídea morreu em"<< (char)('A' + linha)<< (char)('A' + coluna)<< "\n";
}

std::string Orquidia::getNome() const{
    return "Orquidia";
}
