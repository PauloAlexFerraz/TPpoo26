#ifndef JARDINEIRO_H
#define JARDINEIRO_H

#include <string>
class Jardim;

class Jardineiro {
private:
    int linha;
    int coluna;
    bool dentro;
    Jardim* jardim;

    int movimentosTurno;
    int entradasNesteTurno;


public:
    explicit Jardineiro(Jardim* j);

    void entra(int l, int c);
    void sai();
    void mover(char direcao);
    void novoTurno();

    bool estaDentro() const { return dentro; }
    int getLinha() const { return linha; }
    int getColuna() const { return coluna; }
};

#endif
