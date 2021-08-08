# Pratica 2 - Algoritmo e Estrutura de Dados #
Trabalho realizado para a disciplina de Algoritmo e Estrutura de Dados \
CEFET - MG Campus V \
Jorge Vitor G. de Souza
## Compilar ##
```
  make
  make run
```
## Problema 1 - Listas ##
### Enunciado ###

Conforme literatura, o tipo lista é uma estrutura de dado extremamente flexível cuja definição
permite o armazenamento de informação sem muitas regras de manipulação. Sabendo-se
disso, considere dois conjuntos aleatórios de dados, um apenas com números impares e outro
com pares. Veja um exemplo: I = {1, 33, 25, 87, . . . , 13} e P = {62, 42, 36, 48, . . . , 14}. Realize
as solicitações de implementação a seguir considerando para isso estruturar sua solução da
seguinte forma: i) Uma implementação por letra e; ii) Uma implementação magma que conecte
todas as letras por um único menu para execução. 

- a: Crie duas listas (i.e., L1 e L2) com 100 elementos cada conforme regra par/impar acima
apresentada. Feito isso, elabore uma função de concatenação que faça a união de L1
e L2 mantendo as posições de paridade em ordem crescente, ou seja, {{L1[0], L2[0]},
{L1[1], L2[1]}, . . . , {L1[99], L2[99]}}. 

- b: Crie um pequeno jogo utilizando duas listas (i.e., L1 e L2). Nesse, cada lista deve
ter tamanho máximo de 3 entradas e cada posição deve armazenar um número inteiro
aleatório entre 1 e 13. Nesse jogo, após preencher ambas as listas, selecione também
de forma aleatória mais um valor entre 1 e 13 e mostre-o na tela. A regra do jogo é a
seguinte: Ambas as listas devem ser apresentadas na tela de forma sequencial a partir de suas posições de paridade, ou seja, {{L1[0], L2[0]}, {L1[1], L2[1]}, {L1[2], L2[2]}}.
Cada par deve ser subtraído do valor apresentado e ganha o jogo a lista que apresentar
a maior soma final. Mostre o ganhador ao final. 

- c: Crie um pequeno sistema com três listas dinâmicas L1, L2 e L3. A primeira lista deve
armazenar o nome de um produto de mercado comum como pão, arroz, feijão, etc .. bem
como sua quantidade e um identificador único do tipo inteiro. A segunda lista deve armazenar os diferentes mercados da cidade em que esse produto se encontra em estoque,
não é obrigado que todos os mercados tenham os mesmos produtos. Além disso, na L2
é desejável também que tenhamos um identificado único para o mercado. Por fim, em L3
teremos uma estrutura que detalha o preço de um determinado produto para um mercado
específico. Dessa forma, essa última estrutura deve conter dois identificadores (produto
vs mercado) e o respectivo preço. Sua função nessa aplicação é relacionar produtos vs
mercado vs preço e mostrar ao final o menor custo total para uma compra. Para tanto,
detalhe em tela produto, menor preço e mercado a ser comprado.

### Resolução ###

