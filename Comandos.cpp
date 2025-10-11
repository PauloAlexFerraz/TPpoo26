//
// Created by shado on 11/10/2025.
//

#include "Comandos.h"
#include <iostream>
#include <sstream>

#include "Cacto.h"
using namespace std;

Comandos::Comandos() : jardim(nullptr) {}

Comandos::~Comandos() { //destrutor
    delete jardim;
}


void Comandos::cicloPrincipal() { // ciclo comandos
    cout << "Simulador de Jardim ( 'terminar' para sair)\n";
    cout << "Escreve comando 'Jardim 6 13' sendo que o 6 e 13 sao dimensoes escolhidas\n";

    string linha;
    while (true) {
        cout << "> ";
        getline(cin, linha);
        interpretar(linha);
    }
}

void Comandos::interpretar(const string& linha) { // le os comandos
    stringstream ss(linha);
    string comando;
    ss >> comando;

    if (comando.empty())
        return;

    if (comando == "jardim") { // criar jardim com dimensoes
        int linhas, colunas;

        if (ss >> linhas >> colunas) {
            if (jardim == nullptr) {
                if (linhas > 0 && linhas <= 26 && colunas > 0 && colunas <= 26) {
                    jardim = new Jardim(linhas, colunas);
                    cout << "Jardim criado com " << linhas
                         << " linhas e " << colunas << " colunas.\n";
                    jardim->imprimir();
                } else {
                    cout << "Erro: o tamanho maximo do jardim é 26x26.\n";
                }
            } else {
                cout << "Erro: o jardim ja foi criado.\n";
            }
        } else {
            cout << "Uso: jardim <linhas> <colunas>\n";
        }
    }

    else if (comando == "mostrar") { // para mostrar o jardim
        if (jardim == nullptr) {
            cout << "jardim ainda nao foi criado. Usa 'jardim <linhas> <colunas>' primeiro.\n";
        } else {
            jardim->imprimir();
        }
    }

    else if (comando == "larea") {
        if (jardim == nullptr) {
            cout << "Ainda não existe jardim. Crie-o com 'jardim <linhas> <colunas>'.\n";
        } else {
            jardim->listarArea();
        }
    }


    else if (comando == "terminar") { // terminar
        cout << "A terminar o simulador...\n";
        exit(0);
    }

    else if (comando == "planta") {
        int lin, col;
        char tipo;

        if (ss >> lin >> col >> tipo) {
            if (jardim == nullptr) {
                cout << "Ainda não existe jardim. Crie-o primeiro.\n";
                return;
            }

            if (lin >= 0 && lin < 26 && col >= 0 && col < 26) {
                if (tipo == 'c') {
                    Cacto* nova = new Cacto(lin, col);
                   // jardim->adicionarPlanta(nova); // <-- precisa implementar este método no Jardim
                    cout << "Cacto plantado na posição (" << lin << "," << col << ").\n";
                } else {
                    cout << "Tipo de planta desconhecido.\n";
                }
            } else {
                cout << "Posição inválida. Use valores entre 0 e 25.\n";
            }
        } else {
            cout << "Uso: planta <linha> <coluna> <tipo>\n";
        }
    }


    else { // erro
        cout << "Comando desconhecido: " << comando << endl;
    }
}


