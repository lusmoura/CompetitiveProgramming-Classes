# Introdução à Linguagem C/C++

Conceitos fundamentais da aula 02 (introdução C, C++):

## Template padrão de c++:
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    //codigo vai aqui
    return 0;
}
```

## Declaração de variáveis:
```c++
tipo_var nome_var;
//em que tipo pode ser int, char, float, double, long long...
```

## Leitura de variaveis:
```c++
//leitura de inteiro:

scanf("%d", &nome_var);
//ou
cin >> nome_var;
```

## Impressao na tela
```c++
//impressao de inteiro:

printf("%d", nome_var);
//ou
cout << nome_var;
```

Lembrando que o '\n' é um caractere que representa a *quebra de linha*.

## If-Else
```c++
if (condicao) {
    //codigo
}
```