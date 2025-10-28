#include "Jardineiro.h"
#include "Jardim.h"
#include <iostream>
using namespace std;

Jardineiro::Jardineiro(Jardim* j)
    : linha(-1), coluna(-1), dentro(false), jardim(j),
      movimentosTurno(0), entrouNesteTurno(false), saiuNesteTurno(false) {}

void Jardineiro::entra(int l, int c) {
    if (!jardim) {
        cout << "[ERRO] Jardineiro não tem jardim associado.\n";
        return;
    }

    if (entrouNesteTurno) {
        cout << "O jardineiro já entrou neste turno.\n";
        return;
    }

    if (l < 0 || l >= jardim->getNumLinhas() ||
        c < 0 || c >= jardim->getNumColunas()) {
        cout << "Posição inválida para o jardineiro.\n";
        return;
    }

    linha = l;
    coluna = c;
    dentro = true;
    entrouNesteTurno = true;
    saiuNesteTurno = false;

    cout << "Jardineiro entrou em "
         << (char)('A' + l) << (char)('A' + c) << ".\n";
}

void Jardineiro::sai() {
    if (!dentro) {
        cout << "O jardineiro já está fora do jardim.\n";
        return;
    }
    if (saiuNesteTurno) {
        cout << "O jardineiro já saiu neste turno.\n";
        return;
    }

    dentro = false;
    saiuNesteTurno = true;
    cout << "O jardineiro saiu do jardim.\n";
}

void Jardineiro::mover(char direcao) {
    if (!dentro) {
        cout << "O jardineiro está fora do jardim.\n";
        return;
    }
    if (movimentosTurno >= 10) {
        cout << "O jardineiro já se moveu 10 vezes neste turno.\n";
        return;
    }

    int novaLinha = linha;
    int novaColuna = coluna;

    switch (tolower(direcao)) {
        case 'c': novaLinha--; break;
        case 'b': novaLinha++; break;
        case 'e': novaColuna--; break;
        case 'd': novaColuna++; break;
        default:
            cout << "Direção inválida. Use c, b, e ou d.\n";
            return;
    }

    if (novaLinha < 0 || novaLinha >= jardim->getNumLinhas() ||
        novaColuna < 0 || novaColuna >= jardim->getNumColunas()) {
        cout << "O jardineiro não pode sair assim. Use 'sai' para sair.\n";
        return;
    }

    linha = novaLinha;
    coluna = novaColuna;
    movimentosTurno++;

    cout << "Jardineiro moveu-se para "
         << (char)('A' + linha) << (char)('A' + coluna)
         << " (" << movimentosTurno << "/10 movimentos).\n";
}

void Jardineiro::novoTurno() {
    movimentosTurno = 0;
    entrouNesteTurno = false;
    saiuNesteTurno = false;
}
