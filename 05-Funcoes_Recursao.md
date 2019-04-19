# Funções

## A teoria por trás:

Até agora falamos de funções várias vezes e já até vimos exemplos. Finalmente é hora de explicar o que são, como funcionam e a utilidade delas.

Em um código, funções são como funções matemáticas: conjuntos de comandos que recebem valores de entrada, fazem algumas operações com esses valores e geram valores de saída (resultados). Mas pera, isso não é a mesma coisa que um programa/código? Na verdade sim. A diferença é que a função é um *trecho* de código que serve para organizá-lo e facilitar a nossa vida.

Se temos, por exemplo, um conjunto de comandos que serão executados diversas vezes ao longo do progama, é muito mais fácil escrevê-lo apenas uma vez e chamar essa parte do código quando necessário. Ou se temos um código muuuuito grande e ninguém consegue entender o que está acontecendo, é possível dividí-lo em funções e fragmentá-lo para facilitar a compreensão e reduzir a chance de cometer erros.

Tudo isso pode parecer um pouco abstrato, mas com alguns exemplos práticos tudo se tornará mais claro:

Vamos ver agora como declará-las (criá-las).

```c++
tipo_do_retorno nome(parametros) {
	// comandos
	retorno
}

```
## Os elementos básicos de uma função:

### Temos quatro elementos principais que devem ser destacados:
- **Tipo do Retorno**: uma função pode retornar (devolver) algo, como um valor, uma string, uma letra... é preciso declarar o tipo do dado que será retornado, sendo que esses tipos são os mesmos das variáveis que já vimos. Temos apenas um novo tipo: void - não retorna nada (a função só serve para executar as instruções).
- **Nome**: é... acho que isso é auto-explicativo. Aqui vai o nome da função.
- **Parâmetros**: pode ser que precisemos enviar para a função algum valor. É aqui que ele entra. No cálculo da área de um triângulo, por exemplo, é necessário informar as medidas da base e da altura.
- **Retorno**: utiliza-se a palavra **return** para indicar o valor que será retornado pela função.

## Alguns exemplos:

```c++
//uma função que recebe dois inteiros e retorna um double
double media(int num1, int num2);

//uma função que recebe uma letra e retorna outra letra
char conversao_para_maiuscula(char letra);

//uma função que recebe duas strings e retorna um booleano (True ou False).
bool mesmoTamanho(string a, string b);
```

Talvez ainda não tenha ficado claro o que queremos dizer, então vamos mostrar.

O código abaixo tem duas funções: main e media. Primeira coisa importante, a main é uma função. Ela não recebe nada, mas retorna um inteiro, por isso geralmente colocamos 'return 0' no final dos nossos códigos e isso significa que não ocorreram erros. A segunda função é a 'media', que recebe dois inteiros e retorna a média deles. Dentro dela temos o processamento necessário, que é o cálculo e, em seguida, o retorno do valor obtido.

```c++
double media(int num1, int num2) {
	double m = (num1 + num2) / 2.0;
	return m;
}

int main() {
	int a, b;
	cin >> a >> b;
	int m = media(a, b);
	
	cout << m << "\n";
	return 0;
}
```

Outro exemplo. Nesse, vamos ler varias letras na main, até que a entrada seja '#". Cada letra será analizada e, se for maiúscula, será impressa.

```c++
void ehMaiuscula(char letra) {
	if(letra >= 'A' && letra <= 'Z') { //sim, dá pra fazer essas comparações com letras
		cout << letra << "\n";
	}
	return; //podemos usar o return mesmo sem nenhum valor a retornar
}

int main() {
	char letra;
	
	do{
		cin >> letra;
		ehMaiuscula(letra);
	} while(letra != '#')

	return 0;
}
```

Agora um último exemplo. Essa função recebe duas strings e retorna verdadeiro se elas tiverem o mesmo tamanho e falso caso contrário.

```c++
bool mesmoTamanho(string a, string b) {
	if(a.size() == b.size()) {
		return true;
	} else {
		return false;
	}
}

int main() {
	string a, b;
	cin >> a >> b;
	
	if(mesmoTamanho(a, b))
		cout << "As strings tem o mesmo tamanho" << "\n";
	else
		cout << "As strings não tem o mesmo tamanho" << "\n";

	return 0;
}
```

É importante ressaltar que quando uma variável é declarada dentro de um escopo (seja ele uma função, um for, um if...), ela só pode ser acessada dentro desse local. Então se voce quer usar uma variável que foi declarada em uma função numa outra, é preciso passá-la como *parâmetro*. 

