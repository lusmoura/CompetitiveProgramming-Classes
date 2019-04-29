# STL - Standard Template Library

Nessa aula vamos aprender a usar algumas estruturas e funções muito úteis da STL,
a biblioteca padrão de C++.

Primeiro vamos aprender o que são structs e templates, funcionalidades de C++
muito usadas pela STL. Apesar de ser raro nós mesmos criarmos structs e templates
numa competição, é importante saber como elas funcionam. Logo após vamos dar uma
olhada nas principais estruturas de dados da STL.

## Structs

Um struct serve para criar um tipo de dado composto. Por exemplo, um struct aluno poderia ser:

```c++
struct aluno {
    int num_usp;
    int ano_entrada;
    char nome[256];
    char email_usp[128];
};

int main() {
    aluno simaraes;                // variável do novo tipo "aluno"
    simaraes.num_usp = 107108109;  // é usado "." para acessar os campos do struct
    simaraes.ano_entrada = 2018;
    ...
}
```

> Note que, em C++, ao contrário de C, não é necessário usar `struct` antes da declaração de
> uma variável que tem um struct como tipo. Com isso, também não é necessário usar o
> truque do `typedef struct { ... } aluno;`.

É possível combinar structs para criar tipos mais complexos (e também usá-los como elementos
de um array):

```c++
struct turma_de_entrada {
    int ano;
    char curso[64];
    int n_alunos;
    aluno alunos[150];
};

int main() {
    // caso se queira acessar o num_usp do 5º aluno da turma:
    
    turma_de_entrada turma;

    // ...

    cout << turma.alunos[4].num_usp;
}
```

### Métodos

Structs podem ter funções específicas, normalmente chamadas de métodos (para diferenciar de funções
que não são ligadas a um struct). Os métodos só funcionam no contexto do struct no qual elas foram
declaradas.

Por exemplo, um struct `vetor3d` poderia ter uma função para calcular o tamanho desse vetor:

```c++
#include <cmath>

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
#include <cstdio>

int main() {
    vetor3d u, v;
    u.x = u.y = u.z = 1;
    v.x = v.y = v.z = 2;

    printf("|u| = %.2lf, |v| = %.2lf \n", u.tamanho(), v.tamanho()); // imprime 1.73 e 3.46
}
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
um tipo concreto dentro da função.

Podemos chamar essa função para qualquer tipo de dados (contanto que o operador `>=` faça sentido para ele):

```c++
maximo(1, 2);          // resultado: 2
maximo(10.0, 5.0);     // 10.0
maximo('X', 'U');      // 'X'
maximo(false, true);   // true
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

int main() {
    par<int, char> tabela_ascii[256];
    ...
    tabela_ascii[65].chave = 0x41;
    tabela_ascii[65].valor = 'A';
    ...
}
```

## STL

A STL é a biblioteca embutida em C++ que nos dá alguns funções e structs prontos para uso.
Seu nome é _Standard **Template** Library_ justamente porque esses algoritmos e estruturas de dados
utilizam templates para serem genéricos. Na STL temos por exemplo o algoritmo `sort` que
ordena valores e a estrutura de dados `set` que guarda valores distintos, como se fosse
um conjunto matemático.

## `vector<T>`

O `vector<T>` é uma melhora para o array vindo de C: ele pode aumentar e diminuir de tamanho. E o melhor de tudo
é que isso é feito automaticamente quando usamos os métodos de inserção/remoção dele. Exemplo:

```c++
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> v;   // inicialmente v tem zero elementos
    v.push_back(1);  // agora v = |1|
    v.push_back(2);  // v = |1, 2|
    v.push_back(3);  // v = |1, 2, 3|

    // o acesso aos elementos é feito como num array: vetor[indice]
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
  // isso

  vector<int> a();

  // é o mesmo que:

  vector<int> a;
  ```

* `vector<T>(size_t tamanho_inicial)` cria um vetor já com tamanho `tamanho_inicial`. O conteúdo do vetor normalmente
  não é inicializado†. Logo, é preciso tomar cuidado para não usar o vetor antes de atribuir valores para seus ítens.  

  ```c++
  vector<int> a(10); // vetor de 10 ints NÃO INICIALIZADOS
  ```

  † _se o tipo T contido pelo vector for um struct que tem construtor padrão, os campos são inicializados
  utilizando esse construtor._
  
* `vector<T>(size_t tamanho_inicial, T valor_padrao)` funciona da mesma forma que o acima, mas dá um valor padrão para
  os elementos do vetor. Exemplo:

  ```c++
  vector<int> a(10, 0)`; // cria um vetor com 10 zeros

  // a partir de C++17 nem precisamos do <int> †

  vector b(10, 0);         // o compilador sabe que o tipo é int por causa
                           // do tipo do zero, que por padrão é int
  vector c(10, 0.0);       // nesse caso c é um vector<double>
  ```
  † _Para usar o C++17, basta passar `-std=c++17` para o compilador. Mas antes verifique se o online judge tem
  suporte a C++17._

