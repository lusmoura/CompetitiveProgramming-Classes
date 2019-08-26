# Grafos

Nessa aula vamos falar um pouco sobre grafos, o que são essas estruturas, para quê servem, como utilizá-las e alguns algoritmos bem legais.

### O que é um grafo?
Um grafo é uma estrutura composta por dois conjuntos, um conjunto de vértices (ou nós) e um de arestas. As arestas tem como funcionalidade ligar/conectar vértices. 

Meio abstrato, eu sei, mas podemos olhar para a figura abaixo para ter uma noção melhor:
![Grafo](https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/figs/coelho-2011/aresta-biconexo-coelho.png)

Nesse caso, temos os vértices (círculos enumerados de 0 a 10) e as arestas (linhas verdes entre os vértices).

### Utilidade
Grafos tem muitas utilidades no dia a dia (em programação competitiva e fora dela!), como:

- Mapas: nesse caso temos, por exemplo, que as casas são vértices e eles estão ligados por ruas, que são as arestas.

![Grafo - Mapa](https://st3.depositphotos.com/1519283/12867/v/950/depositphotos_128676848-stock-illustration-city-map-illustration.jpg)

- Relações entre pessoas: cada pessoa é um nó e as relações entre elas são as arestas.

![Grafo - Pessoas](http://www.inf.ufsc.br/grafos/definicoes/digrafo.gif)

- Matérias curriculares: cada matéria da grade é um vértice e as arestas são as relações de dependência entre elas, isto é, se uma matéria depende de outra (ou tranca uma sucessora), há uma aresta entre elas.

![Grafo - Grade curricular](https://web.icmc.usp.br/SVGRAD/ppp/esquemabcc.jpg)

### Conceitos importantes
- **Ordem**: a quantidade de vértices de um grafo.
- **Adjacência**: dois nós ligados por uma aresta são ditos adjacentes.
- **Grau**: o grau de um nó representa a quantidade de nós que ele tem como adjacentes.
- **Caminho**: um caminho é uma sequência de arestas que liga dois vértices.
- **Direcionado**: um grafo pode ser ou não direcionado. Num grafo não direcionado (como na primeira imagem), se temos uma aresta A->B, também temos a aresta B->A. Já num grafo direcionado as arestas são independentes, isto é, a existência da aresta A->B não diz nada sobre a B->A.
- **Ponderado**: um grafo ponderado é um grafo no qual as arestas tem pesos, como na figura abaixo.
- **Cíclico**: um grafo é dito ciclíco quando há nele um ciclo, ou seja, um caminho que sai de um nó A e retorna a ele.
- **Conexo**: um grafo é dito conexo quando há pelo menos um caminho entre quaisquer dois pares de vértices.
- **Componente conexa**: mesmo que não haja um caminho entre todos os vértices do grafo, é possível dividí-lo em subgrafos que tenham esses caminhos. Dessa forma, temos as componentes conexas, ou seja, os subgrafos que são conexos.

## Implementação
### Como representar um grafo?
Existem várias maneiras de representar um grafo, mas vamos mostrar hoje a representação por meio da chamada **lista de adjacências**. 

Para representar um grafo, precisamos basicamente de um forma de representar seus vértices e suas arestas. Usamos, então, a lista da seguinte forma: para cada nó, armazenamos uma lista com os nós aos quais ele é adjacente. 

Visualmente as listas ficam assim:  
![Lista de adjacências](https://upload.wikimedia.org/wikipedia/commons/thumb/6/61/Lista_de_adjacencia.png/360px-Lista_de_adjacencia.png)

O nó 1 tem como adjacentes os nós 2 e 5.  
O nó 2 tem como adjacentes os nós 1, 3 e 5.  
O nó 3 tem como adjacentes os nós 2 e 4.  
O nó 4 tem como adjacentes os nós 3, 5 e 6.  
O nó 5 tem como adjacentes os nós 1, 2 e 4.  
O nó 6 tem como adjacente somente o nó 4.

Agora falando em termos de código, a declaração dessa estrutura pode ser feita com um vetor de vectors. Cada índice do vetor representa um nó (como os nós verdeds da imagem acima) e em cada posição desse vetor temos um vector que armazena os adjacentes, então cada vector seria a lista de adjacências em si (a lista amarela da imagem acima).

A declaração é:

```c++
#define MAX 1e5

vector<int> edges[MAX];
``` 

### Adicionando arestas
Uma vez que temos a estrutura podemos adicionar as arestas desse grafo. Se quisermos inserir uma aresta entre 1 e 2, por exemplo, precisamos inserir o número 2 no vector associado à posição 1 do vetor. O comando para isso é:

```c++
edges[1].push_back(2);
```

Tomemos o grafo abaixo como referência:  
![Grafo](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRNTONs5fUXLrd-VBAxdAHqBQ9d8l0EVV8I5oqShmMpuC0J0k_z)

Para inserir todas as arestas entre os vértices podemos fazer:
```c++
// inserindo aresta 1->2 e 2->1
edges[1].push_back(2);
edges[2].push_back(1);

// inserindo aresta 1->5 e 5->1
edges[1].push_back(5);
edges[5].push_back(1);

// inserindo aresta 2->5 e 5->2
edges[2].push_back(5);
edges[5].push_back(2);

// inserindo aresta 3->2 e 2->3
edges[2].push_back(3);
edges[3].push_back(2);

// inserindo aresta 3->4 e 4->3
edges[3].push_back(4);
edges[4].push_back(3);

// inserindo aresta 5->4 e 4->5
edges[5].push_back(4);
edges[4].push_back(5);

// inserindo aresta 6->4 e 4->6
edges[6].push_back(4);
edges[4].push_back(6);
```

Agora a lista será algo como:  
1 -> 2 5  
2 -> 1 5 3  
3 -> 2 4  
4 -> 3 5 6  
5 -> 1 2 4  
6 -> 4  

Top, já temos nosos grafo montado e podemos seguir para a parte dos algoritmos! Vamos ver dois dos principais algorítmos de busca em grafos: a busca em profundidade (DFS) e a busca em largura (BFS).

## DFS

## BFS
