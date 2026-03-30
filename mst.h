#ifndef MST_H
#define MST_H

#define V_MAX 100 // Definido globalmente para todos os arquivos

/* Estrutura de uma Aresta */
typedef struct {
    int u, v, peso;
} Aresta;

/* Protótipos com as assinaturas exatas das funções */
void kruskal(Aresta arestas[], int E, int V);
void prim(int V, int grafo[V_MAX][V_MAX]);

#endif
