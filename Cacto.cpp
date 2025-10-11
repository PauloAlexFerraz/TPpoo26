#include "Cacto.h"
#include <iostream>
using namespace std;

Cacto::Cacto(int linha, int coluna)
    : Planta(linha, coluna, 'c')
{
    agua = 0;
    nutrientes = 0;
}

void Cacto::atualizar(Solo& solo) {
    if (!viva)
        return;

    // ⚙️ Copiar valores do Settings (não podes usar diretamente)
    const int absorcaoAguaPercentagem = 25;
    const int absorcaoNutrientes = 5;
    const int morreAguaSoloMaior = 100;
    const int morreAguaSoloInstantes = 3;
    const int morreNutrientesSoloInstantes = 3;

    // --- Absorção de água ---
    int absorvidaAgua = (solo.getAgua() * absorcaoAguaPercentagem) / 100;
    agua += absorvidaAgua;
    solo.removerAgua(absorvidaAgua);

    // --- Absorção de nutrientes ---
    int disponivel = solo.getNutrientes();
    int absorvidaNutrientes = absorcaoNutrientes;
    if (absorvidaNutrientes > disponivel)
        absorvidaNutrientes = disponivel;

    nutrientes += absorvidaNutrientes;
    solo.removerNutrientes(absorvidaNutrientes);

    // --- Verifica condições de morte ---
    if (solo.getAgua() > morreAguaSoloMaior)
        instantesAguaAlta++;
    else
        instantesAguaAlta = 0;

    if (solo.getNutrientes() <= 0)
        instantesNutrientesZero++;
    else
        instantesNutrientesZero = 0;

    if (instantesAguaAlta >= morreAguaSoloInstantes ||
        instantesNutrientesZero >= morreNutrientesSoloInstantes) {
        viva = false;
        cout << "O cacto em "
             << (char)('A' + linha)
             << (char)('A' + coluna)
             << " morreu.\n";
        }
}

string Cacto::getNome() const {
    return "Cacto";
}
