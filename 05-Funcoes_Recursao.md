# Funções

Até agora falamos de funções várias vezes e já até vimos exemplos. Finalmente é hora de explicar o que são, como funcionam e a utilidade dessas tais funções.

Em um código, funções são como funções matemáticas: conjuntos de comandos que recebem valores de entrada, fazem algumas operações com esses valores e geram valores de saída (resultados). Mas pera, isso não é a mesma coisa que um programa/código? Na verdade sim. A diferença é que a função é um *trecho* de código que serve para organizá-lo e facilitar a nossa vida. 

Se temos, por exemplo, um conjunto de comandos que serão executados diversas vezes ao longo do progama, é muito mais fácil escrevê-lo apenas uma vez e chamar essa parte do código quando necessário. Ou se temos um código muuuuito grande e ninguém consegue entender o que está acontecendo, é possível dividí-lo em funções e fragmentá-lo para facilitar a compreensão.

Tudo isso pode parecer um pouco abstrato, mas com alguns exemplos práticos tudo se tornará mais claro:

Vamos ver agora, na prática, como declará-las (criá-las).

```c++
tipo_do_retorno nome(parametros) {
	// comandos
	retorno
}

```

Temos quatro elementos principais que devem ser destacados:
	1- Tipo do Retorno: uma função pode retornar (devolver) algo, como um valor, uma string, uma letra... é preciso declarar o tipo do dado que será retornado, sendo que esses tipos são os mesmos das variáveis que já vimos. Temos apenas um novo tipo: void - não retorna nada (a função só serve para executar as instruções).
	2- Nome: é... acho que isso é auto-explicativo. Aqui vai o nome da função.
	3- Parâmetros: pode ser que precisemos enviar para a função algum valor. É aqui ele ele entra. No cálculo da área de um triângulo, por exemplo, é necessário informar as medidas da base e da altura.
	4- Retorno: utiliza-se a palavra **return** para indicar o valor que será retornado pela função.

Alguns exemplos:

```c++
//uma função que recebe dois inteiros e retorna um double
double media(int num1, int num2);

//uma função que recebe uma letra e retorna outra letra
char conversao_para_maiuscula(char letra);

//uma função que recebe duas palavras e retorna um booleano (True ou False).
bool mesmoTamanho(string a, string b);
```

Talvez ainda não tenha ficado claro o que queremos dizer, então vamos mostrar.

O código abaixo tem duas funções: main e max. Primeira coisa importante, a main é uma função (plot twist). Ela não recebe nada, mas retorna um inteiro, por isso geralmente colocamos 'return 0' no final dos nossos códigos. A segunda função é a 'média', que recebe dois inteiros e retorna a média deles. Dentro dela temos o processamento necessário, que é o cálculo e, em seguida, o retorno do valor obtido.

```c++
int media(int num1, int num2) {
	double m = (num1 + num2) / 2;
	return m;
}

int main() {
	int a, b;
	cin >> a >> b;
	int m = media(a, b);
	
	cout << m << endl;
	return 0;
}
```

Outro exemplo. Nesse, vamos ler varias letras na main, até que a entrada seja '#". Cada letra será analizada e, se for maiúscula, será impressa.

```c++
void ehMaiuscula(char letra) {
	if(letra >= 'A' && letra <= 'Z') {//sim, dá pra fazer essas comparações com letras
		cout << letra << endl;
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
```
