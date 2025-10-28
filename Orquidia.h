#ifndef ORQUIDIA_H
#define ORQUIDIA_H

#include "Planta.h"
#include "Solo.h"
#include <string>

class Orquidia : public Planta {
private:
    int instantesViva;
    int instantesAguaAlta;
    int instantesNutrientesBaixos;

    // Constantes específicas da Orquídea
    static const int ABSORCAO_AGUA;
    static const int ABSORCAO_NUTRIENTES;
    static const int PERDA_AGUA;
    static const int PERDA_NUTRIENTES;
    static const int MORRE_AGUA_MAIOR;
    static const int MORRE_AGUA_INSTANTES;
    static const int MORRE_NUTRIENTES_MENOR;
    static const int MORRE_NUTRIENTES_INSTANTES;
    static const int MULTIPLICA_AGUA_MAIOR;
    static const int MULTIPLICA_NUTRIENTES_MAIOR;
    static const int NOVA_AGUA_PERCENTAGEM;
    static const int NOVA_NUTRIENTES;

public:
    Orquidia(int linha, int coluna);

    void atualizar(Solo& solo);
    void morrer(Solo& solo);
    std::string getNome() const override;
};

#endif
