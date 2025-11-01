//
// Created by shado on 11/10/2025.
//

#include "Comandos.h"
#include <iostream>
#include <sstream>




#include "Planta.h"
#include "Jardineiro.h"

using namespace std;

Comandos::Comandos()
    : jardim(nullptr), jardineiro(nullptr)
{}

Comandos::~Comandos() { //destrutor
    delete jardim;
}


void Comandos::cicloPrincipal() { // ciclo comandos
    cout << "Jardim ( 'fim' para sair)\n";
    cout << "Escrever por exemplo comando 'Jardim 6 13' sendo que o 6 e 13 sao dimensoes escolhidas\n";

    string linha;
    while (true) {
        cout << "Comando: ";
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

    if (comando == "jardim") {
        int linhas, colunas;

        if (ss >> linhas >> colunas) {
            if (jardim == nullptr) {
                if (linhas > 0 && linhas <= 26 && colunas > 0 && colunas <= 26) {
                    jardim = new Jardim(linhas, colunas);
                    cout << "Jardim criado com " << linhas << " linhas e " << colunas << " colunas.\n";
                    jardim->imprimir();
                } else {
                    cout << "Erro: o tamanho maximo do jardim é 26x26.\n";
                }
            } else {
                cout << "Erro: o jardim ja foi criado.\n";
            }
        } else {
            cout << "Usa: jardim <linhas> <colunas>\n";
        }
    }

    else if (comando == "mostrar") {
        if (jardim == nullptr) {
            cout << "ainda nao existe jardim\n";
        } else {
            jardim->imprimir();
        }
    }

    else if (comando == "avanca") {
        if (jardim == nullptr) {
            cout << "Ainda nao existe jardim\n";
            return;
        }

        cout << "A avancar 1 turno...\n";

        for (int i = 0; i < jardim->getNumLinhas(); ++i) {
            for (int j = 0; j < jardim->getNumColunas(); ++j) {
                Planta* p = jardim->getPlanta(i, j);
                if (p != nullptr && p->estaViva()) {
                    Solo& solo = jardim->getSolo(i, j);
                    p->atualizar(solo);
                    if (!p->estaViva())
                    {
                        jardim->removePlanta(i,j);
                    }
                    if(p->querMultiplicar())
                    {
                        p->multiplicar();
                        jardim->criarPlantaAdjacente(p);
                    }
                }
            }
        }

        if (jardineiro)
            jardineiro->novoTurno();

        jardim->imprimir();
    }


    else if (comando == "larea") {
        if (jardim == nullptr) {
            cout << "Ainda nao existe jardim\n";
        } else {
            jardim->listarArea();
        }
    }

    else if (comando == "lsolo") {
        if (jardim == nullptr) {
            cout << "Ainda nao existe jardim.\n";
            return;
        }

        string pos;
        int raio = 0;
        if (!(ss >> pos)) {
            cout << "Usa: lsolo <posicao> raio\n";
            return;
        }

        ss >> raio;

        if (pos.size() != 2) {
            cout << "Posicao invalida\n";
            return;
        }

        int lin = tolower(pos[0]) - 'a';
        int col = tolower(pos[1]) - 'a';

        if (lin < 0 || lin >= jardim->getNumLinhas() ||
            col < 0 || col >= jardim->getNumColunas()) {
            cout << "Posicao fora dos limites do jardim.\n";
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
            if (!jardim) {
                cout << "Ainda nao existe jardim\n";
                return;
            }

            if (pos.size() != 2) {
                cout << "Posicao invalida ex(bc)\n";
                return;
            }

            int lin = tolower(pos[0]) - 'a';
            int col = tolower(pos[1]) - 'a';

            if (lin < 0 || lin >= jardim->getNumLinhas() || col < 0 || col >= jardim->getNumColunas()) {
                cout << "Posicao fora dos limites do jardim\n";
                return;
            }

            Planta* nova = Planta::criarPlanta(tipo, lin, col);
            if (!nova) {
                cout << "Tipo de planta desconhecida\n";
                return;
            }

            if (jardim->adicionarPlanta(lin, col, nova)) {
                cout << "Planta " << nova->getNome() << " colocada em " << pos << ".\n";
                jardim->imprimir();
            } else {
                cout << "Posicao ocupada\n";
                delete nova;
            }
        } else {
            cout << "Usa planta posicao tipo\n";
        }
    }



    else if (comando == "entra") {
        string pos;
        if (!(ss >> pos) || pos.size() != 2) {
            cout << "Usa entra posicao\n";
            return;
        }
        if (!jardim) { cout << "Crie o jardim primeiro.\n"; return; }

        int lin = tolower(pos[0]) - 'a';
        int col = tolower(pos[1]) - 'a';

        if (!jardineiro) {
            jardineiro = new Jardineiro(jardim);
            jardim->setJardineiro(jardineiro);
        }

        jardineiro->entra(lin, col);
        jardim->imprimir();
    }

    else if (comando == "sai") {
        if (!jardineiro) { cout << "O jardineiro nao esta dentro do jardim\n"; return; }
        jardineiro->sai();
        jardim->imprimir();
    }


    else if (comando == "c" || comando == "b" || comando == "e" || comando == "d") {
        if (!jardineiro) { cout << "O jardineiro nao esta dentro do jardim\n"; return; }
        jardineiro->mover(comando[0]);
        jardim->imprimir();
    }


    else if (comando == "adubo") {
        if (jardim == nullptr) { cout << "Cria o jardim primeiro\n"; return; }
        string pos;
        if (!(ss >> pos)) { cout << "Uso: adubo <posição>\n"; return; }
        if (pos.size() != 2) { cout << "Formato inválido, ex: bc\n"; return; }

        int lin = tolower(pos[0]) - 'a';
        int col = tolower(pos[1]) - 'a';
        if (lin < 0 || lin >= jardim->getNumLinhas() || col < 0 || col >= jardim->getNumColunas()) {
            cout << "Posicao fora dos limites.\n"; return;
        }

        pacote.aplicar(jardim->getSolo(lin, col));
    }





    else {
        cout << "Comando desconhecido: " << comando << endl;
    }
}


