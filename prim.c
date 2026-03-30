#include <stdio.h>
#include <limits.h>
#include "mst.h"

#define INF INT_MAX

/* Retorna o vértice de menor chave ainda fora da MST */
int minKey(int key[], int inMST[], int V) {
    int min = INF, idx = -1;
    int v;
    for (v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            idx = v;
        }
    }
    return idx;
}

// Agora recebe o grafo do main.c como argumento
void prim(int V, int grafo[V_MAX][V_MAX]) {
    int pai[V_MAX], key[V_MAX], inMST[V_MAX];
    int i, cnt, v;

    // Inicializa: todos fora da MST, chaves infinitas
    for (i = 0; i < V; i++) {
        key[i] = INF; 
        inMST[i] = 0; 
        pai[i] = -1;
    }
    key[0] = 0;  // começa pelo vértice 0

    printf("=== MST por Prim ===\n");
    int custo = 0;

    for (cnt = 0; cnt < V; cnt++) {
        int u = minKey(key, inMST, V);
        inMST[u] = 1;

        if (pai[u] != -1) {
            printf("Aresta: %d -- %d  (peso: %d)\n", pai[u], u, grafo[pai[u]][u]);
            custo += grafo[pai[u]][u];
        }

        // Atualiza chaves dos vizinhos
        for (v = 0; v < V; v++) {
            if (grafo[u][v] && !inMST[v] && grafo[u][v] < key[v]) {
                pai[v] = u;
                key[v] = grafo[u][v];
            }
        }
    }
    printf("Custo total: %d\n", custo);
}
