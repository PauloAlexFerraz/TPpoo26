#include "Jardineiro.h"
#include "Jardim.h"
#include <iostream>
using namespace std;

Jardineiro::Jardineiro(Jardim* j)
    : linha(-1), coluna(-1), dentro(false), jardim(j),
      movimentosTurno(0), entradasNesteTurno(0) {}

void Jardineiro::entra(int l, int c) {
    if (!jardim) {
        cerr << "erro nao ha jardim\n";
        return;
    }
    if (entradasNesteTurno >= Settings::Jardineiro::max_entradas_saidas) {
        cout << "O jardineiro ja entrou ou saiu neste turno\n";
        return;
    }
    if (l < 0 || l >= jardim->getNumLinhas() ||
        c < 0 || c >= jardim->getNumColunas()) {
        cout << "Posicao invalida\n";
        return;
    }

    linha = l;
    coluna = c;
    dentro = true;
    entradasNesteTurno++;

    cout << "Jardineiro entrou em "<< (char)('A' + l) << (char)('A' + c) << "\n";
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
    cout << "Jardineiro saiu do jardim\n";
}

void Jardineiro::mover(char direcao) {
    if (!dentro) {
        cout << "O jardineiro esta fora do jardim\n";
        return;
    }
    if (movimentosTurno >= Settings::Jardineiro::max_movimentos) {
        cout << "O jardineiro nao se pode movimentar mais este turno\n";
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
            cout << "Direcao invalida (usa c b e d).\n";
            return;
    }

    if (novaLinha < 0 || novaLinha >= jardim->getNumLinhas() ||
        novaColuna < 0 || novaColuna >= jardim->getNumColunas()) {
        cout << "Movimento fora do jardim Usa 'sai' para sair\n";
        return;
    }

    linha = novaLinha;
    coluna = novaColuna;
    movimentosTurno++;

    cout << "Jardineiro moveu-se para "<< (char)('A' + linha) << (char)('A' + coluna)
    << "\n" << movimentosTurno << "/" << Settings::Jardineiro::max_movimentos << " movimentos restantes\n";
}

void Jardineiro::novoTurno() {
    movimentosTurno = 0;
    entradasNesteTurno = 0;
}
