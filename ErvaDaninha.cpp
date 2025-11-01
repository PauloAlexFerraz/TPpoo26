#include "ErvaDaninha.h"
#include <iostream>
using namespace std;

ErvaDaninha::ErvaDaninha(int linha, int coluna)
    : Planta(linha, coluna, 'e') {
    agua = Settings::ErvaDaninha::inicial_agua;
    nutrientes = Settings::ErvaDaninha::inicial_nutrientes;
    instantesViva = 0;
    instantesDesdeUltimaMultiplicacao=0;
    quer_multiplicar=false;
}

void ErvaDaninha::atualizar(Solo& solo) {
    if (!viva)
        return;

    instantesViva++;
    instantesDesdeUltimaMultiplicacao++;
   // cout << "multi " << instantesDesdeUltimaMultiplicacao << endl;

    int aguaSolo = solo.getAgua();
    int nutrientesSolo = solo.getNutrientes();

    int absorvidaAgua = Settings::ErvaDaninha::absorcao_agua;
    int absorvidaNutrientes = (nutrientesSolo < Settings::ErvaDaninha::absorcao_nutrientes)
                              ? nutrientesSolo
                              : Settings::ErvaDaninha::absorcao_nutrientes;

    solo.removerAgua(absorvidaAgua);
    solo.removerNutrientes(absorvidaNutrientes);

    agua += absorvidaAgua;
    nutrientes += absorvidaNutrientes;

    if (instantesViva >= Settings::ErvaDaninha::morre_instantes) {
        morrer(solo);
        return;
    }

//cout << "nutrientes " << nutrientes << endl;
    if (nutrientes > 30 && instantesDesdeUltimaMultiplicacao >= 5) {
        quer_multiplicar = true;
        cout << "Erva daninha " << (char)('A' + linha)<< (char)('A' + coluna) << " quer multiplicar-se\n";
    }
}


bool ErvaDaninha::querMultiplicar() const {
    return quer_multiplicar;
}

void ErvaDaninha::multiplicar() {
    instantesDesdeUltimaMultiplicacao = 0;
    quer_multiplicar= false;
}

void ErvaDaninha::morrer(Solo& solo) {
    viva = false;
    solo.adicionarNutrientes(Settings::ErvaDaninha::nova_nutrientes);
    nutrientes = 0;
    agua = 0;

    cout << "Erva daninha morreu em "<< (char)('A' + linha)<< (char)('A' + coluna)<< "\n";
}

std::string ErvaDaninha::getNome() const{
    return "ErvaDaninha";
}
