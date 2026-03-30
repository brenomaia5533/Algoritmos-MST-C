#include <stdio.h>
#include <stdlib.h>
#include "mst.h"

/* Union-Find — detecta ciclos */
int pai[V_MAX], rank_[V_MAX];

int encontrar(int x) {
    if (pai[x] != x)
        pai[x] = encontrar(pai[x]);
    return pai[x];
}

void unir(int x, int y) {
    int rx = encontrar(x), ry = encontrar(y);
    if (rank_[rx] < rank_[ry]) pai[rx] = ry;
    else if (rank_[rx] > rank_[ry]) pai[ry] = rx;
    else { pai[ry] = rx; rank_[rx]++; }
}

/* Comparador para ordenar por peso */
int compara(const void *a, const void *b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}

void kruskal(Aresta arestas[], int E, int V) {
    int i;
    
    // 1. Inicializa Union-Find
    for (i = 0; i < V; i++) { 
        pai[i] = i; 
        rank_[i] = 0; 
    }

    // 2. Ordena arestas por peso (menor -> maior)
    qsort(arestas, E, sizeof(Aresta), compara);

    int custo = 0, count = 0;
    printf("=== MST por Kruskal ===\n");

    // 3. Percorre arestas ordenadas
    for (i = 0; i < E && count < V-1; i++) {
        int ru = encontrar(arestas[i].u);
        int rv = encontrar(arestas[i].v);

        if (ru != rv) {  // não forma ciclo!
            unir(ru, rv);
            custo += arestas[i].peso;
            count++;
            printf("Aresta: %d -- %d  (peso: %d)\n",
                   arestas[i].u, arestas[i].v, arestas[i].peso);
        }
    }
    printf("Custo total: %d\n", custo);
}