* `vector<T>(initializer_list<T> valores_iniciais)` serve para iniciar manualmente os valores do vector. O tipo
  `initializer_list<T>` se refere a uma lista literal (direto no código) entre chaves. Exemplo de uso:
  
  ```c++
  vector<int> a({1, 2, 3, 4, 5});
  vector<int> b = {1, 2, 3, 4, 5};

  // ou no C++17

  vector c = {1, 2, 3, 4, 5};
  ```

* operador `[]` - utilizado para acessar os elementos, tanto para recuperar seus valores quanto para modificá-los.

* `void push_back(T valor)` insere um valor no final do vetor, aumentando automaticamente seu tamanho.
  Como exemplo de seu uso podemos fazer a leitura da entrada de um problema assim:
  
  ```c++

  // a entrada é dada assim:
  // 5                        <-- número de elementos
  // 1 2 3 4 5                <-- elementos

  int n;
  vector<int> v;
  
  cin >> n;
  for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
  }
  ```

  Uma outra possibilidade é já reservar o espaço para o vetor:

  ```c++
  int n;
  cin >> n;

  vector<int> v(n);   // vetor de n posições

  for (int i = 0; i < n; i++) {
      cin >> v[i];
  }
  ```

* `size_t size()` retorna a quantidade de elementos atualmente no vetor. Exemplo:

    ```c++
    vector<int> v({1, 2, 3, 4, 5});
    
    void print_vector() {
        for (int i = 0; i < v.size(); i++) {
            printf("%d ", v[i]);
        }
        printf("\n");
    }
    ```

<!--
// TODO diferença entre size e capacity  
// TODO falar do emplace_back?  
// TODO comparação de dois códigos, um usando array e outro usando vector, para mostra como é bem mais simples
// TODO falar do for (auto a: v)
-->

<!--
### Um outro tipo de for: `for (tipo variavel : container)`

TODO
-->

### Explicando o `using namespace std;`

Para usar a STL, é necessário importar (isto é, indicar ao compilador que se está usando código externo ao seu programa)
seus elementos via `#include`. Para usar o `vector`, por exemplo, precisamos de:

```c++
#include <vector>
```

Além disso, para maior organização, todos elementos da STL estão dentro de um namespace, o `std`. Namespaces servem
para organizar o código de forma a manter coisas associadas num mesmo contexto e para evitar conflitos de nome (isto é,
para podermos ter funções, structs, etc. com o mesmo nome).

Por exemplo, a declaração de `vector<T>` é feita mais ou menos assim:

```c++
namespace std {
    template <typename T>
    struct vector {          // na verdade seria uma classe, mas isso não importa agora
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

### O que é o tal `size_t` ou `size_type`?

Ao ler a documentação da STL ou mensagens de erros, frequentemente a gente se depara com `size_t`
ou `size_type`. Ele é um tipo numérico que é utilizado para indexar elementos de containers
(como arrays, vectors, etc.). "Por que não usar `int` ou `long long` para isso?", você pode
estar se perguntando. O problema é que `int` e `long long` não têm a garantia de serem grandes
o suficiente para indexar coisas na memória RAM do computador†, enquanto o `size_t` tem a
garantia de ser tão grande quanto o barramento de endereços do processador. Por exemplo, num
processador de 64 bits, o `size_t` tem 64 bits, isto é, 8 bytes.

† _C/C++ são usados em muuuuitos tipos de hardware e os tamanhos dos tipos primitivos mudam de
processador para processador. Em alguns casos o `int` pode ter somente 2 bytes, por exemplo._

Apesar desse detalhe, normalmente podemos e usamos `int`s para indexação sem problema algum, pois
é raro que tenhamos um container com mais de 2^31 elementos (o que já dá 2GiB de memória, no
mínimo) e também porque o compilador já faz a conversão automática de `int` para `size_t` quando
necessário, antes de acessar os elementos.

<!--

### O caso especial do `vector<bool>`

// TODO

-->

## `stack<T>`

A stack<T> é uma pilha de elementos. Ela tem duas operações básicas _push_ e _pop_, que empilham
ou desempilham elementos, respectivamente. Exemplo:

```c++
stack<int> pilha;      // {}        pilha vazia

pilha.push(1);         // {1}       pilha contém somente o elemento 1
pilha.push(2);         // {2, 1}    agora 2 está no topo da pilha
pilha.push(3);         // {3, 2, 1}

pilha.pop();           // {2, 1}    o topo, que era 3, é retirado
pilha.pop();           // {1}
pilha.pop();           // {}
```

* `stack<T>()` constrói uma pilha vazia
* `void push(T valor)` 
* `void pop()`
* `T top()`
* `size_t size()`

Um exemplo mais completo de uso de pilha:

```c++
// TODO
```

## `queue<T>`

// TODO

## `pair<T,U>`

// TODO

## `priority_queue<T>`

// TODO

<!--

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

-->

## Referências

* [CPP Reference](https://cppreference.com/)
* [STL Containers](https://en.cppreference.com/w/cpp/container)
* [STL Algorithms](https://en.cppreference.com/w/cpp/algorithm)
