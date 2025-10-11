//
// Created by shado on 11/10/2025.
//

#include "Solo.h"


Solo::Solo() {
    agua = 80 + rand() % 21;       // 80–100
    nutrientes = 40 + rand() % 11; // 40–50
}

int Solo::getAgua() const { return agua; }
int Solo::getNutrientes() const { return nutrientes; }

void Solo::adicionarAgua(int valor) { agua += valor; }
void Solo::adicionarNutrientes(int valor) { nutrientes += valor; }
void Solo::removerAgua(int valor) { agua = (agua - valor < 0) ? 0 : agua - valor; }
void Solo::removerNutrientes(int valor) { nutrientes = (nutrientes - valor < 0) ? 0 : nutrientes - valor; }
