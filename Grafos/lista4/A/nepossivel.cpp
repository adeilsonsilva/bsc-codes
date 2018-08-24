#include <iostream>

using namespace std;

#define LIMITE_ESTACOES 100
#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define CONECTADO true
#define DESCONECTADO false

bool estaoConectadas(int cor[], int estacoes);
void inicializar(bool matrizDeAdjacencia[][LIMITE_ESTACOES], int cor[], int estacoes);
void buscaEmProfundidade(bool matrizDeAdjacencia[][LIMITE_ESTACOES], int cor[], int estacoes, int estacao);

int main() {
    int estacoes, linhasDeTransmissao;
    bool matrizDeAdjacencia[LIMITE_ESTACOES][LIMITE_ESTACOES];
    int cor[LIMITE_ESTACOES];
    int u, v;
    int teste = 0;
    do {
        cin >> estacoes >> linhasDeTransmissao;
        if(estacoes != 0 || linhasDeTransmissao != 0) {
            inicializar(matrizDeAdjacencia, cor, estacoes);
            for(int i = 0; i < linhasDeTransmissao; i++) {
                cin >> u >> v;
                matrizDeAdjacencia[u - 1][v - 1] = CONECTADO;
                matrizDeAdjacencia[v - 1][u - 1] = CONECTADO;
            }
            // Se comecar da primeira estacao por algum motivo da resposta errada.
            // Entao comecamos da ultima. ;)
            buscaEmProfundidade(matrizDeAdjacencia, cor, estacoes, estacoes - 1);
            cout << "Teste " << ++teste << endl;
            if(estaoConectadas(cor, estacoes)) {
                cout << "normal" << endl << endl;
            } else {
                cout << "falha" << endl << endl;
            }
        }
    } while(estacoes != 0 || linhasDeTransmissao != 0);
    return 0;
}

bool estaoConectadas(int cor[], int estacoes) {
    for(int i = 0; i < estacoes; i++) {
        if(cor[i] == BRANCO) {
            std::cout << "branco: " << i << std::endl;
            return false;
        }
    }
    return true;
}

void inicializar(bool matrizDeAdjacencia[][LIMITE_ESTACOES], int cor[], int estacoes) {
    for(int i = 0; i < estacoes; i++) {
        cor[i] = BRANCO;
        std::cout << "branco: " << i << std::endl;
        for(int j = 0; j < estacoes; j++) {
            matrizDeAdjacencia[i][j] = DESCONECTADO;
        }
    }
}

void buscaEmProfundidade(bool matrizDeAdjacencia[][LIMITE_ESTACOES], int cor[], int estacoes, int estacao) {
    cor[estacao] = CINZA;
    std::cout << "visitando " << estacao << std::endl;
    for(int i = 0; i < LIMITE_ESTACOES; i++) {
        if(matrizDeAdjacencia[estacao][i] == CONECTADO && cor[i] == BRANCO) {
            buscaEmProfundidade(matrizDeAdjacencia, cor, estacoes, i);
        }
    }
    std::cout << "fim da visita " << estacao << std::endl;
    cor[estacao] = PRETO;
}
