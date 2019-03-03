# Laços de Repetição

Nessa aula vamos aprender um pouco sobre repetição, ou seja, trechos de código que queremos executar diversas vezes. Imagine que queremos ler 5 números, e ver se algum deles vale 10. Aprendemos até aqui que isso pode ser feito da seguinte forma:

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, x2, x3, x4, x5;
    cin >> x1 >> x2 >> x3 >> x4 >> x5;

    if (x1 == 10 or x2 == 10 or x3 == 10 or x4 == 10 or x5 == 10)
        printf("Algum deles vale 10");
    else
        printf("Nenhum vale 10");
}
```

Certo, isso funciona. Mas e se quisermos conferir isso para 10 números? Para 50? E para 10^5 numeros? Seria bem complicado fazer dessa forma, ne?

Para isso, existem os laços de repetição. São eles, em C++, o **for**, o **while** e o **do while**.

## For

O comando **for** funciona da seguinte forma:

```c++
    for (int i = 0; i < 10; i = i + 1) {
        // comandos que queremos
    }
```

Um pouco confuso? Nem tanto. Ele sempre será mais ou menos assim:

```c++
    for (inicia_var; condicao_parada; incrementos_var) {
        // comando
    }
```

O primeiro **for** faz o seguinte: ele cria uma variável *i*, que começa com o valor 0. Depois, ele confere se *i* é *menor que* 10. Então, ele executa os "comandos que queremos". Após a execução, o valor de *i* é incrementado em 1, passando a valer 1. Após isso, é feito o teste novamente, *i é menor que 10?* Como *i* agora vale 1, isso é verdade, então os comandos que queremos são executados novamente. Após isso, é feito novamente o incremento de *i*, que passa a valer 2. Novamente, é feito a pergunta condicional, que ainda é verdadeira. E os comandos são executados novamente. E assim por diante, até que *i* vale 9 e é incrementado. Nesse momento, *i* passa a valer 10 e ao fazer a comparação (*i* < 10) teremos *false* como resposta e então a repetição deixa de ser executada.

Representando o exemplo citado anteriormente, de se ler 5 números e checar se algum vale 10:

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    bool flag = false;

    for (int i = 0; i < 5; i++) { //i++ é o mesmo de i = i+1
        int x; scanf("%d", &x);
        if (x == 10) {
            flag = true;
        }
    }

    if (flag == true)
        printf("Algum deles vale 10");
    else
        printf("Nenhum vale 10");
}
```

Agora, se quisermos aumentar o limite de variáveis lidas para 10, 100 ou 1 milhão, é bem simples, pois apenas aumentamos o valor dentro da condição do for.

## Algumas instruções para laços de repetição

Vimos anteriormente que o comando **return** na função *main* simplesmente retorna um valor para o sistema operacional, finalizando o programa, certo? Veremos agora alguns comandos que podem ser utilizados em laços de repetição:

### break;
O laço é interrompido e para imediatamente.

```c++
    for (int i = 0; i < 5; i++) {
        int x; cin >> x;
        if (x == 10) 
            break;
    } //o for ira parar de executar quando o valor lido for igual a 10, ou quando forem lidos 5 valores.
```

### continue;
Os comandos que estão após o *continue* não executam, porém o laço não é interrompido - o sistema finge que os comandos a serem executados acabaram, e volta no incremento das variáveis. É como se "pulassemos" uma execução.

```c++
    for (int i = 0; i < 5; i++) {
        if (i == 2) 
            continue;
        cout << i << " ";
    }
    // output desse programa: 0 1 3 4
```

## While

O *while* fará outro tipo de laço de repetição. Ele é um pouco mais simples, tendo dentro dele apenas a condição de parada. Se pensarmos na sua tradução, teremos uma noção de como ele funciona: **enquanto** uma condição é verdadeira, seu código é executado. Podemos ver a estrutura abaixo:

```c++
    while (condicao_for_verdadeira) {
        // comandos que eu quero
        ...
    }
```

Abaixo, aquele mesmo exemplo de checar se temos um número 10 como entrada, agora usando while:

```c++
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        bool flag = false;

        int i = 0;
        while (i < 5) {
            int x; scanf("%d", &x);
            if (x == 10) flag = true;

            i++;
        }

        if (flag == true)
            printf("Algum deles vale 10");
        else
            printf("Nenhum vale 10");
    }
```

## Do While

O *do while* é como um while, mas tem uma pequina diferença: ele sempre executará no mínimo uma vez, e verificará a condição apenas no final de seu escopo. 

```c++
    do {
        // comandos
    } while (condicao_existencia);    
```

Aquele mesmo exemplo:

```c++
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        bool flag = false;

        int i = 0;
        do {
            int x; scanf("%d", &x);
            if (x == 10) flag = true;

            i++;
        } while (i < 5);

        if (flag == true)
            printf("Algum deles vale 10");
        else
            printf("Nenhum vale 10");
    }
```

Esses comandos são bem básicos, mas são muuuuito úteis. Recomendamos que você faça algumas alterações nos exemplos e teste em casa!