O caso abaixo, por exemplo, não funcionaria. A função printString não sabe quem é 's', então não pode fazer o acesso.
```c++
void printString() {
	cout << s;
}

int main() {
	string s;
	cin >> s;
	printString();
}
```

O correto seria fazer:
```c++
void printString(string s) {
	cout << s;
}

int main() {
	string s;
	cin >> s;
	printString(s);
}
```

É possível burlar isso (pelo menos para as funções), com variáveis globais, como veremos no próximo tópico.

# Variáveis Globais
Agora que já sabemos o que é função, podemos falar um pouco sobre as variáveis globais. Elas são variáveis que são declaradas fora do escopo de todas as funções. Por exemplo:
```c++
int a, b; // variáveis globais, fora da função main

int main(){    // só um código aleatório
	cin >> a >> b;
	cout << a + b;
}
```

Esse tipo de variável é bastante útil em programação competitiva, pois permite que seja feito o acesso do valor daquela variável sem ter que passá-la como parâmetro para outra função. Ou seja, qualquer função do código tem acesso ao valor dessas variáveis.

Sem variável global teríamos:
```c++
int soma(int a, int b, int c, int d){  // todas as variáveis são passadas por parâmetro
	return a+b+c+d;
}

int main(){    // só um código aleatório
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << soma(a, b, c, d);
}
```

Com variável global:
```c++
int a, b, c, d;

int soma(){  // a função tem acesso às variáveis mesmo sem tê-las como parâmetro
	return a+b+c+d;
}

int main(){    // só um código aleatório
	cin >> a >> b >> c >> d;
	cout << soma();
}
```

Elas também são úteis pois, ao declará-las fora das funções, essas variáveis já começam zeradas, dessa forma, não é preciso inicializá-las.
```c++
int vetGlobal[10];  // criamos um vetor global de inteiros

int main(){
	int vetLocal[10];  // criamos um vetor local de inteiros
	
	for(int i = 0; i < 10; i++)   
		cout << vetLocal[i] << " ";
	/*No meu computador foram impressos os valores: */
	/*27 982938 -2983 281 182 37 40 82387 748 2*/

	cout << endl;

	for(int i = 0; i < 10; i++) 
		cout << vetGlobal[i] << " ";
	/*Em todos os computadores serão impressos: */
	/*0 0 0 0 0 0 0 0 0 0*/
}
```

### Porém...
Esse tipo de prática não é muito recomendada. É bastante perigoso declarar variáveis fora das funções, pois pode haver conflito de nomes, acessos indevidos e indesejados, dentre outros problemas. 
Aqui em programação competitiva não fazemos códigos tão grandes que serão utilizados por muitas pessoas, então podem usar e abusar das variáveis globais. MAS não usem elas nos trabalhos da faculdade ou no mercado de trabalho (se usarem sem querer, a culpa não é nossa... a gente avisou).

# Algumas funções úteis

Como já falamos antes, no início do código nós incluímos a *biblioteca* bits/stdc++. Além de diversas outras coisas, ela contém algumas funções úteis já implementadas e prontas para serem usadas. O próprio C++ também já possui algumas funções que não existem em C. As principais são:

#### Sqrt
Essa função simplesmente retorna um double representando a raíz quadrada do número passado como parâmetro.
```c++
int main(){
	int n;
	cin >> n;
	cout << sqrt(n) << endl;
}
```

#### Max
Função que retorna o máximo entre os valores passados como parâmetros (essa não existe em C). Esse valores não necessariamente precisam ser números.
```c++
int main(){
	int a = 2, b = 3;
	int maxNum = max(a, b); // maxNum vai receber o maior dos valores entre a e b
	cout << maxNum << endl;
	/*maxNum = 3*/

	int c = 4, d = 5;
	int maxNum2 = max({a, b, c, d}) // para comparar mais de dois valores, é preciso utilizar 
									// as {chaves}
	cout << maxNum2 << endl;
	/*maxNum2 = 5*/

	char e = "e", z = "z";
	char maxChar = max(e, z); // maxChar vai receber z, pois ele é maior lexicograficamente
	cout << maxChar << endl;
	/*maxChar = "z"*/
}
```

