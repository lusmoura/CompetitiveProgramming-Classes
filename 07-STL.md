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

    vetor3d(double a, double b, double c) { // construtores não têm tipo de retorno e têm o mesmo nome do struct
        x = a;
        y = b;
        z = c;
    }
};
```

Agora podemos criar um `vetor3d` muito mais facilmente:

```c++
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
    T x;
    T y;
    T z;
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

A seguir um exemplo de template com mais de um tipo e seu uso:

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
é que isso é feito automaticamente (quando se usam os métodos de inserção/remoção). Exemplo:

```c++
vector<int> v;   // inicialmente v tem tamanho zero
v.push_back(1);  // agora v = |1|
v.push_back(2);  // v = |1, 2|
v.push_back(3);  // v = |1, 2, 3|

// o acesso aos elementos é feito igual a um array: vetor[indice]
v[1] = 10;       // v = |1, 10, 3|

// mas ainda é um erro tentar acessar uma posição que não existe:
v[50] = 32;      // segmentation fault!
```

O método `push_back` aloca automaticamente mais uma posição de memória para o vetor.

// TODO

## Iteradores

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
