#include "ErvaDaninha.h"
#include <iostream>
using namespace std;

ErvaDaninha::ErvaDaninha(int linha, int coluna)
    : Planta(linha, coluna, 'e') {
    agua = Settings::ErvaDaninha::inicial_agua;
    nutrientes = Settings::ErvaDaninha::inicial_nutrientes;
    instantesViva = 0;
}

void ErvaDaninha::atualizar(Solo& solo) {
    if (!viva)
        return;

    instantesViva++;

    int aguaSolo = solo.getAgua();
    int nutrientesSolo = solo.getNutrientes();

    // Absorção mínima (é resistente e pouco exigente)
    int absorvidaAgua = Settings::ErvaDaninha::absorcao_agua;
    int absorvidaNutrientes = (nutrientesSolo < Settings::ErvaDaninha::absorcao_nutrientes)
                              ? nutrientesSolo
                              : Settings::ErvaDaninha::absorcao_nutrientes;

    // Retira do solo
    solo.removerAgua(absorvidaAgua);
    solo.removerNutrientes(absorvidaNutrientes);

    // Adiciona à erva daninha
    agua += absorvidaAgua;
    nutrientes += absorvidaNutrientes;

    // Morte natural após certo tempo
    if (instantesViva >= Settings::ErvaDaninha::morre_instantes) {
        morrer(solo);
        return;
    }

    // Multiplicação (espalha-se facilmente)
    if (nutrientes > Settings::ErvaDaninha::multiplica_nutrientes_maior &&
        instantesViva % Settings::ErvaDaninha::multiplica_instantes == 0) {

        cout << "Erva daninha ("
             << (char)('A' + linha)
             << (char)('A' + coluna)
             << ") espalhou-se!\n";

        // Usa parte dos nutrientes para criar uma nova
        nutrientes = Settings::ErvaDaninha::original_nutrientes;
        // Aqui poderias notificar o Jardim para criar outra ErvaDaninha
        // Ex: jardim->adicionarPlanta(new ErvaDaninha(...));
    }
}

void ErvaDaninha::morrer(Solo& solo) {
    viva = false;
    solo.adicionarNutrientes(Settings::ErvaDaninha::nova_nutrientes);
    nutrientes = 0;
    agua = 0;

    cout << "Erva daninha morreu em ("
         << (char)('A' + linha)
         << (char)('A' + coluna)
         << ")\n";
}

std::string ErvaDaninha::getNome() const {
    return "ErvaDaninha";
}
