# STL - Standard Template Library

## Structs

Uma struct serve para criar um tipo de dads composto. Por exemplo, um struct aluno poderia ser:

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

## Templates

Templates permitem que um mesmo código sirva para vários tipos de dados. Em resumo, o código é genérico
e pode ser reutilizado para várias situações.

### Templates de funções

Suponha que precisamos de várias funções para calcular o máximo entre dois valores, para os tipos `int`, `long long`, `float` e `double`. Ao invés de criar 4 funções, podemos criar a função genérica a seguir:

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

### Templates de structs/classes

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

Para declarar uma variável, é necessário identificar entre `< >` qual é(são) o(s) tipo(s) concretos.
Por exemplo, se queremos um `vetor3d` de `int`s, temos que usar `vetor3d<int>` como o tipo da variável:

```c++
vetor3d<int> v;
v.x = 1;
x.y = -5;
v.z = 23;
```

## STL

A STL é a biblioteca padrão de C++ que nos dá alguns algoritmos e estruturas de dados prontas para uso.
Seu nome é _Standard **Template** Library_ justamente porque esses algoritmos e estruturas utilizam templates
para serem genéricos.

## `vector<T>`

```c++
```

## Iteradores

Mostrar rapidamente um uso de lambdas no sort()?

## `stack<T>`

## `queue<T>`

## `pair<T,U>`

## `priority_queue<T>`

## `set<T>`

## `map<T,U>`

## Algoritmos da STL

### sort
### first, last
### find
### unique
### lower_bound, upper_bound

## Referências

* [CPP Reference](https://cppreference.com/)
* [STL Containers](https://en.cppreference.com/w/cpp/container)
* [STL Algorithms](https://en.cppreference.com/w/cpp/algorithm)
