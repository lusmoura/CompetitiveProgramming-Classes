# STL - Standard Template Library

Nessa aula vamos aprender a usar algumas estruturas e funções muito úteis da STL,
a biblioteca padrão de C++.

Primeiro vamos aprender o que são structs e templates, funcionalidades de C++
muito usadas pela STL. Apesar de ser raro nós mesmos criarmos structs e templates
numa competição, é importante saber como elas funcionam. Logo após vamos dar uma
olhada nas principais estruturas de dados da STL.

## Índice

* [Structs](#Structs)
  * [Métodos](#Métodos)
  * [Construtores](#Construtores)
* [Templates](#Templates)
  * [Templates de Funções](#Templates-de-funções)
  * [Templates de Structs](#Templates-de-structs)
* [STL](#STL)
  * [`vector<T>`](#vectort)
  * [`stack<T>`](#stackt)
  * [`queue<T>`](#queuet)
  * [`deque<T>`](#dequet)
  * [`pair<T,U>`](#pairtu)
  * [`priority_queue<T>`](#priority_queuet)
  * [`set<T>`](#sett)
  * [`map<T,U>`](#maptu)
  * [`unordered_set<T>`](#unordered_sett)
  * [`unordered_map<T,U>`](#maptu)
  * [`multiset<T>`](#multisett)
  * [Algoritmos da STL](#Algoritmos-da-STL)
    * [Iteradores](#iteradores)
    * [Principais Algoritmos](#Principais-algoritmos)
      * [`sort`](#sort)
      * [`upper_bound`](#upper_bound)
      * [`lower_bound`](#lower_bound)
      * [`min`](#min)
      * [`max`](#max)
* [Extras](#Extras)
  * [Explicando o `using namespace std;`](#Explicando-o-using-namespace-std)
  * [O que é o tal `size_t` ou `size_type`?](#sizet)
  * [O caso especial do `vector<bool>`](#O-caso-especial-do-vectorbool)
  * [Inferência de tipos usando `auto`](#Inferência-de-tipos-usando-auto)
  * [Loop em containers: `for (tipo x : container)`](#Loop-em-containers-for-tipo-x--container)
* [Referências](#Referências)

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

> [Templates de funções no C++ Reference](https://en.cppreference.com/w/cpp/language/function_template)

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
> [`vector<T>` no C++ Reference](https://en.cppreference.com/w/cpp/container/vector)

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

## `stack<T>`

A `stack<T>` é uma pilha de elementos, como numa pilha de objetos numa mesa. Ela tem duas operações
básicas _push_ e _pop_, que empilham ou desempilham elementos, respectivamente. Exemplo:

```c++
stack<int> pilha;      // {}        pilha vazia

pilha.push(1);         // {1}       pilha contém somente o elemento 1
pilha.push(2);         // {2, 1}    agora 2 está no topo da pilha
pilha.push(3);         // {3, 2, 1}

pilha.pop();           // {2, 1}    o topo, que era 3, é retirado
pilha.pop();           // {1}
pilha.pop();           // {}
pilha.pop();           // {}        não faz nada, pois já está vazia
```

A principal característica da pilha é que ele segue a regra FILO - _first in, last out_, isto é
um elemento que foi empilhado primeiro será o último a ser desempilhado.

Você poderia dizer "ah, mas dá implementar uma pilha usando um vector". Dá sim, mas a importãncia
de usar uma estrutura de dados mais simples, com um propósito mais bem definido, é manter o
código mais claro, já que a intenção do programador fica mais clara quando ele usa uma pilha
ao invés de um vector geralzão.

* `stack<T>()` constrói uma pilha vazia.

* `stack<T>(Container const & container)` cria uma pilha com o conteúdo dado. Os últimos elementos
do container estão mais no topo da fila. Por exemplo:
```c++
stack<int> s({1, 2, 3, 4, 5});

while (not s.empty()) {
    cout << s.top() << " ";
    s.pop();
}
```
imprime "5 4 3 2 1".
  
* `void push(T valor)` insere o valor dado no topo da pilha. O próximo `pop()` retirará esse valor
  da pilha.
* `void pop()` retira o topo da pilha. Não faz nada se a pilha estiver vazia. Note que `pop()` não
  retorna o valor que está no topo. Para isso é necessário usar `top()`.
* `T top()` retorna o valor que está no topo da pilha. Se a pilha estiver vazia, chamar `top()` leva
  a um erro.
* `size_t size()` retorna a quantidade de elementos que está atualmente na pilha.
* `bool empty()` indica se a pilha está vazia ou não. É comum utilizar um `while (not pilha.empty())`
  como condição em algoritmos que utilizam uma pilha.

Note que não é possível acessar um elemento que está no meio da pilha sem antes retirar todos elementos
que estão acima dela usando `pop()`. Não há como fazer `pilha[i]` ou `for (auto x : pilha)`.

> [`stack<T>` no C++ Reference](https://en.cppreference.com/w/cpp/container/stack)

## `queue<T>`

A `queue<T>` é uma fila de elementos, como uma fila de banco ou supermercado. Ela funciona de forma oposta
à pilha, usando a regra FIFO - _first in, first out_. Ou seja, um elemento que foi enfileirado primeiro
é o primeiro a ser desenfileirado:

```c++
queue<int> fila;      // {}        fila vazia

fila.push(1);         // {1}       pilha contém somente o elemento 1
fila.push(2);         // {2, 1}    agora 2 está no final da fila
fila.push(3);         // {3, 2, 1} agora 3 está na rabeira

fila.pop();           // {3, 2}    o início, que era 1, é retirado
fila.pop();           // {3}
fila.pop();           // {}
fila.pop();           // {}        não faz nada, pois já está vazia
```

<!-- TODO construtores e funções -->

Assim como na pilha, não é possível acessar os elementos que estão no meio da fila.

> [`queue<T>` no C++ Reference](https://en.cppreference.com/w/cpp/container/queue)

## `deque<T>`

A `deque<T>` é uma fila de duas pontas. Os elementos podem entrar e sair dela por qualquer um dos
lados. Por exemplo:

<!-- TODO exemplo mostrando funcionamento -->
<!-- TODO construtores e funções -->

> [`deque<T>` no C++ Reference](https://en.cppreference.com/w/cpp/container/deque)

## `pair<T,U>`

<!-- TODO explicação -->
<!-- TODO construtores e funções -->
<!-- TODO make_pair -->
<!-- TODO tuple, get<n>(t) -->

> [`pair<T>` no C++ Reference](https://en.cppreference.com/w/cpp/utility/pair)
> [`tuple<T>` no C++ Reference](https://en.cppreference.com/w/cpp/utility/tuple)

## `priority_queue<T>`

A priority_queue<T> nada mais é que uma *fila de prioridades*. Ou seja, ela funciona como uma fila - posso adicionar um elemento, e remover o primeiro - que, porém, organiza os elementos interiores em alguma ordem específica e o seu primeiro elemento é sempre o maior de todos os inseridos, de acordo com algum método escolhido. As principais funções da `priority_queue` são o `push` (insere um elemento), `top` (retorna o primeiro elemento) e `pop` (remove o primeiro elemento).
    
```c++
priority_queue<int> pq; // priority_queue vazia
pq.push(1);             // {3}
pq.push(3);             // {3, 1}
pq.push(2);             // {3, 2, 1}
int u = pq.top();       // u = 3
pq.pop();               // {2, 1}
pq.pop();               // {1}
pq.pop();               // priority_queue vazia
```

E se quisermos deixar a fila ordenada de outra forma? Por exemplo, se for preciso que o primeiro elemento da fila seja o *menor* elemento, e nao o maior?

Existem dois jeitos mais conhecidos de se fazer isso. Um deles é o seguinte:

```c++
priority_queue<int, vector<int>, greater<int> > pq;
```

Nesse caso, o que está sendo feito é o seguinte: se cria uma priority_queue de *int*, com o *container* de um vector<int> (que é o container padrão dela), e que utiliza a função de comparação *greater<int>* (função existente na *STL* que ordena os elementos de forma decrescente).
    
Porém, também é possível fazer o seguinte: cria-se uma `priority_queue` normal. Porém, ao adicionar um elemento qualquer, adiciona-se o *oposto* daquele elemento. Por exemplo, digamos que eu queira armazenar os valores *1, 2 e 3* de forma decrescente:

```
priority_queue<int> pq; // fila vazia
pq.push(-1);            // {-1}
pq.push(-2);            // {-1, -2}
pq.push(-3);            // {-1, -2, -3}
```

Com isso, eu tenho os elementos ordenados de forma decrescente, e quando eu quiser pegar o elemento do topo, pode-se fazer isso:

```
int x = -pq.top();
```
Que pegará o oposto do topo da fila - que é o elemento original.

OBS: sempre que um elemento é inserido ou removido da priority_queue, a organização dos elementos internos é alterada, para que ela esteja sempre ordenada. Da pra perceber que isso tem um custo computacional - e as operações `pop` e `push` tem a complexidade de *O(log n)*, em que *n* é o número de elementos presentes na fila de prioridades.

* `priority_queue<T>()` constrói uma priority queue vazia
* `void push(T valor)` insere um elemento em O(log n)
* `void pop()` remove um elemento em O(log n)
* `T top()` retorna o primeiro elemento em O(1)
* `size_t size()` retorna o numero de elementos

## `set<T>`

O `set<T>` representa basicamente um conjunto matemático - ou seja, os elementos ficam ordenados e não se repetem. Suas principais operações são: `insert`, `erase`, `find` e `count`.

```
set<int> st;
st.insert(10);
st.insert(20);
st.insert(5);

for (int elem : st) // percorre elemento por elemento do set
   cout << elem << endl; // 5, 10, 20

if (st.find(3) == st.end())
   cout << "O elemento 3 não está no set" << endl;
   
if (st.count(5) != 0)
   cout << "O elemento 5 está no set" << endl;

st.erase(4);
```

* `set<T>()` constrói um set vazio
* `void insert(T valor)` insere um elemento em O(log n)
* `void erase(T valor)` remove um elemento em O(log n)
* `set<T>::iterator find(T valor)` retorna o iterador para o elemento (end() se não estiver nele) em O(log n)
* `size_t size()` retorna o numero de elementos
* `size_t count(T valor)` retorna a quantidade de elementos com o valor presente no set em O(log n)

## `map<T,U>`

// TODO

## `unordered_set<T>`

// TODO

## `unordered_map<T,U>`

// TODO

## `multiset<T>`

// TODO

## Algoritmos da STL

### Iteradores

// TODO

### Principais algoritmos

#### sort

Ordena um intervalo de elementos.

```c++
vector<int> a = {5, 1, 3, 7, 9};
sort(a.begin(), a.end());
// a = {1, 3, 5, 7, 9};
sort(a.rbegin(), a.rend());
// a = {9, 7, 5, 3, 1};
```

Também é possível definir sua própria função de ordenação:

```c++
bool cmp(int a, int b) { // isso ordena de forma crescente
   return a < b;
}

int main() {
   ...
   sort(a.begin(), a.end(), cmp);
}
```

#### lower_bound

// TODO

#### upper_bound

// TODO

#### min

Retorna o elemento mínimo.

```
cout << min(100, 30) << endl;     // 30
cout << min('a', 'z') << endl;    // 'a'
cout << min({10, 20, 5}) << endl; // 5
```

#### max

Retorna o elemento máximo.

```
cout << max(100, 30) << endl;     // 100
cout << max('a', 'z') << endl;    // 'z'
cout << max({10, 20, 5}) << endl; // 20
```

## Extras

### Explicando o `using namespace std;`

Para usar a STL, é necessário importar (isto é, indicar ao compilador que se está usando
código externo ao seu programa) seus elementos via `#include`. Para usar o `vector`, por
exemplo, precisamos de:

```c++
#include <vector>
```

Além disso, para maior organização, todos elementos da STL estão dentro de um namespace,
o `std`. Namespaces servem para organizar o código de forma a manter coisas associadas num
mesmo contexto e para evitar conflitos de nome (isto é, para podermos ter funções, structs,
etc. com o mesmo nome).

Por exemplo, a declaração de `vector<T>` é feita mais ou menos assim:

```c++
namespace std {
    template <typename T>
    struct vector {          // na verdade seria uma classe, mas isso não importa agora
        ...
    };
}
```

Como vector foi declarado dentro de um namespace, se quisermos usá-lo precisamos antes
indicar qual namespace ele está. O acesso a elementos de um namespace é feito usando o
separador de escopo `::`.

```c++
std::vector<int> u;    // sem o "std::" o compilador vai dizer que não sabe o que é um vector<T>
```

Para evitar ter que escrever o `std` toda vez, podemos usar o `using` para indicar que queremos
que o vector fique disponível para nós também sem o seu indicador de namespace:

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

> [Namespaces no C++ Reference](https://en.cppreference.com/w/cpp/language/namespace)

### O que é o tal `size_t` ou `size_type`? <a name="sizet"></a>

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

> [`size_t` no C++ Reference](https://en.cppreference.com/w/cpp/types/size_t)

### O caso especial do `vector<bool>`

O `vector<bool>` é definido de forma diferente dos outros vectors, pois ele usa uma representação
compacta de um valor por bit. Com isso ele ocupa potencialmente 8 vezes menos espaço que um
`vector<char>`, por exemplo. Ele também tem alguns métodos específicos, como o `flip()` que inverte
todos os bits do vector.

O uso do `vector<bool>` pode ser problemático em alguns casos porque o acesso aos seus elementos
é levemente mais lento que nos outros vectors, já que ele tem que fazer uns shifts para pegar o
bit exato dentro do byte no qual ele está localizado.

Além de simplesmente usar `vector<char>` ou `bool[]`, uma alternativa ao `vector<bool>` é
o `bitset<size>`, onde n é o número de bits a serem guardados (sim, o argumento de um template pode ser
um número). Apesar de ter a desvantagem de ter um tamanho fixo, o `bitset<size>` tem a vantagem de dar
suporte a várias operações booleanas e conversões a partir de tipos numéricos e strings.

> [`vector<bool>` no C++ Reference](https://en.cppreference.com/w/cpp/container/vector_bool)  
> [`bitset<size>` no C++ Reference](https://en.cppreference.com/w/cpp/utility/bitset)

### Inferência de tipos usando `auto`

// TODO

### Loop em containers: `for (tipo x : container)`]

// TODO

## Referências

* [CPP Reference](https://cppreference.com/)
* [STL Containers](https://en.cppreference.com/w/cpp/container)
* [STL Algorithms](https://en.cppreference.com/w/cpp/algorithm)
* [Compiler Explorer](https://godbolt.org/) - Usado na aula para mostrar o que o computador faz com os templates.
* [Vários links bem úteis para C++](https://en.cppreference.com/w/cpp/links)