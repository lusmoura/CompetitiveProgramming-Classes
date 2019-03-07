# Introdução à Linguagem C/C++

Introduziremos agora à linguagem C++ (e também um pouco da linguagem C), normalmente utilizada em programação competitiva pela sua eficiência e simplicidade.

Antes de começar, é bom dizer que o que fazemos em C (e que estará mais a frente) também pode ser feito em C++. Para as aplicações que utilizaremos, se simplesmente pegarmos um código em C, salvarmos com a extensão .cpp e compilarmos, tudo será executado normalmente.

As partes de código precedidas de *//* são comentários. Eles são ignorados no processo de compilação e execução do código, mas facilitam o entendimento do programador e de outras pessoas que possam vir a ler o código.

Recomendamos que, durante a leitura, você tente fazer os códigos ou pelo menos executar os exemplos mostrados.

# Estrutura básica em C

```c
int main() { //função principal do código, a partir da qual a execuço é iniciada
    // aqui voce escreve seu código
}
```

Falaremos agora sobre **variáveis**.

Variáveis são tipos de dados, que podem armazenar determinados valores, de acordo com suas especificações. Os principais tipos de dados são:
1. *int* - armazena números inteiros, no intervalo de -2^31 até +(2^31) - 1 (da ordem de -10^9 para 10^9).
2. *char* - armazena números pequenos (-128 a 127) ou caracteres do tipo ASCII.
3. *float* - armazena valores reais.
4. *double* - armazena valores reais, com maior capacidade de precisão.

Para declarar uma variavel, deve-se fazer o seguinte:

```c
#include <stdio.h>

int main() {
    //tipo_da_variavel nome_da_variavel
    int x; //tipo int e nome x
    char c;
  
    x = 10; //atribuição de valor à variável
    c = 'a'; // caracteres são representados por aspas simples
  
    int n = 23; //também é possível atribuir um valor à variável na sua inicialização
  
    return 0;
}
```

Nesse código apenas declaramos algumas variáveis e assinalamos algum valor à elas. Podemos, porém, melhorá-lo. Para isso, importaremos e utilizaremos *bibliotecas*, que são como códigos que possuem funções já implementadas, por exemplo, para a entrada e saída de dados.

```c
#include <stdio.h> //biblioteca "standart input and output"

int main() {
    printf("Hello World\n");
    return 0;
}
```

O código acima imprime a mensagem "Hello World", com uma quebra de linha no final (o *\n* pula a linha da saída - falaremos mais sobre as chamadas 'máscaras' do printf mais a frente). Portanto, o comando *printf()* serve para imprimir coisas na tela. Mas e se quisermos ler uma entrada (input) do usuário?

```c
#include <stdio.h>

int main() {
    int x;
    printf("Digite um número: ");
    scanf("%d", &x); //lendo o valor de x
    
    printf("O número lido foi: %d\n", x); //imprime uma frase com o valor de x, com uma quebra de linha no final
    return 0;
}
```

Essas funções podem parecer confusas no começo, mas elas são bastante úteis e comumente utilizadas. 
Tanto o scanf quanto o printf funcionam com "máscaras", que dizem à função qual tipo de valor será lido/escrito. No código acima vemos o *%d* no printf e scanf. Isso representa um *sinal* à função, que saberá que deve imprimir um valor do tipo inteiro naquela parte do código. Essas são as principais máscaras:

1. *%d* tipo inteiro
2. *%f* tipo float
3. *%lf* tipo double (long float)
4. *%c* tipo char

Também é possível ler e imprimir mais de uma variável ao mesmo tempo:

```c
#include <stdio.h>

int main() {
    int x, y; //cria uma variavel x e outra y - poderia ser em duas linhas separadas, mas podemos separar por vírgulas também.
    scanf("%d%d", &x, &y); //lendo o valor de x e de y
    
    printf("Você digitou %d e %d\n", x, y);
    return 0;
}
```

Sem crise até aqui, certo? Vamos falar agora sobre operações que podemos fazer com variáveis. As principais são:
1. a + b, soma a e b
2. a - b, subtrai b de a
3. a * b, multiplica a e b
4. a / b, divide a por b
5. a % b, resto da divisão de a por b

```c
int main() {
    int x = 15, y = 2;
    
    int soma = x + y; //a = 15+2, ou seja, soma = 17
    int subt = x - y; //subt = 13
    int mult = x * y; //mult = 30
    
    int div = x / y; //div = 15/2, ou seja, div = 7 (hm... blz né, é inteiro...)
    float div_real = x / y; //div_real = 7 (eita, mas agora é float... não deveria ser 7.5??)
    
    int resto = x % y; //resto = 15%2, ou seja, resto = 1 (pois 15 dividido por 2 temos resto 1)
    
    return 0;
}
```

