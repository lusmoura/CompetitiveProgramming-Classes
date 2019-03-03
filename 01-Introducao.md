# Introdução à Programação Competitiva

> "Dado um problema de programação já conhecido, resolva ele no menor tempo possível."

O estudo em programação competitiva se baseia em várias técnicas e algoritmos. Além de conhecê-los, também é importante uma constante prática, para que o tempo que se gasta em cada problema seja menor.

## Essencias de um problema

Certo, você irá resolver um problema. Para se familiarizar melhor com eles, aqui vai um resumo de como eles costumam aparecer. Normalmente, os enunciados de problemas apresentam a seguinte forma:
1. Título do Problema\
    Na maioria dos casos, é *realmente* só um título, não influenciando em nada o problema. Porém, às vezes ele nos dá uma dica de como o resolver (apresenta alguma *tag*, etc.)
2. História do Problema\
    Mesma coisa que em vestibular. Uma historinha que o cara criou só para o problema ter sentido - e que, assim como em matemática, o que realmente importa está dentro dela. Portanto, é sempre bom ler o enunciado para saber o que fazer.
3. Constraints (restrições)\
    Embora agora isso não faça muito sentido, mais pra frente vocês verão que isso importa muito. As *constraints* de determinado problema representam o intervalo que os valores de entrada podem apresentar. Isso irá restringir a complexidade do algoritmo que você desenvolver, ou o tipo de variável que você deve utilizar.
4. Casos de Teste de Exemplo\
    Digamos que você leu o enunciado e tem uma noção do que fazer. Então, você vê os casos de teste de exemplo. Eles terão um exemplo de entrada de valores, e logo depois a saída que o problema espera.
5. Explicação dos Casos de Teste\
    Em alguns problemas, também é possível que os casos de teste sejam explicados, para facilitar a compreensão do problema.

## Exemplo básico

Aqui vai um exemplo básico de problema:

| Cremosas em Ferpa |
| --- |
| Tempo limite: 1s |

Jaojão é um garoto sagaz. Sempre que possível, ele vai à Ferpa em busca de cremosas aos finais de semana. Agora ele quer dizer a seus amigos a quantiadade *k* de cremosas que ele avistou em sua grande terra natal em um final de semana. Seja *n* (0 < n < 100) o número de cremosas que Jaojão viu no sábado e *m* (0 < m < 100) o número de cremosas que ele viu no domingo, responda a quantidade *k* de cremosas avistadas.

Entrada\
A primeira linha contém dois inteiros *n* e *m* (a quantidade de cremosas avistadas).

Saída\
Seu programa deverá apresentar um único inteiro *k*, o total de cremosas.

Exemplo
```
Entrada:
3 4

Saída:
7
```

Bom, você deve ter percebido que a solução deste problema é apenas somar os dois valores de entrada. Nele, podemos perceber as situações que destaquei acima: o título do problema *(que realmente não tem nada a ajudar na solução em si)*; a história *(que tem muita coisa inútil, porém é nela que está descrito o problema)*. Nesse caso, as *constraints* são dadas também no enunciado (tanto *n* quanto *m* são valores inteiros entre 1 e 99, inclusive), isso nos ajuda a escollher os tipos de variáveis que vamos utilizar; e a restrição de tempo do problema é 1 segundo - isto é, a execução do seu problema não pode ultrapassar 1 segundo - vamos ver mais para frente como saber se seu programa será executado dentro do tempo limite.

## Introdução à Programação em C++

Se você já estiver familiarizado com alguma linguagem de programação *(c, python, pascal)*, não será tão difícil aprender os conceitos básicos de C++. Em C++, você pode usar tudo que se usa em *c* (posso, por exemplo, pegar um programa em C e compilá-lo em C++ sem problemas).

### Formato do Código em C++
```c++
#include <iostream> //incluindo biblioteca que possui alguma função que eu quero

int main() { //funcao principal, a primeira a ser executada em seu codigo
    return 0; //retorno da funcao (opcional)
}

// OBS: '//' (barra barra) representa um comentario de uma linha do codigo
// e sera ignorado na execucao do programa
```



## Introdução à Complexidade

