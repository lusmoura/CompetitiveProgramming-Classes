# Árvore de Segmentos (Segment Tree) :deciduous_tree:

Nesse texto vamos falar um pouco a respeito de uma estrutura de dados muito poderosa e muito utilizada na maratona: a Árvore de segmentos.

Comecemos falando a respeito de um problema: o *Range Sum Query (RSQ)*

### **Range Sum Query** :heavy_plus_sign:

Dado um vetor *a*, realizaremos *Q queries*, isto é, perguntas do tipo:
 
**Qual é a soma dos elementos do vetor no intervalo de l à r?** 

Denotaremos essa operação *rsq(l, r)*.

#### **Estratégia Naive** (ingênua) 🤔 : 

Na estratégia Naive, simplesmente realizaremos a soma entre os elementos do intervalo dado:

<p align="center"><img src="https://tex.s2cms.ru/svg/rsq(l%2C%20r)%20%3D%20a%5Bl%5D%20%2B%20a%5Bl%2B1%5D%20%2B%20...%20%2B%20a%5Br-1%5D%20%2B%20a%5Br%5D" alt="rsq(l, r) = a[l] + a[l+1] + ... + a[r-1] + a[r]" /></p>
  
- Complexidade: O(n) por query.

#### **Soma acumulada** :moneybag: :

Nesta estratégia, criaremos um vetor de soma acumulada e utilizaremos a subtração entre somas de prefixos para calcular a soma em um determinado intervalo.

O vetor de soma acumulada representa a soma até um certo índice i, isto é:

<p align="center"><img src="https://tex.s2cms.ru/svg/acc%5Bi%5D%20%3D%20a%5B1%5D%20%2B%20a%5B2%5D%20%2B%20...%20%2B%20a%5Bi%5D" alt="acc[i] = a[1] + a[2] + ... + a[i]" /></p>

Para construirmos o vetor de soma acumulada, sabemos de duas igualdades:

<p align="center"><img src="https://tex.s2cms.ru/svg/%0A%5Cbegin%7Balign*%7D%0A%20%20%26acc%5Bi%5D%20%3D%20a%5B1%5D%20%2B%20a%5B2%5D%20%2B%20...%20%2B%20a%5Bi%5D%20%5C%5C%20%0A%20%20%26acc%5Bi-1%5D%20%3D%20a%5B1%5D%20%2B%20a%5B2%5D%20%2B%20...%20%2B%20a%5Bi-1%5D%0A%5Cend%7Balign*%7D%0A" alt="
\begin{align*}
  &amp;acc[i] = a[1] + a[2] + ... + a[i] \\ 
  &amp;acc[i-1] = a[1] + a[2] + ... + a[i-1]
\end{align*}
" /></p>

<p align="center"><img src="https://tex.s2cms.ru/svg/%5Ccenter%7B%5Ctherefore%20acc%5Bi%5D%20%3D%20acc%5Bi-1%5D%20%2B%20a%5Bi%5D%7D" alt="\center{\therefore acc[i] = acc[i-1] + a[i]}" /></p>

Utilizando o vetor *acc*, podemos calcular a soma em um intervalo (l,r), denominada **rsq(l,r)**, da seguinte forma:

<p align="center"><img src="https://tex.s2cms.ru/svg/%0A%5Cbegin%7Balign*%7D%0A%20%20%26acc%5Bl-1%5D%20%3D%20a%5B1%5D%20%2B%20a%5B2%5D%20%2B%20...%20%2B%20a%5Bl-1%5D%20%5C%5C%20%0A%20%20%26acc%5Br%5D%20%3D%20%5Cunderbrace%7Ba%5B1%5D%20%2B%20a%5B2%5D%20%2B%20...%20%2B%20a%5Bl-1%5D%7D_%7B%7Bacc%5Bl-1%5D%7D%7D%20%2B%20%5Cunderbrace%7Ba%5Bl%5D%20%2B%20a%5Bl%2B1%5D%20%2B%20...%20%2B%20a%5Br%5D%7D_%7B%7Brsq(l%2Cr)%7D%7D%0A%5Cend%7Balign*%7D%0A" alt="
\begin{align*}
  &amp;acc[l-1] = a[1] + a[2] + ... + a[l-1] \\ 
  &amp;acc[r] = \underbrace{a[1] + a[2] + ... + a[l-1]}_{{acc[l-1]}} + \underbrace{a[l] + a[l+1] + ... + a[r]}_{{rsq(l,r)}}
\end{align*}
" /></p>

<p align="center"><img src="https://tex.s2cms.ru/svg/%5Ccenter%7B%5Ctherefore%20acc%5Br%5D%20-%20acc%5Bl-1%5D%20%3D%20rsq(l%2Cr)%7D" alt="\center{\therefore acc[r] - acc[l-1] = rsq(l,r)}" /></p>

- Complexidade: <img src="https://tex.s2cms.ru/svg/O(1)%20%5Ctext%7B%20por%20query.%7D" alt="O(1) \text{ por query.}" />

### **Vamos complicar um pouquinho então...** :sunglasses::

Vamos definir um novo tipo de query possível: <img src="https://tex.s2cms.ru/svg/upd(k%2C%20x)" alt="upd(k, x)" /> , isto é, atualizar/sobreescrever (realizar um update) o **elemento k** com o **valor x**.

`Mas como isso afetou as estratégias citadas?`

Com essa mudança, ambas as estratégias serão <img src="https://tex.s2cms.ru/svg/O(n)" alt="O(n)" /> em geral:

- Soma acumulada:

  - <img src="https://tex.s2cms.ru/svg/O(1)" alt="O(1)" />  para calcular **rsq(l, r)**.
  - <img src="https://tex.s2cms.ru/svg/O(n)" alt="O(n)" />  para realizar **upd(k, x)**, visto que o vetor *acc* dever ser reconstruído.

- Estratégia naive:

  - <img src="https://tex.s2cms.ru/svg/O(n)" alt="O(n)" />  para calcular **rsq(l, r)**.
  - <img src="https://tex.s2cms.ru/svg/O(1)" alt="O(1)" />  para realizar **upd(k, x)**.

Mas existe uma solução! As tais **Árvores de Segmentos**!

- Segment tree:

  - <img src="https://tex.s2cms.ru/svg/O(%5Clog_2%7B(n)%7D)" alt="O(\log_2{(n)})" />  para calcular **rsq(l, r)**.
  - <img src="https://tex.s2cms.ru/svg/O(%5Clog_2%7B(n)%7D)" alt="O(\log_2{(n)})" />  para realizar **upd(k, x)**.

### **Mas o que é essa tal Seg. Tree?**

A árvore de segmentos é uma estrutura de dados que, como diz o nome, se organiza em segmentos. Cada nó dessa árvore contém informação de um intervalo/segmento <img src="https://tex.s2cms.ru/svg/(l%2Cr)" alt="(l,r)" />. 

Para o problema dado (RSQ), essa informação é a soma dos elementos do intervalo, mas é importante notar que a Segment Tree é uma estrutura muito poderosa que pode armazenar outras informações, como por exemplo o elemento máximo/mínimo naquele intervalo, e pode resolver uma variedade enorme de problemas de Programação Competitiva.

<img src='https://i.imgur.com/I88YMTG.png' align="middle" alt="Seg tree">