Simples, não? Agora, por que 15/2 é igual a 7 mesmo com a variável div_real sendo do tipo float?

Estamos falando de operações com **números inteiros**. Ou seja, não podemos considerá-los números reais. Quando vamos mexer com variáveis inteiras em C ou em C++, todas as operações envolvidas com elas resultarão valores inteiros. Portanto, se quisermos que 15/2 resulte algo como 7.5, devemos converter algum número inicial (15 ou 2) para um tipo real (float ou double) ou fazer o chamado "casting", ou seja, forçar uma variável a atuar como se fosse de outro tipo. Desse jeito:

```c
int main() {
    int x = 15;
    double y = 2; 
    
    double a = x / y; //agora sim, a = 7.5
    
    //também seria possível fazer o casting:
    int xx = 15, yy = 2;
    double aa = xx / (double)yy;
    
    return 0;
}
```

# Comandos Condicionais

Outros comandos muito úteis são os condicionais. Isto é, fazemos linhas de código que apenas executam caso alguma condição seja satisfeita. Desse jeito:


```c
#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    
    if (x == 1) {
        printf("Você digitou o valor 1\n");
    } else {
        printf("Você digitou algum valor que não é 1\n");
    }
    
    return 0;
}
```

Deu pra ter uma base, certo? Caso a condiço dentro dos parenteses seja satisfeita (verdadeira), serão executados os comandos que estão dentro das chaves após o *if*. Caso contrário (se a condição for falsa), poderemos adicionar também um comando *else* (senão). Essa condição é estabelecida de acordo com alguns operadores:

1. a == b -> a expressão é *verdadeira* caso a seja **igual** a b (importante notar que caso queiramos fazer uma comparação, devemos utilizar '=='. Apenas um '=' significa uma atribuição, como já vimos)
2. a != b -> a expressão é *verdadeira* caso a seja **diferente** de b
3. a < b -> a expressão é *verdadeira* caso a seja **menor** que b
4. a > b -> a expressão é *verdadeira* caso a seja **maior** que b
5. a <= b -> a expressão é *verdadeira* caso a seja **menor ou igual** a b
6. a >= b -> a expressão é *verdadeira* caso a seja **maior ou igual** a b

No código abaixo vemos também um novo comando: "else if". Ele vem logo após um if e só será executado caso sua condição seja verdadeira e a condição do if anterior não tenha sido satisfeita.
Sugerimos que você brinque um pouco com o código a seguir, testando comandos, valores e operadores diferentes.
```c
#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    
    if (a + b == 10) {
        printf("A soma é 10\n");
    } else if (a + b == 15) {
        printf("A soma é 15\n");
    } else {
        printf("A soma não dá isso não\n");
    }
    
    if (a * b == 32)
        printf("A multiplicação dá 32.\n");
    
    return 0;
}
```

Podemos também aprimorar as condições com as cláusulas and e or.
Para o and (&&), o if será executado apenas se ambas as condições forem satisfeitas. Já utilizando o or (||), basta que no mínimo uma delas seja verdadeira, como pode ser observado a seguir.

```c
#include <stdio.h>

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    
    if (x == 1 && y == 1) { // && é o comando de AND em C
        printf("Tanto x quanto y são 1.\n");
    } else if (x == 1 || y == 1) { // || é OR em C
        printf("Algum dos dois vale 1\n");
    } else {
        printf("Nenhum valor vale 1.\n");
    }
    
    return 0;
}
```

## Cuidado!

É comum cometer **erros lógicos** ao se lidar com condicionais. Dentre eles, tentar comparar uma variável com diversos valores da seguinte forma:

```c
if(x == 1 || 2 || 3 || 4)
```
Lembre-se sempre que comparações sempre são interpretadas pelo computador em pares: no caso anterior, `x` está sendo comparado com `(1 || 2 || 3 || 4)`, e essa não era a nossa intenção. Portanto, a forma correta seria:

```c
if(x == 1 || x == 2 || x == 3 || x == 4)
```

Outro erro recorrente é trocar a comparação de igualdade `==` com a atribuição `=`:

```c
if(x = 1){
    ...
}
```

# C++
Bom, essa é foi introdução à programação em C. Agora, vamos ver algumas coisas que podemos fazer em C++, e que ajudarão na maratona de programação.

Como foi dito no início, podemos usar em C++ os mesmos comandos que utilizamos em C. Mas também podemos fazer as coisas de um jeito um pouco diferente. Podemos, por exemplo, utilizar os comandos 'cin' e 'cout' para substituir o scanf e o printf, uma vez que, com eles, não precisamos das máscaras para os diferentes tipos de variáveis.

