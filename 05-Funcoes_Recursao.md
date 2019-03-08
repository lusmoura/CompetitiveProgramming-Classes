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
	-Main chama soma(3)
	-soma(3) retorna (3 + soma(2))
						  soma(2) retorna (2 + soma(1))
						  					   soma(1) retorna (1 + soma(0))
						  					   						soma(0) retorna (0 + soma(-1))

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
	-Main chama soma(3)
	-soma(3) retorna (3 + soma(2))
						  soma(2) retorna (2 + soma(1))
						  					   soma(1) retorna 1
						  					   					
Após todas as chamadas terem sido feitas, a recursão vai "voltar" fazendo de fato a operação com os valores retornados.
	-soma(1) retorna 1
    -soma(2) retorna (2 + soma(1)) -> retorna 2+1 -> retorna 3
    -soma(3) retorna (3 + soma(2)) -> retorna 3+3 -> retorna 6

Esse tópico geralmente é um pouco confuso mesmo, então vamos mostrar outro exemplo.
A função de Fibonacci é uma função na qual o valor atual (n) é a soma dos dois valores anteriores (n-1 e n-2), ou seja, f(n) = f(n-1) + f(n-2). Mas como vimos antes, se não definirmos um caso base a função será infinita, então podemos dizer que f(1) = f(2) = 1. Isso quer dizer que nossa sequência vai ser 1, 1, 2, 3, 5, 8, 13....

```c++
int fib(int n) {
	if(n == 1 || n == 2) return 1; //caso base
	return fib(n-1) + fib(n-2); //chamadas recursivas
}

int main(){
	int n;
	cin >> n;
	cout << fib(n) << "\n";
}
```