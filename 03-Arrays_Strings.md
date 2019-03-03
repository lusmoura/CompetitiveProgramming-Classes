# Vetores, Matrizes e Strings

# Vetores

Os vetores (ou arrays) servem para armazenar várias variáveis (de mesmo tipo) de uma só vez. Podemos representar arrays da seguinte forma:

```c++
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        
        int tamanho = 10;
        int vec[tamanho]; // tipo nome[tamanho]
        
        for (int i = 0; i < tamanho; i++) { //para cada posição do vetor
            int x;
            scanf("%d", &vec[i]); //leia um valor e armazene no vetor
        }

        for (int i = 0; i < tamanho; i++) {
            printf("%d ", vec[i]);
        }
    }
```

Nesse caso, lemos 10 números inteiros e os armazenamos no array *vec*. As posições do array são representadas com valores de 0 até tamanho_var. Ou seja, um array de tamanho 10 tem posições de 0 até 9. Elas podem ser acessadas utilizando indices dentro dos colchetes, para acessar o valor que está na posição 5, por exemplo, podemos escrever vec[4].

Também é possível inicializar um array com valores, da seguinte forma:

```c++
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        
        int tamanho = 5;
        int vec[5] = {1, 2, 3, 4, 5};

        for (int i = 0; i < tamanho; i++) {
            printf("%d ", vec[i]);
        }
    }
```

O array acima pode ser representado da assim:

| Index: | vec[0] | vec[1] | vec[2] | vec[3] | vec[4] |
|:------:|:------:|:------:|:------:|:------:|:------:|
| Value: |    1   |    2   |    3   |    4   |    5   |


# Matrizes
Uma matriz é um array 2D, isso é, um array que pode ser organizado e acessado a partir de linha e colunas. O código abaixo mostra a utilização de uma matriz:

```c++
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        
        int tamanhoLinhas = 3;
        int tamanhoColunas = 4;
        int mat[tamanhoLinhas][tamanhoColunas];  // tipo nome[tamanhoLinhas][tamanhoColunas]
        
        for (int i = 0; i < tamanhoLinhas; i++) { //para cada linha
            for(int j = 0; j < tamanhoColunas; j++){ //para cada coluna
                int x;
                scanf("%d", &mat[i][j]); //leia um valor e armazene na matriz
            }
        }

        for (int i = 0; i < tamanhoLinhas; i++) {
            for(int j = 0; j < tamanhoColunas; j++) {
                printf("%d ", mat[i][j]);
            }
            printf("\n"); //após cada linha feita a impressão de uma quebra
        }
    }
```

Nesse caso, lemos 12 números inteiros e os armazenamos na matriz *mat*. Cada dimensão da matriz tem posições que vão de 0 a tamaho-1. Ou seja, numa matriz 3x4, tanto as linhas são numeradas de 0 a 2 e as colunas, de 0 a 3. Assim como nos array, podemos acessar valores utilizando indices dentro dos colchetes, mas dessa vez precisaremos utilizar os dois índices, da linha e da coluna. Para acessar o valor que está na primeira linha e na primeira coluna, por exemplo, utilizaremos mat[0][0].

Também é possível inicializar uma matriz com valores, da seguinte forma:

```c++
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        
        int tamanhoLinhas = 3;
        int tamanhoColunas = 4;
        int mat[tamanhoLinhas][tamanhoColunas] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

        for (int i = 0; i < tamanhoLinhas; i++) {
            for(int j = 0; j < tamanhoColunas; j++){
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
    }
```

A matriz acima pode ser representada assim:

|  Index   | mat[][0] | mat[][1] | mat[][2] | mat[][3] |
|:--------:|:--------:|:--------:|:--------:|:--------:|
| mat[0][] |     1    |     2    |     3    |     4    |
| mat[1][] |     5    |     6    |     7    |     8    |
| mat[2][] |     9    |    10    |    11    |    12    |

# Variáveis globais, locais e *lixo*