```c++
#include <bits/stdc++.h> //em vez de usar bibliotecas específicas, vamos usar essa aqui que tem tipo TUDO
using namespace std; //indicaremos que estamos usando o namespace std, mas não precisa entender isso agora. Só aceita por enquanto

int main() {
    int x;
    cin >> x; //equivalente à scanf("%d", &x);
    
    cout << "X vale: " << x << "\n"; //equivalente ao printf("X vale %d\n", x);
    
    int a;
    double b;
    cin >> a >> b; //lendo a e b mesmo sendo de tipos diferentes
    if (a == 2 and b == 3.0) { //em C++, podemos também usar "and" e "or"
        printf("a é 2 e b é 3.\n");
    }
    
    return 0;
}
```

# Overflow e o tipo *long long*

Bom, como foi dito anteriormente, cada tipo de variável possui um limite para os valores que pode armazenar. Isso se dá devido a quantidade de bits e bytes que uma variável reserva na memória. Portanto, se eu digitar um valor muito grande (ou muito pequeno) em algum dos tipos citados anteriormente, acontece o chamado *overflow* - a sua variável não possui bits necessários para representar o valor inserido, e fica com um valor totalmente diferente do esperado.

Esses valores dependem da arquitetura utilizada, mas, por exemplo, um tipo *int* possui, normalmente, 32 bits (4 bytes). Isso quer dizer que ele pode armazenar 2^32 números. Podemos calcular esse valor com aquele esquema de combinatória, uma vez que temos 32 "espaços" que podem ser preenchidos com 0 ou 1, a fim de representar número desejado. Se quiser saber mais sobre o sistema binário é só clicar [aqui](https://pt.wikipedia.org/wiki/Sistema_de_numera%C3%A7%C3%A3o_bin%C3%A1rio).

Portanto, um *int* suporta valores até aproximadamente 2 * 10^9. Se precisarmos utilizar valores maiores, existe o tipo *long long*, que possui 64 bits (8 bytes). Portanto, ele pode suportar o dobro de valores de um int, valores, estes, que vão até aproximadamente 9.10^18, normalmente o necessário para as contas em programação competitiva. Mesmo assim, em alguns exercícios específicos, isso pode não ser o suficiente, sendo necessário o tipo BigInt - mas não precisa se preocupar com isso (ainda).

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x; //lendo o valor de x - pode ser bem grande

    cout << x << endl; //imprimindo o valor de x do jeito c++
    printf("%lld\n", x); //imprimindo o valor de x do jeito C (a mascara do printf é %lld ou %I64d)
    return 0;
}
```

# O tipo boolean

Existe também outro tipo de variável interessante que é bastante utilizado. Esse é o tipo *bool*, que tem apenas um byte, ou seja simplesmente armazena dois valores - *true* ou *false* (1 ou 0). Em C, é preciso adicionar uma biblioteca para poder utilizá-los, mas em C++ ele é um tipo nativo.
Ele é útil, dentre outras coisas, para armazenar alguma informação que depois será usada em um comando condicional *(if e else)*. Abaixo, um exemplo (um tanto quanto inútil) de funcionamento:

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    bool flag = false;

    int x; scanf("%d", &x);
    if (x == 5)
        flag = true;

    if (flag == true)
        printf("hmm é true hein");
    else
        printf("hmm é false hein");
}
```

# Probleminha

Aqui vai um problema que aborda alguns dos principais conceitos vistos nessa aula:

Um grande restaurante em São Carlos, conhecido por muitos como *podrão*, está fazendo uma formidável promoção: serão distribuídos **N** litros de óleo para o primeiro grupo de pessoas que chegar lá, com a seguinte condição: o óleo sera dividido pelo grupo, e cada pessoa do grupo deverá receber quantidades **iguais** de óleo. Ou seja, os N litros de óleo deverão ser repartidos igualmente entre todos os integrantes do grupo. Vendo essa inigualável promoção, a famosa esportista *Limora* decide, rapidamente, formar um grupo de **K** pessoas para ir ao podrão. Porém, no meio do caminho até lá, teve uma dúvida: será que eles conseguirão ganhar a promoção?

Dados a quantidade **N** de litros de óleo e **K** de pessoas no grupo, informe se Limora ganhará a promoção.

**Entrada**: N e K, 2 <= N <= 100, 2 <= K <= N.

**Saída**: se for possível para Limora ganhar a promoção, apresente "MENOS CINCO ANOS DE VIDA" (sem aspas). Caso contrário, informe "NÃO VAI TER HIPERTENSAO".

<details><summary>Código com a solução para o problema</summary>

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; //declaracao das variaveis
    cin >> n >> k; //leitura delas

    if (n%k == 0) // se k divide n, o resto da divisao eh 0
        cout << "MENOS CINCO ANOS DE VIDA\n"; //ganharam a promocao
    else
        cout << "NAO VAI TER HIPERTENSAO\n";  //nao ganharam a promocao

    return 0; //fim do codigo
}
```
</details>
