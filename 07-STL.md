# STL - Standard Template Library

## Structs

Um struct serve para criar um tipo de dado composto. Por exemplo, um struct aluno poderia ser:

```c++
struct aluno {
    int num_usp;
    int ano_entrada;
    char nome[256];
    char email_usp[128];
};

void test() {
    aluno simaraes;                // variável do novo tipo "aluno"
    simaraes.num_usp = 107108109;  // é usado "." para acessar os campos do struct
    simaraes.ano_entrada = 2018;
    ...
}
```

> Note que, em C++, ao contrário de C, não é necessário usar `struct` antes da declaração de
> uma variável que tem um struct como tipo. Com isso, também não é necessário usar o
> truque do `typedef struct _ { ... } aluno;`.

É possível combinar structs para criar tipos mais complexos:

```c++
struct turma_de_entrada {
    int ano;
    char curso[64];
    int n_alunos;
    aluno alunos[150];
}

// caso se queira acessar o num_usp do 5º aluno da turma:
turma_de_entrada turma;
...
cout << turma.alunos[4].num_usp;
```

### Métodos

Structs podem ter funções específicas, normalmente chamadas de métodos (para diferenciar de funções
que não são ligadas a um struct). Os métodos só funcionam no contexto do struct no qual elas foram
declaradas.

Por exemplo, um struct `vetor3d` poderia ter uma função para calcular o tamanho desse vetor:

```c++
struct vetor3d {
    double x, y, z;    // também é possível declarar vários campos juntos, casos todos sejam do mesmo tipo

    // segue a declaração normal de uma função
    double tamanho() {
        return sqrt(x * x + y * y + z * z);  // os campos do struct ficam disponíveis para a função
    }
};
```

O acesso aos métodos, assim como os campos, também se dá através de `.`:

```c++
vetor3d u, v;
u.x = u.y = u.z = 1;
v.x = v.y = v.z = 2;

printf("|u| = %.2lf, |v| = %.2lf", u.tamanho(), v.tamanho()); // imprime 1.73 e 3.46
```

### Construtores

Construtores são métodos que facilitam a criação de structs. Por exemplo, é bem chato setar manualmente
cada uma das dimensões de um `vetor3d`. O que podemos fazer é criar um construtor que já recebe esses
números:

```c++
struct vetor3d {
    ...

    vetor3d(double a, double b, double c) { // construtores não têm tipo de retorno
        x = a;                              // ... e têm o mesmo nome do struct
        y = b;
        z = c;
    }                                       // não é necessário um return explícito
};
```

Agora podemos criar um `vetor3d` muito mais facilmente:

```c++
vetor3d u = vetor3d(1, 2, 3);

// equivalentemente, na forma simplificada:
vetor3d u(1, 2, 3);
```

## Templates

Templates permitem que um mesmo código sirva para vários tipos de dados. Em resumo, o código é genérico
e pode ser reutilizado para várias situações.

### Templates de funções

Suponha que precisamos de várias funções para calcular o máximo entre dois valores, para os
tipos `int`, `long long`, `float` e `double`. Ao invés de criar 4 funções, podemos criar a
função genérica a seguir:

```c++
template<typename T>
T maximo(T a, T b) {
    if (a >= b)
        return a;
    else
        return b;
}
```

Note que há um preâmbulo antes da função que indica que ela é um template e quais são os parâmetros
de tipo que ela tem. A partir daí podemos usar o tipo genérico (normalmente chamado de `T`) como se fosse
um tipo concreto dentro da função, incluindo nos seus argumentos e tipo de retorno.

Podemos chamar essa função para qualquer tipo de dados (contanto que o operador `>=` faça sentido para ele):

```c++
maximo(1, 2);
maximo(1.0, 5.0);
maximo('X', 'U');
maximo(false, true);
```

### Templates de structs

Da mesma forma que é possível criar funções genéricas, é possível criar structs genéricos.
A sintaxe inicial é igual. Segue exemplo:

```c++
template<typename T>
struct vetor3d {
    T x, y, z;
};
```

Para declarar uma variável de um tipo genérico é necessário identificar entre `< >` qual
é(são) o(s) tipo(s) concretos. Por exemplo, se queremos um `vetor3d` de `int`s, temos
que usar `vetor3d<int>` como o tipo da variável:

```c++
vetor3d<int> v;

v.x = 1;
x.y = -5;
v.z = 23;

printf("(%d, %d, %d)", v.x, v.y, v.z);
```

Métodos e construtores também podem ser genéricos:

```c++
template<typename T>
struct vetor3d {
    T x, y, z;

    vetor3d(T a, T b, T c) {
        x = a;
        y = b;
        z = c;
    }

    void multiplica_por_escalar(T r) {
        x = x * r;
        y = y * r;
        z = z * r;
    }
};
```

A seguir um exemplo de template com mais de um tipo:

```c++
template <typename T, typename U>
struct par {
    T chave;
    U valor;
};

void test() {
    par<int, char> tabela_ascii[256];
    ...
    tabela_ascii[65].chave = 0x41;
    tabela_ascii[65].valor = 'A';
    ...
}
```

## STL

A STL é a biblioteca embutida em C++ que nos dá alguns algoritmos e estruturas de dados prontas para uso.
Seu nome é _Standard **Template** Library_ justamente porque esses algoritmos e estruturas utilizam templates
para serem genéricos. Na STL temos por exemplo o algoritmo `sort` que ordena valores e a estrutura de
dados `set` que guarda valores distintos, como se fosse um conjunto matemático.

## `vector<T>`

