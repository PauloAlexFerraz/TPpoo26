#include "Jardim.h"
#include "Planta.h"
#include "Jardineiro.h"
using namespace std;

Jardim::Jardim(int nLinhas, int nColunas)
    : linhas(nLinhas), colunas(nColunas), solos(nullptr), plantas(nullptr), jardineiro(nullptr)
{
    solos = new Solo*[linhas];
    for (int i = 0; i < linhas; ++i)
        solos[i] = new Solo[colunas];

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

            if (jardineiro && jardineiro->estaDentro() &&
                jardineiro->getLinha() == i &&
                jardineiro->getColuna() == j) {
                cout << '*';
                continue;
                }

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

bool Jardim::criarPlantaAdjacente(Planta* p) {
    if (!p || !p->estaViva()) return false;

    const int l = p->getLinha();
    const int c = p->getColuna();

    const int dl[4] = {-1, 1, 0, 0};
    const int dc[4] = { 0, 0,-1, 1};

    for (int k = 0; k < 4; ++k) {
        const int nl = l + dl[k];
        const int nc = c + dc[k];

        if (nl < 0 || nl >= linhas || nc < 0 || nc >= colunas)
            continue;

        if (getPlanta(nl, nc) == nullptr) {
            Planta* nova = Planta::criarPlanta(p->getSimbolo(), nl, nc);
            if (!nova) continue;

            if (adicionarPlanta(nl, nc, nova)) {
                std::cout << "Nova " << nova->getNome() << " criada em " << char('A'+nl) << char('A'+nc) << "\n";
                return true;
            }
        }
    }
    return false;
}

bool Jardim::removePlanta(int linha, int coluna) {
    int idx = linha * colunas + coluna;
    if (plantas[idx] == nullptr) return false;
    delete plantas[idx];
    plantas[idx] = nullptr;
    return true;
}

Planta* Jardim::getPlanta(int linha, int coluna) const {
    return plantas[linha * colunas + coluna];
}

Solo& Jardim::getSolo(int linha, int coluna) {
    return solos[linha][coluna];
}

void Jardim::listarArea() const {
    cout << "\nInformacao do Solo\n";
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cout << numeroParaLetra(i) << numeroParaLetra(j)
                 << " agua: " << solos[i][j].getAgua() << " Nutrientes: " << solos[i][j].getNutrientes() << endl;
        }
    }
}

void Jardim::listarSolo(int lin, int col, int raio) const {
    cout << "\nInformacao do Solo ( com raio " << raio << ")\n";
    int linInicio = max(0, lin - raio);
    int linFim = min(linhas - 1, lin + raio);
    int colInicio = max(0, col - raio);
    int colFim = min(colunas - 1, col + raio);

    for (int i = linInicio; i <= linFim; ++i) {
        for (int j = colInicio; j <= colFim; ++j) {
            const Solo& s = solos[i][j];
            Planta* p = plantas[i * colunas + j];

            cout << numeroParaLetra(i) << numeroParaLetra(j)
                 << " agua: " << s.getAgua() << ", Nutrientes: " << s.getNutrientes();

            if (p)
                cout << " Planta: " << p->getNome() << endl;
            else
                cout << "vazio";
            cout << endl;
        }
    }
}
