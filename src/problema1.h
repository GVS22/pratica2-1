#ifndef PROBLEMA1_H
#define PROBLEMA1_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>
#define MAXTAM 100
#define MAXTAMB 3

typedef struct Item1 Item1;
typedef struct Block1 Block1;
typedef struct Lista1 Lista1;

typedef struct Item2 Item2;
typedef struct Block2 Block2;
typedef struct Lista2 Lista2;

typedef struct Item3 Item3;
typedef struct Block3 Block3;
typedef struct Lista3 Lista3;

struct Item1{
	char *prd;
    int qtd;
    int id;
};

struct Item2{
	char *mercado;
    int idm;
};

struct Item3{
    int pxm;
	int valor;
};

struct Block1{
	Item1 data;
	Block1 *prox;
};

struct Block2{
	Item2 data;
	Block2 *prox;
};

struct Block3{
	Item3 data;
	Block3 *prox;
};

struct Lista1{
	Block1 *first;
	Block1 *last;
};

struct Lista2{
	Block2 *first;
	Block2 *last;
};

struct Lista3{
	Block3 *first;
	Block3 *last;
};

typedef struct Item{
	int val;
}Item;

typedef struct Lista{
    Item vet[100];
    int first;
    int last;
}Lista;

typedef struct Listab{
    Item vet[3];
    int first;
    int last;
}Listab;

void ListMain();

void EmptyList(Lista *l);
void PrintList(Lista *l);
void ListInsert(Lista *l, Item d);
void ListA(Lista *par, Lista *imp, Lista *conc);

void Swap(Item *a, Item *b);
void ListBRemove(Listab *l, Item d);
void ListBInsert(Listab *l, Item d);
void EmptyListB(Listab *l);
void PrintListB(Listab *l1, Listab *l2); 
void ListB(Listab *l1, Listab *l2);
void GameB(Listab *l1, Listab *l2, int random);

// void ListC();
void EmptyListC(Lista1 *l1, Lista2 *l2, Lista3 *l3);


#endif
