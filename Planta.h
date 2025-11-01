#ifndef PLANTA_H
#define PLANTA_H

#include "Solo.h"
#include <string>

class Jardim;

class Planta {
protected:
    int linha;
    int coluna;
    int agua;
    int nutrientes;
    bool viva;
    char simbolo;
    std::string atributo;


public:
    Planta(int l, int c, char simb);
    ~Planta();

    virtual void atualizar(Solo& solo)=0;
    virtual bool querMultiplicar() const { return false; }
    virtual void multiplicar() {}
    virtual void morrer(Solo& solo)=0;
    virtual std::string getNome() const=0;




    bool estaViva() const { return viva; }
    char getSimbolo() const { return simbolo; }
    int getLinha() const { return linha; }
    int getColuna() const { return coluna; }

    static Planta* criarPlanta(char tipo, int linha, int coluna);
};

#endif