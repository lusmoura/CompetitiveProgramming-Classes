# Complexidade 

## A ideia geral: Analisando a eficiência e o tempo de execução de algoritmos.  :runner:

Em programação competitiva, a eficiência de um programa e o tempo de execução é crucial. 
Eu imagino que vocês que estão lendo esse blog e que já resolveram exercícios de programação competitiva, já tiveram problemas com tempo 
de execução (os famosos TLE), mas não souberam como lidar ou analisar a fonte de tais problemas.

Aqui estamos então: é hora de explicar porque certos códigos não são capazes de serem executados **abaixo de um certo limite de tempo**
dada uma **certa entrada**.

De maneira geral, a **complexidade de um algoritmo** é uma estimativa para o número de operações que o programa executaria, dada uma certa
entrada. Com base no número de operações, podemos por fim estimar o tempo necessário para a execução e determinar se o programa iria ser
capaz de satisfazer um limite de tempo.

## Mas como a entrada se relaciona com o número de operações?

#### Suponhamos por exemplo, que certo exercício de programação competitiva gere um número aleatório **n** em cada caso de teste.

  Seja **n**, tal que:

    1 < n < 10000

#### Suponhamos então, que dois programadores, Fakhinho e Cabralzinho construíram duas implementações (códigos) diferentes que resolvessem tal problema.

  Assim: 

  - Seja a **função f**, que para dado **n**, nos diz o número de operações que **o código de Fakhinho realiza**:

    - `f(n) = 2n² + 5n + 5` operações.

  - Seja a **função g**, que para dado **n**, nos diz o número de operações que **o código de Cabralzinho realiza**.

    - `g(n) = 500n + 400` operações.
 
  É evidente pelas funções **f** e **g** mostradas acima que, quanto maior o valor de **n** dado pelo caso de teste, maior é o número de operações realizadas.
  
#### No entanto, o computador leva certo tempo para realizar uma operação, dessa forma, temos a seguinte implicação:
  
    Maior valor de n -> Maior número de operações -> Maior tempo de execução do programa.
  
  Dessa forma, percebemos que **para reduzir o tempo de execução de um problema**, devemos **reduzir o número de operações que o mesmo realiza**.
  
  Em programação competitiva, é comum se usar como base o valor máximo da entrada para a análise do algoritmo, visto que esse causaria
  o tempo máximo de execução e nos deixaria claro se o nosso programa iria ser executar abaixo do limiar de tempo de um exercício.
  
## A notação Big-O
  
  #### Para avaliar a eficiência de um algoritmo, é comum se utilizar diferentes notações. Em programação competitiva usamos uma notação especial para comparar funções que descrevem o número de operações. essa notação se chama **Big O**.

  - Tomemos a **função f(n) = 2n² + 5n + 5** do tópico anterior e seja uma nova função **h(n) = n²**.
  
  - Podemos dizer que **a função f** é **O(h(n))** ou **O(n²)**, isto é: `Para valores grandes, f e h possuem eficiência similar.`
  
  - Uma mensagem importante que a notação Big-O nos passa é: 
  
    - Conforme n cresce **linearmente**, os valores f(n) e h(n) crescem **quadraticamente**.
      Portanto, a notação nos diz que **todas as funções quadráticas são O(n²)**.
  
  - Outro aspecto importante a adicionar: 
    
    - Na análise assintótica. Apenas o termo com maior grau é levado em conta. Ou seja, por mais que **f(n)** possua um termo **5n**
      e um termo 5, esses são desconsiderados na análise.
  
  Isso tudo pode ter ficado um pouco abstrato, mas não se preocupe, tudo ficará mais claro com exemplos.
  
## Mas como dizer a complexidade de um algoritmo? :computer:

De maneira geral, com exceção dos grandes algoritmos e funções (que as vezes possuem demonstrações complexas e elaboradas sobre as suas complexidades), o foco da análise da complexidade em um código são os laços de repetição. Por exemplo:

```c++
for(int i = 0; i < n; i++){
    // x operações (nao dependem de n)
}
```

No laço acima, **x operações** são executadas **n vezes**. Portanto, podemos dizer que a complexidade geral é O(n). É importante 
notar que **x não depende de n**, e portanto é desconsiderado na notação.

Além disso, podemos dizer que a complexidade de **um algoritmo O(n)** que é executado **por outro algoritmo O(n)** tem complexidade
**O(n²)**, isto é:

```c++
// codigo externo \/
for(int i = 0; i < n; i++){ 

    // codigo do exemplo anterior \/
    for(int j = 0; j < n; j++){
        // x operaçoes (nao dependem de n)
    }
    // codigo do exemplo anterior /\
}
// codigo externo /\

```
Aqui, o código do exemplo anterior, que possui **complexidade O(n)**, foi executado **n vezes**. Dessa forma, a complexidade geral do código externo é **O(n²)**.

E quanto ao código abaixo, qual você acha que é a notação Big-O para ele?

```c++
int a = 3;
int b = 2;
int x = a + b;
int y = a - b;
```

A complexidade é **O(1)**!

O código não depende de n, e sempre executa um número constante de operações.

## O que todos estávamos esperando: a estimativa do tempo :clock1: 

Chegamos então ao que todos queremos saber:

- Como relacionar o número de operações e o tempo de execução?
- Como eu vou saber se meu código vai rodar em menos de 1 segundo ????

Na maratona, uma estimativa utilizada em C++ é: **10⁸ operações levam em média 1 segundo para serem executadas**!

Um algoritmo que executa **10⁹ operações**, por exemplo, levaria **em média 10 segundos** para ser executado, visto que **10⁹ = 10⁸ . 10**

Suponhamos portanto que **você, programador competitivo**, criou um algoritmo capaz de resolver um problema em complexidade **O(n²)**. **Para valores até 10⁴**, seu código **pode ser executado em menos de 1 segundo!**

Por outro lado, digamos que o exercício diga que **n está entre 1 e 10⁶** e o limite de tempo seja **3 segundos**. 

Nesse exemplo, Seu código não iria ser eficiente o suficiente, visto que em um caso de teste **n = 10⁶**, seu código calcularia **(10⁶)²** ou **10¹²** operações, o que é equivalente a **10⁴ segundos** :cry:

## Mais exemplos!

### Qual é a complexidade do código abaixo?

```c++
for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            // operaçoes constantes
        }
    }
}
```
 
<details><summary> Clique para ver a Resposta </summary>
  
   <b>  O código acima é O(n³).</b>
</details>





### Digamos que queremos calcular a **soma dos n primeiros números naturais**. Quais são as diferentes formas de resolver esse problema Qual é a diferença de eficiência entre elas?
  
<details><summary> Clique para ver a Resposta </summary>
  
#### Uma primeira maneira de pensar no problema é a versão **ad-hoc** da solução, ou seja, simplesmente somar os n primeiros termos. Da seguinte forma:
  
  ```c++
  int sum = 0;
  for(int i = 1; i <= n; i++){
      sum += i;
  }
  ```
  
#### No entanto, essa solução é O(n)... e podemos fazer melhor! Uma segunda maneira seria usar a fórmula da soma de P.A.!
  
  ```c++
  int sum = ((1+n)*n)/2;
  ```
  
#### Essa solução é O(1) e portanto mais eficiente.
  
</details>