- a) Para a resolução do item a, foi implementada uma estrutura de lista estática devido a informação prévia do número de elementos.
    Para o prenchimento da lista foi utilizado um metodo para gerar números randômicos entre 1 e 99. Por exemplo para gerar a lista de números pares:
    ```
    
    srand((unsigned)time(NULL));
    while(aux1 != MAXTAM){
		  Item d;
		  d.val = rand()%99;
		  if(d.val % 2 == 0 && d.val != 0){
			  ListInsert(par, d);
			  aux1++;
		  }
	  }
    ```
    Por fim, foi criada uma função que concatena os valores da lista par com os valores da lista impar, mantendo as respectivas posições juntas:
    ```	
    char str[10];
    int result;
    for(int i = par->first; i < par->last; i++){
		Item c;
		sprintf(str, "%d%d",  par->vet[i].val, imp->vet[i].val);
		result = strtol(str, NULL, 10);
		c.val = result;
		ListInsert(conc, c);
	}
    ```
    #### Exemplo de execução: ####
    
    ![menu1](https://user-images.githubusercontent.com/60747654/128634479-7dece094-b740-4c6a-ab17-10adeacbf297.PNG)
    
	![meenu2](https://user-images.githubusercontent.com/60747654/128634481-4d161bc4-60eb-40c0-ad76-2a637022bda9.PNG)
	
	![par](https://user-images.githubusercontent.com/60747654/128634485-3be64866-a9f8-45c0-a995-157324c078a8.PNG)
		
	![imp](https://user-images.githubusercontent.com/60747654/128634488-41aff163-0242-4ed9-aa42-9992cbacfd36.PNG)
	
	![conc](https://user-images.githubusercontent.com/60747654/128634490-9dd9bf14-cc06-4751-bd55-998e32331174.PNG)

- b) Para a resolução do item b foi reutilizada a estrutura de lista estática do item anterior pelo mesmo motivo: já se sabe o tamanho da estrutura, nesse caso 3 posições, porém foram feitas alterações para atender as questões levantadas no item.
	Foi criada uma ListaB para tal, e um metódo que preenche com números aleatórios entre 1 e 13 as 3 posições da lista.
	```
	void ListB(Listab *l1, Listab *l2){
		int aux1 = 0;

		srand((unsigned)time(NULL));
		while(aux1 != MAXTAMB){
			Item d;
			d.val = rand()%13;
			if(d.val != 0){
				ListBInsert(l1, d);
				aux1++;
			}
		}

		int aux2 = 0;
		while(aux2 != MAXTAMB){
			Item d;
			d.val = rand()%13;
			if(d.val != 0){
				ListBInsert(l2, d);
				aux2++;
			}
		}	
	}
	```
	Criadas as listas, é feito um procedimento para gerar o número randomico a ser subtraído:
	```
		srand((unsigned)time(NULL));
		int random = (rand()%12)+1;
		printf("\n");
		printf("NUMERO RANDOMICO: %d", random);
		printf("\n\n");
	```
	Por fim é chamado o método que executa o jogo:
	```
	void GameB(Listab *l1, Listab *l2, Listab *l3, Listab *l4, int random){
		int result1 = 0;
		int result2 = 0;
		int vet1[3],vet2[3];

		for(int i = l1->first; i < l1->last; i++){
			vet1[i] = random - l1->vet[i].val;
			result1 = result1+(random - l1->vet[i].val);
		}
		for(int i = l2->first; i < l2->last; i++){
			vet2[i] = random - l2->vet[i].val;
			result2 = result2+(random - l2->vet[i].val); 
		}

		for(int i = 0; i < MAXTAMB; i++){
			Item d;
			d.val = vet1[i];
			ListBInsert(l3, d);
		}
		for(int i = 0; i < MAXTAMB; i++){
			Item d;
			d.val = vet2[i];
			ListBInsert(l4, d);
		}

		if(result1 > result2){
			printf("L1 é o ganhador! \n\n");
		}else if(result2 > result1){
			printf("L2 é o ganhador! \n\n");
		}else if(result1 == result2){
			printf("Empate!");
		}
	
		PrintListB(l3,l4);
	}
	```
	#### Exemplo de execução: ####
	![menu1](https://user-images.githubusercontent.com/60747654/128635298-4a251c0b-0874-4a11-919a-e7e60ed5e3e2.PNG)
	
	![menu2](https://user-images.githubusercontent.com/60747654/128635302-c8e63a5c-be40-4fcb-8c89-378080c7d798.PNG)
	
	![game](https://user-images.githubusercontent.com/60747654/128635303-2dcd02e7-6381-4e6c-b5aa-9c706f57df1c.PNG)

	
- c) 

## Problema 2 - Pilhas ##
### Enunciado ###

É de conhecimento que a estrutura do tipo pilha define regras de manipulação que não podem
ser modificadas e que essas são comumente citadas como ações de PUSH (empilhar) e POP
(desempilhar). Sabendo-se disso e mediante as regras de desenvolvimento já apresentadas
faça:

- a: Escreva um programa que utilize uma pilha para verificar se expressões aritméticas estão
com a parentização correta. O programa deve verificar as expressões para ver se cada
“abre parênteses” tem um “fecha parênteses”. Veja exemplo: 
Correto -> ( ( ) ) – ( ( )( ) ) – ( ) ( ) 
Errado -> ( ( ) – ( ( )( ) ) – ( ) ( ).

- b: Elabore um programa utilizando duas pilhas dinâmicas P1 e P2. O objetivo desse programa é transferir os dados da pilha P1 para P2 mantendo-se a ordem de P1 em P2. Para
tanto, não é permitido a utilização de nenhuma estrutura ou variável auxiliar, apenas um
único ponteiro auxiliar do mesmo tipo utilizado para marcar topo e fundo.

- c: Elabore uma função que receba uma pilha P1 com 20 posições preenchidas por números
inteiros aleatórios entre 1 e 99. Para cada número da pilha, utilize a função totiente de
Euler para encontrar para esse número os co-primos. Mostre-os na tela como resultado
de sua execução.

### Resolução ###

- a 
- b 
- c 

## Problema 3 - Filas ##
### Enunciado ###

Uma estrutura baseada em fila tem por definição a regra de sempre remover do início e inserir
novos elementos no final. Sabendo-se disso, vamos praticar a utilização desse conceito nos
seguintes problemas:

- a: Em matemática discreta é muito comum nos depararmos com o conceito de binômio de
Newton. O binômio de Newton fornece os coeficientes da expansão de potência para uma
expressão binomial. Sua missão é criar uma função que receba uma Fila cujas posições
representem expressões binomiais do tipo (x+y)
k e retorne para o usuário uma segunda
fila Fresult com a expansão de cada expressão apresentada. Mostre na tela os resultados,
um por linha.

- b: Atualmente, uma das formas de classificar uma entrada qualquer é observar seus atributos em relação a um conjunto de informações já conhecida. Nesse cenário, vamos considerar que esse conjunto de atributos é do tipo inteiro e com variação de 1 a 99, o que
é verdade também para o conjunto de informações conhecida. A estrutura que guarda
as informações conhecidas é definida pelo seguinte modelo: Cada posição da fila há um
atributo e seu peso por classe. Considere que há 5 classes, logo, teremos um vetor de
5 posições como parte de cada posição da fila. Sabendo-se disso, elabore um procedimento/função que dado uma fila de atributos não classificados seja possível buscar essa
classificação entre as informações disponíveis. Mostre para usuário qual a classe que o dado conjunto faz parte. Para isso, considere que a classe de maior valor corresponde
à classe da fila dada. Nesse sentido, some o valor de classe de cada atributo da fila de
entrada e encontre a classe que no final apresente o maior valor. Mostre essa classe
encontrada como resultado.
### Resolução ###

- a 
- b  

