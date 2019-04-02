# Complexidade 

## A ideia geral: Analisando a eficiência e o tempo de execução de algoritmos.  :runner:

Em programação competitiva, a eficiência de um programa e o seu tempo de execução são fatores cruciais e devem ser analisados.
Eu imagino que vocês, que estão lendo esse blog e já resolveram exercícios de programação competitiva, já tiveram problemas com tempo de execução (os famosos TLE - *time limit exceeded*). Talvez não souberam como lidar ou analisar a fonte de tais problemas, então aqui estamos: é hora de explicar porque certos códigos não são pode executados abaixo de um certo limite de tempo dada uma certa entrada.

De maneira geral, a **complexidade de um algoritmo** é uma estimativa do número de operações que o programa executa para uma certa entrada. Com base no número de operações, podemos por fim estimar o tempo necessário para a execução e determinar se o programa iria ser capaz de satisfazer um limite de tempo.

## Mas como a entrada se relaciona com o número de operações?

#### Veja esse código como exemplo:

```c++
for (int i = 1; i <= n; i++) {
  int a = i * 2;
  printf("%d ", a);
}
```

Esse código executa o *printf* e a atribução **n** vezes, certo? Portanto, vemos que o número de operações depende do valor de **n**, isto é, quanto maior for **n**, mais vezes esse trecho de código será executado. Mais que isso, podemos escrever uma função que nos diz a quantidade de operações realizadas de acordo a todas as funções realizadas. Nesse caso, por exemplo, são executadas *n vezes* o *int a = i * 2* e mais *n vezes* o printf. Sendo assim, a função desse código seria mais ou menos assim:

- `f(n) = 2n`


## A relação entre a função e a eficiência

#### Suponhamos por exemplo, que certo exercício de programação competitiva possui um valor des **n** em cada caso de teste.

  Seja **n**, tal que:

    1 < n < 10000

#### Suponhamos então, que dois programadores, Fakhinho e Cabralzinho construíram duas implementações (códigos) diferentes que resolvessem tal problema *hipotético*, e que o número de operações de ambos os códigos dependam do valor de n , ou seja, são definidos por uma função como a que vimos acima, da seguinte forma:

  - Seja a **função f**, que para dado **n**, nos diz o número de operações que o código de Fakhinho realiza:

    - `f(n) = n² - 5n + 5` operações.

  - Seja a **função g**, que para dado **n**, nos diz o número de operações que o código de Cabralzinho realiza.

    - `g(n) = 2n + 400` operações.
 
  Podemos notar pelas funções **f** e **g** mostradas acima que, quanto maior o valor de **n** dado pelo caso de teste, maior é o número de operações realizadas. O gráfico abaixo ilustra o crescimento de cada uma das funções de acordo ao crescimento do valor de **n**:

  COLOCA O GRAFICO AQUI

  Analisando-o, vemos que o código de Fakhinho, que é quadrático (ou seja, tem 2 como maior grau) cresce muito mais rápido que o código linear (que tem 1 como maior grau) de Cabralzinho. Isso quer dizer que quando maior o n, mais tempo demora o código de Cabralzinho, mas mais tempo ainda demora o de Fakhinho.
    
  Isso tudo nos mostra que:\
    - Maior valor de n -> Maior número de operações -> Maior tempo de execução do programa.\
    - Maior grau da equação -> n cresce muito mais rápido -> Número de operações cresce muito mais -> Programa demora muito.
  
  Dessa forma, percebemos que **para reduzir o tempo de execução de um programa**, devemos **reduzir o número de operações que o mesmo realiza**.
  
## A notação Big-O
  
  A primeira colocação importante quando falamos de cálculo de complexidade é que usamos como base o valor máximo da entrada para a análise do algoritmo. Uma vez que esse é o valor que causa o tempo máximo de execução, se ele for baixo o suficiente, sabemos que qualquer outro será.
  
  Em seguida, é bom saber que, para avaliar a eficiência de um algoritmo, é possível utilizar diferentes notações, chamadas notações assintóticas. Essas notações servem para comparar o crescimento de funções que descrevam a quantidade de operações que algoritmos fazem. Para programação competitiva, a notação mais importante se chama **Big O**. Ela busca descrever o comportamento do número de operações que algoritmos fazem, considerando o pior caso (isto é, o mais pesado, o que exija mais operações) possível.
  
  Em geral, podemos dizer que o big-O de uma função representa o elemento mais relevante da função que descreve a execução do código. Ou seja, nos exemplos anteriores, o código de Fakhinho é O(n²) (em português, pronunciamos "Ó de n²"), já que esse é o maior valor da função, enquanto o código de Cabralzinho é O(n) pelo mesmo motivo.

  De uma forma mais matemática:

  - Tomemos a **função f(n) = 2n² + 5n + 5** do tópico anterior e seja uma nova função **h(n) = n²**.
  
  - Podemos dizer que **a função f** é **O(h(n))** ou **O(n²)**, isto é: `Para valores grandes, f e h possuem comportamento (eficiência) similar.`
  
  - Uma mensagem importante que a notação Big-O nos passa é: 
  
    - Conforme n cresce **linearmente**, os valores f(n) e h(n) crescem **quadraticamente**.
      Portanto, a notação nos diz que **todas as funções quadráticas são O(n²)**.
  
  - Outro aspecto importante a adicionar: 
    
    - Na análise assintótica (ou seja, na busca do valor do big-O), apenas o termo com maior grau é levado em conta. Ou seja, por mais que **f(n)** possua um termo **5n** e um termo 5, esses são desconsiderados na análise.s
  
  Isso tudo pode ter ficado um pouco abstrato, mas não se preocupe, tudo ficará mais claro com exemplos.
  
  Exemplo 1-\
    Um código com função f(n) = n³ + 100n² + 1000n + 100000 é O(n³)\

  Exemplo 2-\
    Um código com função f(n) = n * log(n) + 300n é O(n * log(n))\

  Exemplo 3-\
    Um código com função f(n) = n² * log(n) + 300n * log(n) é O(n² * log(n))\


