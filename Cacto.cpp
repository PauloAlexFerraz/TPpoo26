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

    // Absorção de água e nutrientes
    int absorvidaAgua = (aguaSolo * 25) / 100; // 25%
    int absorvidaNutrientes = (nutrientesSolo < 5) ? nutrientesSolo : 5;

    // Retira do solo
    solo.removerAgua(absorvidaAgua);
    solo.removerNutrientes(absorvidaNutrientes);

    // Adiciona ao cacto
    agua += absorvidaAgua;
    nutrientes += absorvidaNutrientes;

    // Verificar condições fatais
    if (aguaSolo > 100)
        instantesAguaAlta++;
    else
        instantesAguaAlta = 0;

    if (nutrientesSolo <= 0)
        instantesNutrientesZero++;
    else
        instantesNutrientesZero = 0;

    if (instantesAguaAlta >= 3 || instantesNutrientesZero >= 3) {
        morrer(solo);
        return;
    }

    // Multiplicação (opcional, avisar o jardim)
    if (nutrientes > 100 && agua > 50) {
        cout << "🌵 Cacto ("
             << (char)('A' + linha)
             << (char)('A' + coluna)
             << ") quer multiplicar-se!\n";
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

