# Busca binária

Nessa aula falaremos um pouco sobre a grandiosa busca binária, uma das ideias mais clássicas da Computação, que aparece em muitos algoritmos e otimiza muitas ideias, diga adeus à linearidade :').

## A motivação por trás

Vamos começar com um pequeno problema, vamos supor que temos uma <u>lista de nomes</u> e queremos saber se um amigo está presente na lista: **o Medeiros**!

- Artista (1)
- David (2)
- Fakhoury (3)
- João (4)
- Luísa (5)
- **Medeiros** (6)
- Preischadt (7)
- Samuquinha (8)
- Tubone (9)

Para encontrar o Medeiros, olharíamos de um a um comparando os nomes e apenas na sexta tentativa acharíamos de fato.

Isso é chamado de <b> busca linear</b>, em que olhamos nome a nome procurando o elemento desejado (<font color='red'> Medeiros</font> ) até o acharmos, sua complexidade é **`O(n)`**. Queremos algo melhor, queremos poder buscar nomes e encontrar nossos amigos em **`O(logn)`**!

## Uma observação

Note que a lista está ordenada, ou seja, organizada por ordem alfabética de nomes, será que é possível utilizar essa informação para nossa vantagem? Vamos tentar, vamos começar por olhar para o **nome que está bem no meio da lista: Luísa**.

- Artista (1)
- David (2)
- Fakhoury (3)
- João (4)
- **Luísa** (5)
- Medeiros (6)
- Preischadt (7)
- Samuquinha (8)
- Tubone (9)

Como a lista está em ordem alfabética, sabemos que todos os nomes que estão acima de <font color='blue'> Luísa </font> começam com letras que vem antes de L no alfabeto. Como queremos encontrar <font color='blue'> Medeiros </font>, temos de olhar mais para baixo, visto que esse nome começa com <font color='blue'> M </font>. que vem depois de L no alfabeto.

Esse fato é muito bom, porque podemos fazer um "corte": Podemos eliminar a metade superior da lista com apenas uma comparação! Nos restando apenas 4 nomes. Vamos de novo adotar a mesma estratégia de tentar olhar para o nome que está no meio da lista, como a lista possui 4 nomes, vamos olhar para o segundo:

- Medeiros (6)
- **Preischadt** (7)
- Samuquinha (8)
- Tubone (9)

De novo não encontramos o nome <font color='blue'> Medeiros </font> ao olhar para o nome que está exatamente na metade, mas adquirimos uma nova informação: **O nome que está bem no meio é Preischadt, que começa com P, logo, como Medeiros começa com M, deve estar acima!** Portanto, podemos eliminar todos os nomes que começam com P em diante! Nos restando:

- **Medeiros** (6)

E então terminamos nossa **busca binária**! Conseguimos achar o nome <font color='red'> Medeiros </font> em apenas **três** comparações. Para listas de tamanho **`N`**, como sempre dividimos a lista na metade em cada iteração, a complexidade desse algoritmo será **`O(logn)`**, que é exatamente o numéro de divisões necessárias para se chegar no tamanho 1.

## Bora pro código!

Primeiro vamos codar uma busca linear:
```c++
// pegamos o tamanho da lista de nomes
int n = lista.size();

string amigo = "Medeiros";

for(int i = 0; i < n; i++){
    if(lista[i] == amigo){
        cout << "achei!";
    }
}
```

Agora vamos fazer o mesmo código, porém no formato de uma **lendária busca binária**:

### Recursiva:
```c++
// inicio e fim nos dizem qual é o intervalo atual do nosso "corte" atual da lista.

void busca_binaria(int inicio, int fim, string amigo){

    // se so sobrou um nome na lista e é o nome do nosso amigo!
    if(inicio == fim and lista[inicio] == amigo)
        cout << "achei!";
    
    // vamos pegar o indice do amigo que está bem no meio!
    int meio = (inicio + fim)/2;

    string nome_do_meio = lista[meio];

    // compara alfabeticamente
    if(nome_do_meio > amigo){

        // parte superior da lista (do inicio ao meio (excluindo o nome do meio))
        busca_binaria(inicio, meio - 1, amigo);

    } else if(nome_do_meio <= amigo){

        // parte inferior da lista (do meio ao fim (incluindo o nome do meio))
        busca_binaria(meio, fim, amigo);

    }
}
```

### Iterativa:
```c++
void busca_binaria(string amigo){
    int inicio = 0;
    int fim = lista.size();

    while(inicio <= fim){
    
        // se so sobrou um nome na lista e é o nome do nosso amigo
        if(inicio == fim and lista[inicio] == amigo)
            cout << "achei!";

        int meio = (inicio + fim)/2;
        string nome_do_meio = lista[meio];

        // comparação alfabetica
        if(nome_do_meio <= amigo){
            // vamos olhar pra parte inferior da lista (abaixo do nome que esta no meio)
            inicio = meio + 1;
        } else if(nome_do_meio > amigo){
            // vamos olhar pra parte superior da lista (do meio para cima)
            fim = meio;
        }
    }
}
```

## Comparando resultados

Mas será que a diferença dessas duas buscas é tão grande assim? A resposta é: **sim**.

Vamos avaliar uma lista de inteiros de tamanho **`N = 100 000 000 (cem milhões)`**.

Vamos busca pelo número **`K = 90 000 001`**:

- A busca linear acha o número K em **`t = 50,863 milisegundos `**, com **`c = 90 000 002 comparações`**.
- A busca binária acha o número K em **`t = 0,002315 milisegundos `**, com **`c = 43 comparações`**.