## Mas como calcular efetivamente a complexidade de um algoritmo? :computer:

Boa notícia: para calcular a complexidade de um algorítmo não é preciso encontrar a função que o define explicitamente. Muitas vezes essas funções tem coeficientes estranhos e são difíceis de calcular. Como o que importa para a gente é apenas o maior grau da equação, podemos focar nele.

De maneira bem geral, o foco da análise da complexidade em um código são os laços de repetição e as recursões, que são responsáveis por relacionar o valor de n à quantidade de vezes que um trecho do código será executado. Por exemplo:

```c++
for(int i = 0; i < n; i++){
    // x operações
}
```

No laço acima, x operações são executadas n vezes. E é isso que precisamos saber. Já podemos dizer que a complexidade desse código é O(n). 
É importante notar que x não depende de n, e portanto é desconsiderado na notação.

Outro exemplo seria:

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
Aqui, o código do exemplo anterior, que possui complexidade O(n), foi executado **n vezes**. Dessa forma, a complexidade geral do código passa a ser é **O(n²)**, uma vez que foram executadas n vezes um código que tem complexidade O(n).

E quanto ao código abaixo, qual você acha que é a notação Big-O para ele?

```c++
int a = 3;
int b = 2;
int x = a + b;
int y = a - b;
```

Dizemos que a complexidade é **O(1)** ou constante, uma vez que o código não depende de n, e sempre executa um número constante de operações.

## O que todos estávamos esperando: a estimativa do tempo :clock1: 

Chegamos então ao que todos queremos saber:

- Como relacionar o número de operações e o tempo de execução?
- Como eu vou saber se meu código vai rodar em menos de 1 segundo ????

Na maratona, uma estimativa utilizada em C++ é: **10⁸ operações levam em média 1 segundo para serem executadas**!

Um algoritmo que executa 10⁹ operações, por exemplo, levaria em média 10 segundos para ser executado, visto que 10⁹ = 10⁸ * 10

Suponhamos portanto que **você, programador competitivo**, criou um algoritmo capaz de resolver um problema em complexidade **O(n²)**. Para valores até 10⁴, seu código pode ser executado em menos de 1 segundo! Pois no pior caso teria n² = (10⁴)² = 10⁸, que ainda dá top.

Por outro lado, digamos que o exercício tenha como limites 1 < n 10⁶ e o limite de tempo seja 3 segundos. 

Nesse exemplo, seu código não iria ser eficiente o suficiente, visto que no pior caso, em um caso de teste **n = 10⁶**, seu código calcularia (10⁶)² ou **10¹²** operações, o que é equivalente a **10⁴ segundos** :cry:

Então para saber o tempo de execução os passos são basicamente:
  Analisar o código -> descobrir seu big-O -> calculá-lo no pior caso

## Alguns exemplos para praticar!
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
  
   <b>  O código acima é O(n³). Já que temos um loop interno que é executado n vezes sendo executado por um loop intermediário também executado n vezes (até agora já temos um algorítmo n²) que, por fim, é executado pelo loop mais externo, resultando num código O(n³).</b>
</details>



### Digamos que queremos calcular a soma dos n primeiros números naturais. Quais são as diferentes formas de resolver esse problema? Qual é a diferença de eficiência entre elas?
  
<details><summary> Clique para ver a Resposta </summary>
  
#### Uma primeira maneira de pensar no problema é a versão **ad-hoc** da solução, ou seja, simplesmente somar os n primeiros termos. Da seguinte forma:
  
  ```c++
  int sum = 0;
  for(int i = 1; i <= n; i++){
      sum += i;
  }
  ```
  
#### Essa solução é O(n), pois é preciso percorrer os n número somando-os... e podemos fazer melhor! Uma segunda maneira seria usar a fórmula da soma de P.A.!
  
  ```c++
  int sum = ((1+n)*n)/2;
  ```
  
#### Essa solução é O(1), já que não é executada mais vezes para um valor maior de n, e portanto mais eficiente.
  
</details>
