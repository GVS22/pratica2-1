# Pratica 2 - Algoritmo e Estrutura de Dados #
Trabalho realizado para a disciplina de Algoritmo e Estrutura de Dados \
CEFET - MG Campus V \
Jorge Vitor G. de Souza
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

## Problema 2 - Pilhas ##

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

## Problema 3 - Filas ##

## Compilar ##
```
  make
  make run
```
