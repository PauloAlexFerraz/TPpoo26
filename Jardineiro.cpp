#include "Jardineiro.h"
#include "Jardim.h"
#include <iostream>
using namespace std;

Jardineiro::Jardineiro(Jardim* j)
    : linha(-1), coluna(-1), dentro(false), jardim(j),
      movimentosTurno(0), entradasNesteTurno(0) {}

void Jardineiro::entra(int l, int c) {
    if (!jardim) {
        cout << "erro nao ha jardim\n";
        return;
    }
    if (entradasNesteTurno >= Settings::Jardineiro::max_entradas_saidas) {
        cout << "O jardineiro ja entrou ou saiu neste turno.\n";
        return;
    }
    if (l < 0 || l >= jardim->getNumLinhas() ||
        c < 0 || c >= jardim->getNumColunas()) {
        cout << "Posição invalida\n";
        return;
    }

    linha = l;
    coluna = c;
    dentro = true;
    entradasNesteTurno++;

    cout << "Jardineiro entrou em "
         << (char)('A' + l) << (char)('A' + c) << ".\n";
}

void Jardineiro::sai() {
    if (!dentro) {
        cout << "O jardineiro esta fora do jardim\n";
        return;
    }
    if (entradasNesteTurno >= Settings::Jardineiro::max_entradas_saidas) {
        cout << "O jardineiro já entrou ou saiu neste turno\n";
        return;
    }

    dentro = false;
    entradasNesteTurno++;
    cout << "Jardineiro saiu do jardim.\n";
}

void Jardineiro::mover(char direcao) {
    if (!dentro) {
        cout << "O jardineiro está fora do jardim.\n";
        return;
    }
    if (movimentosTurno >= Settings::Jardineiro::max_movimentos) {
        cout << "O jardineiro já fez o máximo de movimentos neste turno.\n";
        return;
    }

    int novaLinha = linha;
    int novaColuna = coluna;

    switch (tolower(direcao)) {
        case 'c': novaLinha--; break; // cima
        case 'b': novaLinha++; break; // baixo
        case 'e': novaColuna--; break; // esquerda
        case 'd': novaColuna++; break; // direita
        default:
            cout << "Direção invalida (usa c b e d).\n";
            return;
    }

    if (novaLinha < 0 || novaLinha >= jardim->getNumLinhas() ||
        novaColuna < 0 || novaColuna >= jardim->getNumColunas()) {
        cout << "movimento fora do jardim Usa 'sai'.\n";
        return;
    }

    linha = novaLinha;
    coluna = novaColuna;
    movimentosTurno++;

    cout << "Jardineiro moveu-se para "
         << (char)('A' + linha) << (char)('A' + coluna)
         << " (" << movimentosTurno << "/" << Settings::Jardineiro::max_movimentos << " movimentos).\n";
}

void Jardineiro::novoTurno() {
    movimentosTurno = 0;
    entradasNesteTurno = 0;
}
