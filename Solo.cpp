//
// Created by shado on 11/10/2025.
//

#include "Solo.h"


Solo::Solo() {
    agua = Settings::Jardim::agua_min + rand() % (Settings::Jardim::agua_max - Settings::Jardim::agua_min + 1);
    nutrientes = Settings::Jardim::nutrientes_min + rand() % (Settings::Jardim::nutrientes_max - Settings::Jardim::nutrientes_min + 1);
}

int Solo::getAgua() const { return agua; }
int Solo::getNutrientes() const { return nutrientes; }

void Solo::adicionarAgua(int valor) { agua += valor; }
void Solo::adicionarNutrientes(int valor) { nutrientes += valor; }
void Solo::removerAgua(int valor) { agua = (agua - valor < 0) ? 0 : agua - valor; }
void Solo::removerNutrientes(int valor) { nutrientes = (nutrientes - valor < 0) ? 0 : nutrientes - valor; }
