
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
Uma vez que temos a estrutura podemos adicionar as arestas desse grafo. Se quisermos inserir uma aresta entre 1 e 2, por exemplo, precisamos inserir o número 2 no vector associado à posição 1 do vetor. Sempre bom lembrar que ao adicionar a aresta do 1 para o 2 sem adicionar a aresta contrária, estmos dizenodo que esse grafo é obrigatoriamente **direcionado** O comando para isso é:

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

DFS ou Depth First Search (Busca em profundidade) é um algoritmo de busca em um grafo. Ele pode ser usado de diversas maneiras, como por exemplo, para encontrar componentes conexas (componentes do grafo nas quais é possível ir de um nó para qualquer outro) e para detectar ciclos.

A ideia do seu funcionamente é a seguinte: começando num nó raíz, ele faz o percurso mais profundo que puder primeiro. Depois de ter feito isso, ele faz o chamado backtracking, ou seja, retorna para o estado anterior e procura um novo caminho.

Calma, parece confuso, mas não é. Observe o exemplo abaixo:
![DFS](https://upload.wikimedia.org/wikipedia/commons/7/7f/Depth-First-Search.gif)

Vamos ver o passo a passo para o grafo a seguir:

	      1
	     / \
	    2   3
	   / 
	  4   
	 / \
	5   6


- O percurso começa no nó 1. 
- Em seguida, o seu primeiro filho é processado. Nesse momento temos o caminho (1, 2). 
- Agora vamos para o primeiro filho do 2 e temos (1, 2, 4) e por fim para o primeiro filho do 4, tendo (1, 2, 4, 5). 
- Agora não é mais possível "descer", então vamos voltar um passo para (1, 2, 4) e processar o próximo filho do 4: (1, 2, 4, 6). 
- Novamente, precisamos voltar e temos, (1, 2, 4), porém todos os filhos do 4 já foram processados, então voltamos de novo, tendo (1, 2). 
- Como todos os filhos do 2 foram processados, voltamos para (1) e processamos o segundo filho de 1, (1, 2). 
- Nenhum dos dois possui filhos sem processar, então o algoritmo apenas retorna e acaba o processamento.

É importante notar que devemos ter alguma maneira de marcar os nós como **visitados** (ou processados), para que não entremos num loop e sigamos na busca. Por isso, teremos um vetor auxiliar no qual iremos, para cá nó, identificar se ele já foi ou não processado.

Ou seja, aconteceria o seguinte:
```
(1)
(1, 2)
(1, 2, 4)
(1, 2, 4, 5)
(1, 2, 4, 6)
(1, 2, 4)
(1, 2)
(1)
(1, 3)
(1)
()
```

É possível implementar a DFS com uma pilha (se não estiver familiarizado com isso, é só voltar um pouco e olhar a aula de STL ou recursivamente (observe o esquema acima e note que apenas o último nó é alterado). Vamos mostrar a versão recursiva, pois é mais bonita.

```c++
void dfs(int currNode) {
	// se um nó foi processado, não é preciso processá-lo de novo
	if (vis[currNode]) return;

	// o nó é marcado como já visitado
	vis[currNode] = 1;

	// é feita a chamada recursiva para seus filhos
	for (int i = 0; i < edges[currNode].size(); i++) {
		dfs(edges[currNode][i]);
	}
}
```

## BFS
Falemos agora um pouco sobre a Breadth-First Search ou BFS. Essa é outra maneira de percorrer um grafo, na qual cada "nível" do grafo é analisado por vez. Ou seja, primeiramente são processados todos os filhos de um nó. Em seguida seguimos para processar os filhos dos seus filhos e assim por diante. Essa busca permite, dentre outras coisas, achar componentes conexas e achar o menor caminho entre um nó raiz e os outros nós do grafo.

Vejamos abaixo como funciona a BFS numa árvore:
![BFS](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5d/Breadth-First-Search-Algorithm.gif/375px-Breadth-First-Search-Algorithm.gif)

E para um grafo que contém ciclo:
![BFS](https://upload.wikimedia.org/wikipedia/commons/9/99/Breadth-first_search_Algorithm.gif)

Vamos ver o passo a passo para o mesmo grafo utilizado na DFS:

	      1
	     / \
	    2   3
	   / 
	  4   
	 / \
	5   6


- O percurso começa no nó 1. 
- Em seguida, o seu primeiro filho é processado. Nesse momento temos o caminho (1, 2). 
- Depois processamos seu segundo filho, temos, assim (1, 2, 3). O primeiro nó acabou de ser processado, então temos (2, 3). 
- O próximo nó a ser processado será o 2, para isso, vamos adicionar seus filhos no caminho (2, 3, 4). Done, próximo! 
- Processemos o 3. Como ele não possui filhos, só seguimos em frente, tendo (4).
- Começemos a processar o nó 4. Seus filhos são percorridos e temos (4, 5, 6). Ao terminar de processá-lo, resta (5, 6)
- Processamos o nó 5, que não possui filhos e por último o nó 6, que também não possui.

Ou seja, aconteceria o seguinte:
```
(1)
(1, 2)
(1, 2, 3)
(2, 3)
(2, 3, 4)
(3, 4)
(4)
(4, 5)
(4, 5, 6)
(5, 6)
(6)
```

Nesse caso, estamos inserindo novos nós no final do caminho e tirando os nós que estão no início (é possível notar isso justamente nas listas de processamento mostradas logo aqui em cima). Portanto, precisaremos de uma lista para processar os nós. Cada nó será inserido no final da lista quando for alcançado. Quando chegar sua vez, ou seja, quando estiver na frente da fila, será processado e em seguida removido.

Vamos ver como fica o código:

```c++
void bfs(int root) {
	// criando pilha e colocando o nó raiz
	queue <int> q;
	q.push(root);

	// enquanto ainda houver algum elemento na fila
	while (!q.empty()) {
		// pega o elemento e o tira da pilha
		int u = q.front();
		q.pop();

		// o marca como visitado
		vis[u] = 1;

		// cada filho que não foi visitado ainda é inserido na fila
		for(int i = 0; i < edges[u].size(); i++){
			int v = edges[u][i];
			
			if (!vis[v])
				q.push(v);
		}
	}
}
```

Essa foi uma introdução à Teoria dos Grafos. Em seguida teremos mais algumas aulas ainda sobre eles, falando um pouco sobre caminhos mínimos, árvores geradoras e várias outras coisas feras que podem ser feitas com os grafos! \o/