#### Min
Essa função é similar à max, mas dessa vez retorna o mínimo entre valores.
```c++
int main(){
	int a = 2, b = 3;
	int minNum = min(a, b); // maxNum vai receber o menor dos valores entre a e b
	cout << minNum << endl;
	/*maxNum = 2*/

	int c = 1, d = 0;
	int minNum2 = min({a, b, c, d}) // para comparar mais de dois valores, é preciso utilizar 
									// as {chaves}
	cout << minNum2 << endl;
	/*maxNum2 = 0*/

	char e = "e", z = "z";
	char minChar = min(e, z); // maxChar vai receber e, pois ele é menor lexicograficamente
	cout << minChar << endl;
	/*maxChar = "e"*/
}
```

#### Abs
A função Abs retorna o valor absoluto do parâmetro. Isto é, se o número for positivo, ele mesmo será retornado. Se for negativo, o valor positivo simétrico a ele será retornado.
```c++
int main(){
	int a = 2, b = -3;
	int positivoA = abs(a);    // positivoA = 2
	int positivoB = abs(b);    // positivoB = abs(-3) = 3
	cout << positivoA << " " << positivoB << endl;
}
```
#### Swap
O swap troca dois valores passados como parâmetros.
```c++
int main(){
	int a = 2, b = 3;
	swap(a, b);         //agora a = 3 e b = 2
	cout << a << " " << b << endl;
}
```

#### Sort
Função de ordenação. Ela ordena os elementos num range em ordem crescente. Seus parâmetros são a posição inicial do range e a posição final +1, ou seja, um intervalo fechado no início e aberto no final (inicio, fim].
```c++
int main(){
	int n;                // criando um vetor de n números entrados pelo usuário
	cin >> n;
	int vet[n];
	
	for(int i = 0; i < n; i++) cin >> vet[i];
	
	sort(vet, vet + n);  // ordenando o vetor, da posição inicial (que é o próprio vet) até a
	// posição final (que é a posição inicial mais a quantidade de números, ou seja, vet + n)

	for(int i = 0; i < n; i++) cin >> vet[i] >> " "; // imprimindo o vetor já ordenado
}
```

Outra coisa legal dessa função é que podemos definir um operador para que o parâmetro de ordenação seja diferente. Por exemplo, podemos ordenar os valores em ordem decrescente. Esse operador é inserido como um terceiro parâmentro na função. Vamos ver esses exemplos abaixo:
```c++
bool decrescente(int a, int b) {
	return(a > b);
}

int main(){
	int n;                // criando um vetor de n números entrados pelo usuário
	cin >> n;
	int vet[n];

	for(int i = 0; i < n; i++) cin >> vet[i];
	
	sort(vet, vet + n, decrescente);  // ordenando o vetor tendo como parâmetro o método de comparação que ta definido ali em cima ^
}
```
O operador será um booleano que irá retornar um bool a partir da comparação entre os números. Nesse caso, ele vai retornar true se a for maior b e, com isso, a será inserido numa posição a frente de b no vetor.


# Recursão

Uma coisa muito louca é que uma função pode chamar ela mesma. Podemos pensar nessas funções chamadas *recursivas* como uma espécie de repetição. Em alguns casos é mais fácil implementar uma função recursiva do que um for ou um while, além disso, ela pode ser chamada com parâmetros diferentes, ou seja, a cada chamada o valor do parâmetro pode ser alterado.

Vamos implementar um código de uma função recursiva que retorna a soma dos primeiros n números naturais.
```c++
int soma(int n) {
	return n + soma(n-1);
}

int main(){
	int n;
	cin >> n;
	cout << soma(n) << "\n";
}
```
O código acima para n = 3 funciona assim:
```
-Main chama soma(3)
	     soma(3) retorna (3 + soma(2))
		             soma(2) retorna (2 + soma(1))
				  	          soma(1) retorna (1 + soma(0))
						    	        soma(0) retorna (0 + soma(-1))
```

Opa, algo de errado não está certo. Não queremos números negativos nessa soma. Para resolver isso, é preciso adicionar o chamado **caso base**, ou seja, um caso que diga quando a função deve parar de chamar a si mesma. O código com ela seria:

```c++
int soma(int n) {
	if(n == 1) return 1; //caso base
	return n + soma(n-1); //cálculo e chamada recursiva
}

int main(){
	int n;
	cin >> n;
	cout << soma(n) << "\n";
}
```

O código acima para n = 3 funciona assim:
```
-Main chama soma(3)
	     soma(3) retorna (3 + soma(2))
				 soma(2) retorna (2 + soma(1))
		    			    	     soma(1) retorna 1
```						  				   					