Normalmente, os computadores convencionais conseguem computar cerca de 4*10^8 comandos por segundo. E é aí que as *constraints* do problema são úteis. No caso do exemplo anterior, por exemplo, o *n* ia até no máximo 100. Ou seja, nós poderiamos fazer um *for* indo de *0* até *n* sem problemas, pois seriam executados apenas cerca de 100 comandos. Porém, se o *n* pudesse valer 10^9, isso não seria possível, pois estouraria o limite de tempo.\
Mais para a frente iremos estudar métodos para analisar a complexidade de cada código. Porém, por enquanto, é bom ter algumas noções:
- Se seu programa depende de *n* para o número de execuções, dizemos que ele é de ordem de alguma *f(n)* (ele é *O(f(n)*)
- Se seu programa executa as instruções independentemente de n (por exemplo, no exemplo acima, era necessário apenas somar dois números), dizemos que ele é *constante (O(1))*
- Um *for* de *0* a *n* apresenta complexidade *O(n)*
- Dois *for* aninhados de *0* a *n* apresenta complexidade *O(n^2)*

Essa parte de complexidade não é tão imposta no início, e será revista mais tarde, então se você não entendeu isso agora, não se preocupe: o seu "eu" do futuro se preocupará com isso.

## Respostas dos Judges
Após submeter seu código, você pode receber alguma resposta do site em que mandou:
1. Accepted (AC) - sua solução estava certa e foi aceita.
2. Wrong Answer (WA) - sua solução apresentou alguma saída diferente da esperada.
3. Time Limit Exceed (TLE) - seu programa demorou mais do que o limite para executar.
4. Memory Limit Exceed (MLE) - seu programa está usando mais memória do que deveria.
5. Runtime Error (RTE) - seu programa bugou no meio da execução e travou alguma coisa (fez um acesso indevido, por exemplo).
5. Presentation Error - Alguns judges apresentam esse erro, que ocorre quando a saída do problema está em um formato diferente do esperado (por exemplo, você colocou espaços ou quebras de linha a mais do que deveria).

---

## Referências

### Sites para aprender
É sempre bom ler sobre algoritmos em diferentes sites, para ter diferentes perspectivas sobre um tópico. Entre estes sites, recomendamos:

#### Em português
[CodCad](http://www.codcad.com/)\
[GitHub do Fakhoury](https://github.com/andrefakhoury)\
[GitHub do Forbes](https://github.com/VictorXjoeY)\
[GitHub do LoppA](https://github.com/LoppA)\
[GitHub da lmoura](https://github.com/lusmoura)\
[GitHub do Preischadt](https://github.com/thiagop-usp)\
[GitHub do David](https://github.com/davidcairuz)\

#### Em inglês
[Geeks for Geeks](https://www.geeksforgeeks.org/)\
[HackerRank](https://www.hackerrank.com/)\
[HackerEarth](https://www.hackerearth.com/)\
[CP-Algorithms](https://cp-algorithms.com/)\
Canal do [Abdul Bari](https://www.youtube.com/channel/UCZCFT11CWBi3MHNlGf019nw/) no youtube\
Canal do [Tushar Roy](https://www.youtube.com/user/tusharroy2525) no youtube\
[Texto do João Gui sobre deliberate practice](https://joaogui1.github.io/CP/training/)

### Sites para competir
Após ter certa noção de programação competitiva, você já pode começar a treinar e competir. Para isso, existem vários sites que te dão problemas para resolver, e alguns promovem campeonatos *(contests)* periodicamente, e dão um certo *rating* de acordo com os problemas resolvidos. Entre os melhores (*em minha opinião*) estão:

[Codeforces](https://www.codeforces.com)\
[Codechef](https://www.codechef.com)\
[SPOJ](https://www.spoj.com)\
[TopCoder](https://www.topcoder.com)\
[CsAcademy](https://www.csacademy.com)\
[UVA](https://uva.onlinejudge.org/)\
[URI](https://www.urionlinejudge.com.br)

### Livro de programação competitiva
O livro mais utilizado por aqueles que estão aprendendo algoritmos e técnicas para maratonas de programação é o **Competitive Programming 3**, de Steven e Felix Halim. O livro conta com ótimas explicações e código em C++, além de recomendar diversos problemas para cada assunto estudado.

Os problemas recomendados estão todos no [UVA](https://uva.onlinejudge.org/), um dos sites citados acima, e seu progresso na resolução de cada tópico do livro pode ser acompanhado em [uHunt](https://uhunt.onlinejudge.org/).

Uma ótima forma de utilizar esse livro é combinando-o a alguns outros recursos citados aqui. Como já foi dito anteriormente, é importante tentar ter diferentes perspectivas sobre um mesmo tópico.

A biblioteca do ICMC conta com apenas uma cópia, mas o livro também pode ser encontrado na internet.