Em todos os casos até agora, declaramos nossas variáveis dentro da função *main*. Porém, podemos também declarar variáveis fora dela. Usar variáveis globais fará mais sentido mais a frente, quando falaremos mais sobre *funções*. Por enquanto, vamos falar de apenas uma vantagem de se utilizar variáveis globais - mas, para isso, primeiro temos que entender o que é *lixo* em C/C++.

Quando criamos uma variável e não atribuimos um valor à ela, o espaço da memória que é reservado pode estar com qualquer valor. Espera, não entendi nada! Ao criarmos uma variável, é alocado um espaço para ela na memória. Porém, esse espaço em memória pode já ter sido usada antes, ou seja, alguns 0s e 1s podem ter ficado "sobrando" por lá, e, mesmo quando não os queremos mais, é melhor para o computador sobrescrevê-los em vez de apagá-los. Talvez não tenha ficado tão claro, então você mesmo pode fazer uns testes: crie um programa do seguinte jeito:

```c++
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        int x;
        cout << x << endl;
    }
```

Execute ele várias vezes, e veja os valores que x possui. Os valores diferentes mostram que a cada execução uma posição deferente da memória é utilizada e que nela havia um valor "lixo".

Porém, quando criamos variáveis globais, além delas poderem ser utilizadas em qualquer lugar do código - novamente, falaremos sobre funções mais a frente - elas já se iniciam totalmente zeradas, o que muitas vezes é útil.

```c++
    #include <bits/stdc++.h>
    using namespace std;

    int vet_global[15]; //variavel global, array de tamanho 15 de inteiros.

    int main() {
        int vet_local[15];
        for (int i = 0; i < 15; i++) printf("%d ", vet_local[i]);
        // no meu computador, foram printados esses valores: 0 0 8 0 1 0 -1477321288 32764 -1477321272 32764 9 0 0 0 4839111

        //variavel global:
        for (int i = 0; i < 15; i++) printf("%d ", vet_global[i]);
        // no meu computador, foram printados esses valores: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
    }
```

É bom ressaltar, porém, que apesar do uso de variáveis globais ser bastante útil para programação competitiva, é uma prática abominada na "programação normal". Como geralmente temos códigos grandes, com muitas variáveis e muitas funções (sério, juro que uma hora vamos falar delas), utilizar variáveis globais pode causar, por exemplo, conflitos de nomes. Então nos contests e questões pode usar e abusar dessas variáveis, mas vai com calma nos trabalhos de ICC.

# Strings
Strings são arrays de caracteres, isto é, palavras e frases. Em C não temos o tipo string, então seria preciso utilizar literalmente um vetor de caracteres ou adicionar uma biblioteca (string.h), mas em C++ já temos string como um tipo de variável.
No código abaixo podemos ver como se faz leitura e escrita de palavras:

```c++
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        string s;
        
        cin >> s;
        cout << s;
    }
```
Para ler frases ou qualquer string que contenha um espaço (" "), em geral é feita a leitura de uma linha inteira com a função getline(). Ela é utilizada da seguinte forma:


```c++
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        string s;
        
        getline(cin, s); //getline(cin, nomeDaString)
        cout << s;
    }
```

Uma coisa interessante é que em C++ podemos "somar" strings. Essa operação concatena strings, ou seja, se somarmos as strings a e b (a + b), adicionaremos a string b ao final de a. O exemplo abaixo mostra essa operação:

```c++
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        string s = "Nao tenho";
        string t = " criatividade";

        s = s + t;
        cout << t << endl; //endl = \n
        //na tela será possível ler Nao tenho criatividade
    }
```

Também é possível acessar uma string da mesma forma que vimos para arrays, isto é, utilizando [] para termos o valor de uma certa posição, que no caso da string é uma letra. Para fazer isso, geralmente é preciso utilizar a função size(), que retorna o tamanho da string. No código abaixo lemos uma string e imprimimos uma letra em cada linha.

```c++
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        string s;
        
        cin >> s;
        int n = s.size();
        for(int i = 0; i < n; i++){
            cout << s[i] << endl;
        }
    }
```

Existem muitas funções e algorítmos para lidar com strings. Ao longo das aulas vamos ver outras formas de lidar com elas.
