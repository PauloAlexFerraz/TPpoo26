#include "Planta.h"
#include "Cacto.h"
#include "Roseira.h"
#include "ErvaDaninha.h"
#include "Orquidia.h"
#include <iostream>

Planta::Planta(int l, int c, char simb)
    : linha(l), coluna(c), agua(0), nutrientes(0), viva(true), simbolo(simb) {}

Planta::~Planta() = default;

// Apenas placeholders — o comportamento real está nas subclasses
void Planta::atualizar(Solo& solo) {
    std::cout << "Atualizar() chamado na planta base — nenhuma ação.\n";
}

std::string Planta::getNome() const {
    return "Planta";
}

// Fábrica de plantas
Planta* Planta::criarPlanta(char tipo, int linha, int coluna) {
    switch (tipo) {
    case 'c': return new Cacto(linha, coluna);
    case 'r': return new Roseira(linha, coluna);
    case 'e': return new ErvaDaninha(linha, coluna);
    case 'x': return new Orquidia(linha, coluna);
    default:
        std::cout << "Tipo de planta desconhecido: " << tipo << std::endl;
        return nullptr;
    }
}
