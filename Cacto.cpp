#include "Cacto.h"
#include <iostream>
using namespace std;

Cacto::Cacto(int linha, int coluna)
    : Planta(linha, coluna, 'c') {
    agua = 0;
    nutrientes = 0;
    instantesAguaAlta = 0;
    instantesNutrientesZero = 0;
}

void Cacto::atualizar(Solo& solo) {
    if (!viva)
        return;


    int aguaSolo = solo.getAgua();
    int nutrientesSolo = solo.getNutrientes();

    // Verificar condições fatais antes de alterar o solo
    if (aguaSolo > Settings::Cacto::morre_agua_solo_maior)
        instantesAguaAlta++;
    else
        instantesAguaAlta = 0;


    if (nutrientesSolo < Settings::Cacto::morre_nutrientes_solo_menor)
        instantesNutrientesZero++;
    else
        instantesNutrientesZero = 0;

    if (instantesAguaAlta >= Settings::Cacto::morre_agua_solo_instantes ||
        instantesNutrientesZero >= Settings::Cacto::morre_nutrientes_solo_instantes) {
        morrer(solo);
        return;
        }

    // Absorção de água e nutrientes conforme Settings
    int absorvidaAgua = (aguaSolo * Settings::Cacto::absorcao_agua_percentagem-1) / 100;
    int absorvidaNutrientes = (nutrientesSolo < Settings::Cacto::absorcao_nutrientes)
                              ? nutrientesSolo
                              : Settings::Cacto::absorcao_nutrientes;

    // Retira do solo
    solo.removerAgua(absorvidaAgua);
    solo.removerNutrientes(absorvidaNutrientes);

    // Adiciona ao cacto
    agua += absorvidaAgua;
    nutrientes += absorvidaNutrientes;



    // Multiplicação (condições ideais)
    if (nutrientes > Settings::Cacto::multiplica_nutrientes_maior &&
        agua > Settings::Cacto::multiplica_agua_maior) {

        cout << "Cacto (" << (char)('A' + linha)
             << (char)('A' + coluna)
             << ") quer multiplicar-se!\n";

        // Gasta metade dos recursos na multiplicação
        nutrientes /= 2;
        agua /= 2;

    }
}

void Cacto::morrer(Solo& solo) {
    viva = false;
    solo.adicionarNutrientes(nutrientes);
    nutrientes = 0;
    agua = 0;

    cout << "Cacto morreu em ("
         << (char)('A' + linha)
         << (char)('A' + coluna)
         << ")\n";
}

std::string Cacto::getNome() const {
    return "Cacto";
}
