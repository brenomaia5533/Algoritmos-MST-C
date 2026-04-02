#include <stdio.h>
#include "mst.h"

int main() {
    // Declarando os contadores fora do loop para evitar o erro de C99
    int i, j; 
    int V, E = 0;
    int grafoMatriz[V_MAX][V_MAX] = {0};
    Aresta listaArestas[V_MAX * V_MAX];

    // --- PASSO 1: DEFINIÇÃO DO GRAFO ---
  V = 5; // Vértices: 0, 1, 2, 3, 4

grafoMatriz[0][1] = grafoMatriz[1][0] = 2;
grafoMatriz[0][3] = grafoMatriz[3][0] = 6;
grafoMatriz[1][2] = grafoMatriz[2][1] = 3;
grafoMatriz[1][3] = grafoMatriz[3][0] = 8;
grafoMatriz[1][4] = grafoMatriz[4][1] = 5;
grafoMatriz[2][4] = grafoMatriz[4][2] = 7;
grafoMatriz[3][4] = grafoMatriz[4][3] = 9;

    // --- PASSO 2: CONVERSÃO AUTOMÁTICA ---
    // Usando os contadores i e j já declarados no topo
    for (i = 0; i < V; i++) {
        for (j = i + 1; j < V; j++) {
            if (grafoMatriz[i][j] != 0) {
                listaArestas[E].u = i;
                listaArestas[E].v = j;
                listaArestas[E].peso = grafoMatriz[i][j];
                E++;
            }
        }
    }

    // --- PASSO 3: EXECUÇÃO ---
    printf("Executando MST para %d vertices e %d arestas.\n", V, E);
    
    printf("\n--- RESULTADO KRUSKAL ---\n");
    kruskal(listaArestas, E, V);

    printf("\n--- RESULTADO PRIM ---\n");
    prim(V, grafoMatriz);

    return 0;
}
