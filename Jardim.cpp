#include "Jardim.h"
#include "Planta.h"
#include "Jardineiro.h"
using namespace std;

Jardim::Jardim(int nLinhas, int nColunas)
    : linhas(nLinhas), colunas(nColunas), solos(nullptr), plantas(nullptr), jardineiro(nullptr)
{
    // Aloca solos
    solos = new Solo*[linhas];
    for (int i = 0; i < linhas; ++i)
        solos[i] = new Solo[colunas];

    // Aloca plantas
    plantas = new Planta*[linhas * colunas];
    for (int i = 0; i < linhas * colunas; ++i)
        plantas[i] = nullptr;
}

Jardim::~Jardim() {
    for (int i = 0; i < linhas * colunas; ++i)
        delete plantas[i];

    for (int i = 0; i < linhas; ++i)
        delete[] solos[i];

    delete[] solos;
    delete[] plantas;
}

char Jardim::numeroParaLetra(int n) const {
    return 'A' + n;
}

void Jardim::imprimir() const {
    cout << "  ";
    for (int j = 0; j < colunas; ++j)
        cout << numeroParaLetra(j);
    cout << endl;

    for (int i = 0; i < linhas; ++i) {
        cout << numeroParaLetra(i) << " ";
        for (int j = 0; j < colunas; ++j) {

            // ✅ se o jardineiro estiver aqui, mostra '*'
            if (jardineiro && jardineiro->estaDentro() &&
                jardineiro->getLinha() == i &&
                jardineiro->getColuna() == j) {
                cout << '*';
                continue;
                }

            // mantém a tua lógica original
            Planta* p = plantas[i * colunas + j];
            cout << (p ? p->getSimbolo() : ' ');
        }
        cout << endl;
    }
}

bool Jardim::adicionarPlanta(int linha, int coluna, Planta* p) {
    int idx = linha * colunas + coluna;
    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas)
        return false;
    if (plantas[idx] != nullptr)
        return false;

    plantas[idx] = p;
    return true;
}

Planta* Jardim::getPlanta(int linha, int coluna) const {
    return plantas[linha * colunas + coluna];
}

Solo& Jardim::getSolo(int linha, int coluna) {
    return solos[linha][coluna];
}

void Jardim::listarArea() const {
    cout << "\n--- Informação do Solo ---\n";
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cout << numeroParaLetra(i) << numeroParaLetra(j)
                 << " -> Água: " << solos[i][j].getAgua()
                 << ", Nutrientes: " << solos[i][j].getNutrientes() << endl;
        }
    }
    cout << "-----------------------------------\n";
}

void Jardim::listarSolo(int lin, int col, int raio) const {
    cout << "\n--- Informação do Solo (raio " << raio << ") ---\n";
    int linInicio = max(0, lin - raio);
    int linFim = min(linhas - 1, lin + raio);
    int colInicio = max(0, col - raio);
    int colFim = min(colunas - 1, col + raio);

    for (int i = linInicio; i <= linFim; ++i) {
        for (int j = colInicio; j <= colFim; ++j) {
            const Solo& s = solos[i][j];
            Planta* p = plantas[i * colunas + j];

            cout << numeroParaLetra(i) << numeroParaLetra(j)
                 << " -> Água: " << s.getAgua()
                 << ", Nutrientes: " << s.getNutrientes();

            if (p)
                cout << " | Planta: " << p->getNome() << (p->estaViva() ? " (viva)" : " (morta)");
            else
                cout << " | [vazio]";
            cout << endl;
        }
    }
    cout << "-----------------------------------\n";
}