Os retornos de uma função recursiva são feitos na ordem contrária à da chamada, ou seja, a última chamada é a última é ter seu valor retornado. Então, no exemplo acima, após todas as chamadas terem sido feitas, a recursão vai "voltar" fazendo de fato a operação com os valores retornados.
```
	-soma(1) retorna 1
	-soma(2) retorna (2 + soma(1)) -> retorna 2+1 -> retorna 3	
	-soma(3) retorna (3 + soma(2)) -> retorna 3+3 -> retorna 6
```

Esse tópico geralmente é um pouco confuso mesmo, então vamos mostrar outro exemplo. Nesse, vamos fazer o cálculo do fatorial de um número:
```c++
int fat(int n) {
	if(n == 1) return 1; //caso base
	return n * fat(n-1); //cálculo e chamada recursiva
}

int main(){
	int n;
	cin >> n;
	cout << fat(n) << "\n";
}
```
Na verdade esse exemplo é bem parecido com o anterior, a diferença é que em vez de somarmos n pela chamada recursiva, vamos multiplicá-los.

Ele vai funcionar da seguite maneira:
```
-Main chama fat(4)
	    fat(4) retorna (4 * fat(3))
	    		      fat(3) retorna (3 * fat(2))
						    fat(2) retorna (2 * fat(1))
									fat(1) retorna 1
```						  					   					
Após todas as chamadas terem sido feitas, a recursão vai "voltar" fazendo de fato a operação com os valores retornados.
```
	-fat(1) retorna 1
	-fat(2) retorna (2 * fat(1)) -> retorna 2 * 1 -> retorna 2
	-fat(3) retorna (3 + fat(2)) -> retorna 3 * 2 -> retorna 6
	-fat(4) retorna (4 * fat(3)) -> retorna 4 * 6 -> retorna 24
```

### Overview da recursão
```c++
int recursion(int x) {              //Função recursiva com x como parâmetro
	if(baseCase) return value;  //Checagem do caso base, se x estiver satisfazendo esse
					//caso, a função para de ser chamada recursivamente
	recursion(novoX);           //Se o caso base não foi atendido, é feita a chamada
					//recursiva com o novo valor de x
}
```

### Continuando com exemplos

A função de Fibonacci é uma função na qual o valor atual (n) é a soma dos dois valores anteriores (n-1 e n-2), ou seja, f(n) = f(n-1) + f(n-2). Como vimos antes, se não definirmos um caso base a função será infinita, então podemos dizer que f(1) = f(2) = 1. Isso quer dizer que nossa sequência vai ser 1, 1, 2, 3, 5, 8, 13, 21....

```c++
int fib(int n) {
	if(n == 1 || n == 2) return 1; //caso base (n = 1 ou n = 2)
	return fib(n-1) + fib(n-2);    //chamadas recursivas
}

int main(){
	int n;
	cin >> n;
	cout << fib(n) << "\n";
}
```

Ele vai funcionar da seguite maneira:
```
-Main chama fib(5)

					fib(5) = (fib(4) + fib(3))
						   /          \
			fib(4) = (fib(3) + fib(2))         fib(3) = (fib(2) + fib(1))
				/           \                          /         \
	fib(3) = (fib(2) + fib(1))       fib(2) = 1           fib(2) = 1      fib(1) = 1
		/           \
	fib(2) = 1      fib(1) = 1

```
Após todas as chamadas terem sido feitas, a recursão vai "voltar" fazendo de fato a operação com os valores retornados.
```	
1)
				fib(5) = (fib(4) + fib(3))
                              		     /          \
		   fib(4) = (fib(3) + fib(2))         fib(3) = (fib(2) + fib(1))
			      /           \                      /          \
      fib(3) = (fib(2) + fib(1))           1                     1          1
	  	   /           \
	   	   1           1



2)
				fib(5) = (fib(4) + fib(3))
	                                 /          \
		   fib(4) = (fib(3) + fib(2))         fib(3) = (1 + 1)
			       /           \              
	   	   fib(3) = (1 + 1)          1



3)
               			fib(5) = (fib(4) + fib(3))
                   	    		     /          \
		   fib(4) = (fib(3) + fib(2))         fib(3) = 2
		           /           \              
                          2             1


4)
                            	fib(5) = (fib(4) + fib(3))
                               		     /          \
			       fib(4) = (2 + 1)       fib(3) = 2


5)
			        fib(5) = (fib(4) + fib(3))
                               		     /          \
			                    3           2

6)
			        fib(5) = (3 + 2)

7)			                 
			        *fib(5) = (5)*
```

That's it, folks! Até a próxima \o/
