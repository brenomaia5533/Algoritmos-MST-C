# 🌳 Algoritmos de Árvore Geradora Mínima (MST) — Kruskal & Prim

Este repositório contém a implementação em linguagem C de dois dos algoritmos mais fundamentais da teoria dos grafos: **Kruskal** e **Prim**. O objetivo deste projeto é encontrar a Árvore Geradora Mínima (Minimum Spanning Tree) de diferentes tipos de grafos, comparando os custos e a eficiência de cada método.

🔗 **Acesse o site do projeto:** (https://mst-grupo2.netlify.app/#codigo)

---

## 🛠️ Tecnologias e Ambiente
* **Linguagem:** C (Padrão ISO C89/C99).
* **IDE Recomendada:** Dev-C++.
* **Estruturas de Dados:** Matriz de Adjacência, Vetor de Arestas (Structs) e Union-Find com *Path Compression*.

---

## 🚀 Como Utilizar
1. Clone este repositório em sua máquina local.
2. Abra o arquivo de projeto no **Dev-C++**.
3. Certifique-se de que os arquivos `main.c`, `kruskal.c`, `prim.c` e `mst.h` estejam no mesmo diretório.
4. No arquivo `main.c`, utilize a matriz `grafoMatriz` para definir a estrutura do grafo que deseja testar.
5. Compile (**F11**) e visualize os resultados no terminal.

---

## 📊 Bateria de Testes

O código foi preparado para lidar com diversas topologias de grafos. Abaixo estão os modelos de matrizes prontos para copiar e colar no seu `main.c`:

### 1. Grafo Conexo (Padrão)
Cenário onde todos os nós estão integrados, permitindo uma MST única e completa.
```
V = 5; 
grafoMatriz[0][1] = grafoMatriz[1][0] = 2;
grafoMatriz[0][2] = grafoMatriz[2][0] = 4;
grafoMatriz[0][3] = grafoMatriz[3][0] = 6;
grafoMatriz[1][2] = grafoMatriz[2][1] = 3;
grafoMatriz[1][3] = grafoMatriz[3][1] = 8;
grafoMatriz[1][4] = grafoMatriz[4][1] = 5;
grafoMatriz[2][4] = grafoMatriz[4][2] = 7;

2.Grafo Esparso (Formato em Linha)
Número reduzido de arestas em relação ao número de vértices. Testa a eficiência de processamento de arestas do Kruskal.

V = 6;
// Conexão em série (0-1-2-3-4-5)
grafoMatriz[0][1] = grafoMatriz[1][0] = 10;
grafoMatriz[1][2] = grafoMatriz[2][1] = 20;
grafoMatriz[2][3] = grafoMatriz[3][2] = 30;
grafoMatriz[3][4] = grafoMatriz[4][3] = 40;
grafoMatriz[4][5] = grafoMatriz[5][4] = 50;

3. Grafo Não Conexo (Ilhas Isoladas)
Utilizado para testar a detecção de componentes e a geração de uma Floresta Geradora Mínima.

V = 6; 
// Componente A (Triângulo 0-1-2)
grafoMatriz[0][1] = grafoMatriz[1][0] = 4;
grafoMatriz[1][2] = grafoMatriz[2][1] = 5;
grafoMatriz[0][2] = grafoMatriz[2][0] = 6;

// Componente B (Linha 3-4-5) isolado
grafoMatriz[3][4] = grafoMatriz[4][3] = 2;
grafoMatriz[4][5] = grafoMatriz[5][4] = 3;

4. Grafo Denso (Completo $K_4$)
Cenário onde cada vértice se conecta a todos os outros, testando a performance de busca do Prim.C

V = 4;
// Todos conectados a todos
grafoMatriz[0][1] = grafoMatriz[1][0] = 1;
grafoMatriz[0][2] = grafoMatriz[2][0] = 4;
grafoMatriz[0][3] = grafoMatriz[3][0] = 2;
grafoMatriz[1][2] = grafoMatriz[2][1] = 3;
grafoMatriz[1][3] = grafoMatriz[3][1] = 5;
grafoMatriz[2][3] = grafoMatriz[3][2] = 1;
