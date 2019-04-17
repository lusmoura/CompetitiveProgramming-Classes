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
    aluno prei;                // variável do novo tipo "aluno"
    prei.num_usp = 107108109;  // é usado "." para acessar os campos do struct
    prei.ano_entrada = 2018;
    ...
}
```

> Note que, em C++, ao contrário de C, não é necessário usar `struct` antes da declaração de
> uma variável que tem um struct como tipo. Com isso, também não é necessário usar o
> truque do `typedef struct _ { ... } aluno;`.

## Templates

### Templates de funções



### Templates de structs/classes

`max()`

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
