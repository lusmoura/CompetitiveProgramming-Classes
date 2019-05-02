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
  * [Loop em containers: `for (tipo x : container)`](#Loop-em-containers-for-tipo-x--container)
  * [Inferência de tipos usando `auto`](#Inferência-de-tipos-usando-auto)
  * [O problema do `>>`](#shift-ambiguity-problem)
  * [Pair de pairs? Structs? Tuples?](#Pair-de-pairs-Structs-Tuples)
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

Classes em C++ são a mesma coisa que structs, porém com seus elementos privados por padrão.

Veja também [Classes (e, consequentemente, structs)](https://en.cppreference.com/w/cpp/language/class)
no C++ Reference.

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

O acesso aos métodos, assim como os campos, também se dá através de `.` (ponto):

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

Veja também [Templates de funções](https://en.cppreference.com/w/cpp/language/function_template) no C++ Reference.

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

Veja também [Templates de structs (classes)](https://en.cppreference.com/w/cpp/language/class_template)
no C++ Reference.

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
Veja também [`vector<T>` no C++ Reference](https://en.cppreference.com/w/cpp/container/vector).

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
* `void push(T valor)` insere o valor dado no topo da pilha. O próximo `pop()` retirará esse valor
  da pilha.
* `void pop()` retira o topo da pilha. Não faz nada se a pilha estiver vazia. Note que `pop()` não
  retorna o valor que está no topo. Para isso é necessário usar `top()`.
* `T & top()` retorna o valor que está no topo da pilha. Se a pilha estiver vazia, chamar `top()` leva
  a um erro.
* `size_t size()` retorna a quantidade de elementos que está atualmente na pilha.
* `bool empty()` indica se a pilha está vazia ou não. É comum utilizar um `while (not pilha.empty())`
  como condição em algoritmos que utilizam uma pilha.

Note que não é possível acessar um elemento que está no meio da pilha sem antes retirar todos elementos
que estão acima dela usando `pop()`. Não há como fazer `pilha[i]` ou `for (auto x : pilha)`.

Veja também [`stack<T>` no C++ Reference](https://en.cppreference.com/w/cpp/container/stack).

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

* `queue<T>()` cria uma fila vazia.
* `void push(T valor)` insere o valor no final da fila.
* `void pop()` retira o elemento que está no início da fila.
* `T & front()` dá acesso ao valor que está no início da fila.
* `size_t size()` retorna a quantidade de elementos que está atualmente na fila.
* `bool empty()` indica se a fila está vazia ou não. É comum utilizar um `while (not fila.empty())`
  como condição em algoritmos que utilizam uma fila.

Assim como na pilha, não é possível acessar os elementos que estão no meio da fila.

Veja também [`queue<T>` no C++ Reference](https://en.cppreference.com/w/cpp/container/queue).

## `deque<T>`

A `deque<T>` é uma fila de duas pontas. Os elementos podem entrar e sair dela por qualquer um dos
lados. Por exemplo:

```c++
deque<int> d;       //      {}

d.push_front(10);   //     {10}            10 está no início e no começo
d.push_back(30);    //     {10, 30}        30 inserido no final
d.push_front(20);   // {20, 10, 30}
d.push_back(40);    // {20, 10, 30, 40}

d.pop_back();       // {20, 10, 30}
d.pop_front();      //     {10, 30}
d.pop_front();      //         {30}
d.pop_front();      //          {}
```

* `deque<T>()` - inicializar uma deque vazia.
* `deque<T>(size_t count, T value)` - inicializa uma deque com `count` elementos iguais a `value`.
* `deque<T>(initializer_list<T> valores_iniciais)` - inicializa uma deque com os elementos dados. Exemplo:
  ```c++
  deque<int> e = {1, 2, 3, 4, 5};
  ```
* `deque<T>(begin, end)` inicializa a deque com os elementos de outro container que estão entre os iteradores
  passados como argumento. Exemplo:
  ```c++
    vector v<int> = {1, 2, 3, 4, 5};
    deque<int> e(v.begin(), v.end());
  ```
* `T & front()` - dá acesso ao elemento no início da fila. Note que é retornada uma referência e,
  com isso, é possível alterar o valor desse elemento:
  ```c++
  deque<int> d = {1, 2, 3, 4, 5};
  d.front() = 42;           // d agora é igual a {42, 2, 3, 4, 5}
  ```
  Isso também vale para `stack<T>::top()` e `queue<T>::front()`.

* `T & back()` dá acesso ao elemento no fim da fila.
* `void push_front(T value)` insere um valor no começo da fila.
* `void push_back(T value)` insere um valor no final da fila.
* `void pop_front()` retira o elemento que está no início da fila.
* `void pop_back()` retira o elemento que está no final da fila.
* `size_t size()` retorna a quantidade atual de elementos na fila.
* `bool empty()` indica se a fila está sem elementos.

Algumas outras funcionalidades existem na deque, mas têm complexidade O(n) e devem ser evitadas:
* `operator[i]` acessa o i-ésimo elemento da deque

Veja também [`deque<T>` no C++ Reference](https://en.cppreference.com/w/cpp/container/deque).

## `pair<T,U>`

O `pair<T,U>` serve para criar um par de valores que se mantém ligados um ao outro. Por exemplo o valor
de algo e seu nome. Ele é basicamente equivalente a um struct que tem dois campos: `first` e `second`.
Por exemplo:

```c++
pair<double, string> fruta;
fruta.first = 0.25;
fruta.second = "Banana";
```

Uma propriedade muito útil do pair é que ele implementa automaticamente os operadores de comparação e,
com isso, ele já faz automaticamente a comparação entre pairs. A regra é que ele compara usando `first` e,
em caso de empate, o desempate é feito usando o `second`. Por exemplo:

```c++
vector< pair<double, string> > frutas = {
    {1.31, "Banana Prata"},
    {1.90, "Goiaba"},
    {0.90, "Mamao Formosa"},
    {0.90, "Manga Rosa"},
    {3.00, "Abacate"},
    {1.90, "Abacaxi"},
    {0.90, "Banana Nanica"}
};

sort(frutas.begin(), frutas.end());

for (auto v : frutas) {
    printf("%5.2lf %15s\n", v.first, v.second.c_str());
}
```

imprime

```
 0.90   Banana Nanica
 0.90   Mamao Formosa
 0.90      Manga Rosa
 1.31    Banana Prata
 1.90         Abacaxi
 1.90          Goiaba
 3.00         Abacate
```

<!-- TODO construtores e funções -->
<!-- TODO make_pair -->

Veja também [`pair<T>` no C++ Reference](https://en.cppreference.com/w/cpp/utility/pair).

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

Veja também [`priority_queue<T>` no C++ Reference](https://en.cppreference.com/w/cpp/container/priority_queue).

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

Veja também:
* [`vector<bool>` no C++ Reference](https://en.cppreference.com/w/cpp/container/vector_bool)
* [`bitset<size>` no C++ Reference](https://en.cppreference.com/w/cpp/utility/bitset)
* [Especialização de template no C++ Reference](https://en.cppreference.com/w/cpp/language/template_specialization) -
  usado para dar uma implementação específica para o `vector<bool>`

### Loop em containers: `for (tipo x : container)`

Quando se deseja passar por todos os elementos de um container, é mais fácil usar uma outra forma
de for-loop:

```c++
vector<int> v = {1, 2, 3, 4, 5};
for (int x : v) {
    cout << x << " ";
}
```

Um detalhe importante acima é que `x` vai recebendo sucessivamente **cópias** dos elementos de `v`.
Ou seja, se eu mudar o valor de `x` dentro do loop, essa mudança não será refletida em `v`.
Caso seja necessário mudar os valores do container, é necessário marcar `x` como uma referência,
usando o modificador `&`.

```c++
for (int & x : v) {
    x = x * x;
}
// Agora v == {1, 4, 9, 16, 25}
```

### Inferência de tipos usando `auto`

Quando temos tipos muito complicados, podemos usar o `auto` no lugar do tipo na declaração de variáveis.
Por exemplo, se queremos passar pelos elementos de um vetor:

```c++
vector< pair<int, pair<int, char> > > v;
...
for (pair<int, pair<int, char> > x: v) {
    ...
}
```

é bem chato lembrar e escrever o tipo do elemento do vetor. Para evitar esse retrabalho, usamos `auto`:

```c++
for (auto x: v) {
    ...
}
```

Também é possível usar `auto` para coisas mais simples:

```c++
auto i = 10; // i é um int
auto x = 10ULL; // x é um unsigned long long (por causa do sufixo ULL no valor literal)
auto c = 'X'; // c é um char
```

### O problema do `>>` <a name="shift-ambiguity-problem"></a>

Em versões antigas de C++ os compiladores não eram espertos o suficiente para diferenciar o operador de shift
`>>` do fechamento de dois parâmetros de templates (por exemplo, o `>>` no final de `vector<vector<int>>`).
Com isso, nós éramos obrigados a usar espaços para separar os `>`s e, assim, retirar a ambiguidade: `vector<vector<int> >`.

Ficamos avisados disso, então, pois em algumas competições pode ocorrer disso ser um problema, dada uma versão
antiga do compilador.

### Pair de pairs? Structs? Tuples?

Caso se queira mais de dois campos num `pair`, uma possibilidade é criar um pair de pairs:

```c++
pair< string, pair<double, string> > x = {"kg", {0.90, "Banana Nanica"}};

// x.first == "kg"
// x.second.first == 0.90
// x.second.second == "Banana Nanica"
```

Mas a partir daí a confusão pode ser tanta que talvez você prefira criar um struct:

```c++
struct Fruta {
    double preco;
    string nome, unidade;

    bool operator<(Fruta const & that) const { // temos que implementar o "<"" na mão
        // mas podemos fazer isso facilmente usando o std::tie
        return tie(this->unidade, this->preco, this->nome) < tie(that.unidade, that.preco, that.nome);
    }
};

vector<Fruta> frutas = {
    {1.31, "Banana Prata", "kg"},
    {1.90, "Goiaba", "kg"},
    {0.90, "Mamao Formosa", "kg"},
    {0.90, "Manga Rosa", "kg"},
    {3.00, "Abacate", "unidade"},
    {1.90, "Abacaxi", "unidade"},
    {0.90, "Banana Nanica", "kg"},
};

sort(frutas.begin(), frutas.end());

for (auto v : frutas) {
    // melhor que lembrar o que é v.first.second:
    printf("%10s %5.2lf %15s\n", v.unidade.c_str(), v.preco, v.nome.c_str());
}
```

Outra possibilidade é usar tuplas, que são como pairs, mas com um número qualquer de elementos:

```c++
vector< tuple<string, double, string> > frutas = {
    {"kg", 1.31, "Banana Prata"},
    {"kg", 1.90, "Goiaba"},
    {"kg", 0.90, "Mamao Formosa"},
    {"kg", 0.90, "Manga Rosa"},
    {"unidade", 3.00, "Abacate"},
    {"unidade", 1.90, "Abacaxi"},
    {"kg", 0.90, "Banana Nanica"},
};

sort(frutas.begin(), frutas.end()); // tuple já faz a comparação e desempates

for (auto v : frutas) {
    // Usamos get<posicao do campo>(tupla) para pegar o valor de cada campo:
    printf("%10s %5.2lf %15s\n", get<0>(v).c_str(), get<1>(v), get<2>(v).c_str());
}
```

Veja também:
* [`tuple<T>` no C++ Reference](https://en.cppreference.com/w/cpp/utility/tuple)
* [`tie` no C++ Reference](https://en.cppreference.com/w/cpp/utility/tuple/tie)

## Referências

* [C++ Reference](https://cppreference.com/)
* [STL Containers](https://en.cppreference.com/w/cpp/container)
* [STL Algorithms](https://en.cppreference.com/w/cpp/algorithm)
* [Compiler Explorer](https://godbolt.org/) - Usado na aula para mostrar o que o compilador faz
  para gerar os códigos específicos dos templates.
* [Vários links bem úteis sobre C++](https://en.cppreference.com/w/cpp/links)