O `vector<T>` é uma melhora para o array vindo de C: ele pode aumentar e diminuir de tamanho. E o melhor de tudo
é que isso é feito automaticamente quando usamos os métodos de inserção/remoção dele. Exemplo:

```c++
#include <vector>

using namespace std;

void main() {
    vector<int> v;   // inicialmente v tem zero elementos
    v.push_back(1);  // agora v = |1|
    v.push_back(2);  // v = |1, 2|
    v.push_back(3);  // v = |1, 2, 3|

    // o acesso aos elementos é feito igual a um array: vetor[indice]
    v[1] = 10;       // v = |1, 10, 3|

    cout << v.size();  // imprime 3

    // mas ainda é um erro tentar acessar uma posição que não existe:
    v[50] = 32;      // segmentation fault!
}
```

Os principais construtores e métodos de `vector<T>` usados em competição são:

* `vector<T>()` constrói um vetor vazio. Por ser o costrutor sem parâmetros (o chamado _construtor padrão_),
  também é chamado mesmo quando não colocamos os parênteses:
  ```c++
  vector<int> x();

  // é o mesmo que:
  vector<int> x;
  ```
* `vector<T>(size_t tamanho_inicial)` cria um vetor já com tamanho `tamanho_inicial`. O conteúdo do vetor normalmente
  não é inicializado†. Logo, é preciso tomar cuidado para não usar o vetor antes de atribuir valores para seus ítens.  

  † _se o tipo T contido pelo vector for um struct que tem construtor padrão, os campos são inicializados
  utilizando esse construtor._
  
* `vector<T>(size_t tamanho_inicial, T valor_padrao)` funciona da mesma forma que o acima, mas dá um valor padrão para
  os elementos do vetor. Por exemplo, `vector<int> v(10, 0)` cria um vetor com 10 zeros.

* operador `[]` - utilizado para acessar os elementos, tanto para recuperar seus valores quanto para modificá-los.

* `void push_back(T valor)` insere um valor no final do vetor, aumentando automaticamente seu tamanho.

* `size_t size()` retorna a quantidade de elementos atualmente no vetor.

// TODO diferença entre size e capacity  
// TODO falar do emplace_back?  
// TODO comparação de dois códigos, um usando array e outro usando vector, para mostra como é bem mais simples

### Uma nota sobre inclusão de bibliotecas e namespaces

Para usar a STL, é necessário importar (isto é, indicar ao compilador que se está usando código externo ao seu programa)
seus elementos via `#include`. Para usar o `vector`, por exemplo, precisamos de:

```c++
#include <vector>
```

Além disso, para maior organização, todos elementos da STL estão dentro de um namespace, o `std`. Namespaces servem
para organizar o código de forma a manter coisas associadas num mesmo contexto e para evitar conflitos de nome (isto é,
para podermos ter funções, structs, etc. com o mesmo nome).

Por exemplo, a declaração de `vector<T>` é feita assim:

```c++
namespace std {
    ...
    struct vector {
        ...
    };
}
```

Como vector foi declarado dentro de um namespace, se quisermos usá-lo precisamos antes indicar qual namespace
ele está. O acesso a elementos de um namespace é feito usando o separador de escopo `::`.

```c++
std::vector<int> u;    // sem o "std::" o compilador vai dizer que não sabe o que é um vector<T>
```

Para evitar ter que escrever o `std` toda vez, podemos usar o `using` para indicar que queremos que o vector fique
disponível para nós também sem o seu indicador de namespace:

```c++
using std::vector;

vector<int> u;         // tudo ok, vector<T> é na verdade std::vector<T>
```

Ou ainda podemos fazer isso para todo o namespace `std` de uma vez só:

```c++
using namespace std;

vector<int> u;
stack<int> s;
```

Em ambiente de competição também pode ser usado o import geral:

```c++
#include <bits/stdc++.h>
```

que já importa a maior parte da STL (mas não tira a necessidade do `using namespace std`).


### Uma nota sobre o `size_t`

Ao ler a documentação da STL ou mensagens de erros, frequentemente a gente se depara com o tal `size_t`. Ele é um tipo
numérico que é utilizado para indexar elementos de containers (como arrays, vectors, etc.). Por que não usar `int` ou
`long long` para isso, você pode estar se perguntando. O problema é que `int` e `long long` não têm a garantia de serem
grandes o suficiente para indexar coisas na memória RAM do computador†, enquanto o `size_t` tem a garantia de ser tão grande
quanto o barramento de endereços do processador. Por exemplo, num processador de 64 bits, o `size_t` tem 64 bits, isto é,
8 bytes.

† _C/C++ são usados em muitos tipos de processadores e os tamanhos dos tipos primitivos mudam de processador para processador._

Apesar desse detalhe, normalmente podemos usar `int`s para indexação sem problema algum, pois é raro que tenhamos
um container com mais de 2^31 elementos (o que já dá 512MB de memória, no mínimo) e também porque o compilador faz
uma conversão automática de `int` para `size_t` antes de acessar os elementos.

### O caso especial do `vector<bool>`

// TODO

## `stack<T>`

// TODO

## `queue<T>`

// TODO

## `pair<T,U>`

// TODO

## `priority_queue<T>`

// TODO

## `set<T>`

// TODO

## `map<T,U>`

// TODO

## Algoritmos da STL

### Iteradores

// TODO

### Algoritmos

// TODO mostrar quais?

* sort
* first, last
* find
* unique
* lower_bound, upper_bound

## Referências

* [CPP Reference](https://cppreference.com/)
* [STL Containers](https://en.cppreference.com/w/cpp/container)
* [STL Algorithms](https://en.cppreference.com/w/cpp/algorithm)
