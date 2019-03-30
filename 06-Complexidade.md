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
  
## Mas como dizer a complexidade de um código? :computer:

## O que todos estávamos esperando: a estimativa do tempo :clock1: 

## Exemplos
 
