//
// Created by shado on 11/10/2025.
//

#include "Comandos.h"
#include <iostream>
#include <sstream>

#include "Cacto.h"
#include "ErvaDaninha.h"
#include "Orquidia.h"
#include "Roseira.h"

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

    else if (comando == "avanca") {
        if (jardim == nullptr) {
            cout << "Ainda não existe jardim.\n";
            return;
        }

        cout << "A avancar 1 turno...\n";

        // percorre todo o jardim
        for (int i = 0; i < jardim->getNumLinhas(); ++i) {
            for (int j = 0; j < jardim->getNumColunas(); ++j) {
                Planta* p = jardim->getPlanta(i, j);
                if (p != nullptr && p->estaViva()) {
                    Solo& solo = jardim->getSolo(i, j);
                    p->atualizar(solo);
                }
            }
        }

        jardim->imprimir();
    }




    else if (comando == "larea") {
        if (jardim == nullptr) {
            cout << "Ainda não existe jardim. Crie-o com 'jardim <linhas> <colunas>'.\n";
        } else {
            jardim->listarArea();
        }
    }

    else if (comando == "lsolo") {
        if (jardim == nullptr) {
            cout << "Ainda não existe jardim. Crie-o com 'jardim <linhas> <colunas>'.\n";
            return;
        }

        string pos;
        int raio = 0;
        if (!(ss >> pos)) {
            cout << "Uso: lsolo <posição> [raio]\n";
            return;
        }

        ss >> raio;

        if (pos.size() != 2) {
            cout << "Posição inválida. Usa formato <letra><letra> (ex: df).\n";
            return;
        }

        int lin = tolower(pos[0]) - 'a';
        int col = tolower(pos[1]) - 'a';

        if (lin < 0 || lin >= jardim->getNumLinhas() ||
            col < 0 || col >= jardim->getNumColunas()) {
            cout << "Posição fora dos limites do jardim.\n";
            return;
            }

        jardim->listarSolo(lin, col, raio);
    }


    else if (comando == "fim") { // terminar
        cout << "A terminar o simulador...\n";
        exit(0);
    }

    else if (comando == "planta") {
        string pos;
        char tipo;

        if (ss >> pos >> tipo) {
            if (jardim == nullptr) {
                cout << "Ainda não existe jardim. Crie-o primeiro.\n";
                return;
            }

            if (pos.size() != 2) {
                cout << "Posição inválida. Usa formato <letra><letra> (ex: bc).\n";
                return;
            }

            int lin = tolower(pos[0]) - 'a';
            int col = tolower(pos[1]) - 'a';

            if (lin < 0 || lin >= jardim->getNumLinhas() || col < 0 || col >= jardim->getNumColunas()) {
                cout << "Posição fora dos limites do jardim.\n";
                return;
            }

            Planta* nova = nullptr;

            if (tipo == 'c') {
                nova = new Cacto(lin, col);
            }else if (tipo == 'r')
            {
                nova = new Roseira(lin, col);
            } else if (tipo =='e')
            {
                nova = new ErvaDaninha(lin,col);
            } else if (tipo == 'x')
            {
                nova = new Orquidia(lin, col);
            }
            else {
                cout << "Tipo de planta desconhecido.\n";
                return;
            }

            if (jardim->adicionarPlanta(lin, col, nova)) {
                cout << "Planta " << nova->getNome()
                     << " colocada em " << pos << ".\n";
                jardim->imprimir();  // redesenha o mapa
            } else {
                cout << "Já existe uma planta nessa posição.\n";
                delete nova;
            }
        } else {
            cout << "Uso: planta <posição> <tipo>\n";
        }
    }

    else if (comando == "adubo") {
        if (jardim == nullptr) { cout << "Crie o jardim primeiro.\n"; return; }
        string pos;
        if (!(ss >> pos)) { cout << "Uso: adubo <posição>\n"; return; }
        if (pos.size() != 2) { cout << "Formato inválido, ex: bc\n"; return; }

        int lin = tolower(pos[0]) - 'a';
        int col = tolower(pos[1]) - 'a';
        if (lin < 0 || lin >= jardim->getNumLinhas() || col < 0 || col >= jardim->getNumColunas()) {
            cout << "Posição fora dos limites.\n"; return;
        }

        pacote.aplicar(jardim->getSolo(lin, col));
    }





    else { // erro
        cout << "Comando desconhecido: " << comando << endl;
    }
}


