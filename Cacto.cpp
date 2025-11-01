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

    int absorvidaAgua = (aguaSolo * Settings::Cacto::absorcao_agua_percentagem) / 100;
    int absorvidaNutrientes = (nutrientesSolo < Settings::Cacto::absorcao_nutrientes)
                              ? nutrientesSolo
                              : Settings::Cacto::absorcao_nutrientes;

    solo.removerAgua(absorvidaAgua);
    solo.removerNutrientes(absorvidaNutrientes);

    agua += absorvidaAgua;
    nutrientes += absorvidaNutrientes;
}

bool Cacto::querMultiplicar() const {
//cout<<"queromultiplicar"<<endl;
    return (nutrientes > Settings::Cacto::multiplica_nutrientes_maior &&
            agua > Settings::Cacto::multiplica_agua_maior);
}

void Cacto::multiplicar() {
    nutrientes /=2;
    agua /=2;
    cout << "Cacto " << char('A' + linha) << char('A' + coluna) << " multiplicou-se!\n";
}

void Cacto::morrer(Solo& solo) {
    viva = false;
    solo.adicionarNutrientes(nutrientes);
    nutrientes = 0;
    agua = 0;

    cout << "Cacto morreu em "<< (char)('A' + linha)<< (char)('A' + coluna)<< "\n";
}

std::string Cacto::getNome() const {
    return "Cacto";
}
