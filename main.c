/* main.c — Testando Kruskal e Prim */
#include <stdio.h>
#include "mst.h"

int main() {
    // Inicializa a matriz inteira com zeros (fundamental para o Prim)
    int grafo[V_MAX][V_MAX] = {0}; 
    
    int V = 5;  // 5 vértices: A(0), B(1), C(2), D(3), E(4)
    int E = 7;  // 7 arestas

    /* Arestas para Kruskal: {u, v, peso} */
    Aresta arestas[] = {
        {0, 1, 2},   // A-B = 2
        {1, 3, 3},   // B-D = 3
        {0, 2, 4},   // A-C = 4
        {2, 4, 5},   // C-E = 5
        {2, 3, 6},   // C-D = 6
        {1, 2, 7},   // B-C = 7
        {0, 3, 8}    // A-D = 8
    };

    /* Matriz de adjacência para Prim */
    grafo[0][1] = grafo[1][0] = 2;
    grafo[1][3] = grafo[3][1] = 3;
    grafo[0][2] = grafo[2][0] = 4;
    grafo[2][4] = grafo[4][2] = 5;
    grafo[2][3] = grafo[3][2] = 6;
    grafo[1][2] = grafo[2][1] = 7;
    grafo[0][3] = grafo[3][0] = 8;

    printf("\n--- KRUSKAL ---\n");
    kruskal(arestas, E, V);

    printf("\n--- PRIM ---\n");
    prim(V, grafo); // Agora enviamos o grafo preenchido para o Prim

    return 0;
}
