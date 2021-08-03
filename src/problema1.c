#include "problema1.h"

void EmptyList(Lista *l){
	l->first = 0;
	l->last  = 0;
}

void ListInsert(Lista *l, Item d){
	if (l->last >= MAXTAM){
		printf("LISTA CHEIA!\n");
	}else{
		l->vet[l->last] = d;
		l->last ++;
	}
}

void PrintList(Lista *l){
    for(int i = l->first; i < l->last; i++){
		printf("%d:%d\t", i,l->vet[i].val);
		printf("\n");
	}
}

void ListA(Lista *par, Lista *imp, Lista *conc){
	int aux1 = 0;

	srand((unsigned)time(NULL));
	while(aux1 != MAXTAM){
		Item d;
		d.val = rand()%99;
		if(d.val % 2 == 0 && d.val != 0){
			ListInsert(par, d);
			aux1++;
		}
	}

	int aux2 = 0;
	while(aux2 != MAXTAM){
		Item d;
		d.val = rand()%99;
		if(d.val % 2 == 1 && d.val != 0){
			ListInsert(imp, d);
			aux2++;
		}
	}

	char str[10];
	int result;
	for(int i = par->first; i < par->last; i++){
		Item c;
		//printf("(%d,%d) \n", par->vet[i].val, imp->vet[i].val);
		sprintf(str, "%d%d",  par->vet[i].val, imp->vet[i].val);
		result = strtol(str, NULL, 10);
		c.val = result;
		ListInsert(conc, c);
	}
}

void EmptyListB(Listab *l){
	l->first = 0;
	l->last  = 0;
}

void ListBInsert(Listab *l, Item d){
	if (l->last >= MAXTAMB){
		printf("LISTA CHEIA!\n");
	}else{
		l->vet[l->last] = d;
		l->last ++;
	}
}

void PrintListB(Listab *l1, Listab *l2){
    for(int i = l1->first; i < l1->last; i++)
		printf("(%d,%d)\t", l1->vet[i].val, l2->vet[i].val);
	printf("\n");
}

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

void Swap(Item *a, Item *b){
	Item aux;
	aux = *a;
	*a  = *b;
	*b  = aux;
}

void ListBRemove(Listab *l, Item d){
	bool ok = false;

	if(l->first == l->last)
		printf("LISTA VAZIA!\n");
	else{
		for(int i=l->first; i<l->last; i++)
			if(l->vet[i].val == d.val){
				Swap(&l->vet[i], &l->vet[i+1]);
				ok = true;	
			}
		if(ok)
			l->last --;
	}
}

void GameB(Listab *l1, Listab *l2, int random){
	int result1 = 0;
	int result2 = 0;

	for(int i = l1->first; i < l1->last; i++){
		result1 = result1+(random - l1->vet[i].val);
	}
	for(int i = l2->first; i < l2->last; i++){
		result2 = result2+(random - l2->vet[i].val); 
	}

	if(result1 > result2){
		printf("L1 é o ganhador! \n\n");
	}else if(result2 > result1){
		printf("L2 é o ganhador! \n\n");
	}else if(result1 == result2){
		printf("Empate!");
	}	
}

void EmptyListC(Lista1 *l1, Lista2 *l2, Lista3 *l3){
	l1->first = (Block1*) malloc (sizeof(Block1));
	l1->last  = l1->first;
	l1->first->prox = NULL;

	l2->first = (Block2*) malloc (sizeof(Block2));
	l2->last  = l2->first;
	l2->first->prox = NULL;

	l3->first = (Block3*) malloc (sizeof(Block3));
	l3->last  = l3->first;
	l3->first->prox = NULL;
}

void List1Insert(Lista1 *l1, Item1 d1){
	l1->last->prox = (Block1*) malloc (sizeof(Block1));
	l1->last = l1->last->prox;
	l1->last->data = d1;
	l1->last->prox = NULL;
}

void List2Insert(Lista2 *l2, Item2 d2){
	l2->last->prox = (Block2*) malloc (sizeof(Block2));
	l2->last = l2->last->prox;
	l2->last->data = d2;
	l2->last->prox = NULL;
}

void List3Insert(Lista3 *l3, Item3 d3){
	l3->last->prox = (Block3*) malloc (sizeof(Block3));
	l3->last = l3->last->prox;
	l3->last->data = d3;
	l3->last->prox = NULL;
}
// void ListC(){

// }

void ListMain(){
	int op = 1;
	do
	{	
		printf("-------------------------------------\n");
		printf("-------| PROBLEMA 1 : LISTAS |-------\n");
		printf(" ------|(1) letra a          |-------\n");
		printf(" ------|(2) letra b          |-------\n");
		printf(" ------|(3) letra c          |-------\n");
		printf(" ------|(0) para sair        |-------\n");
		printf("-------------------------------------\n");
		scanf("%d", &op);
		printf("\n\n");

		if(op == 1){
			Lista par;
    		Lista imp;
    		Lista conc;

    		EmptyList(&par);
    		EmptyList(&imp);
    		EmptyList(&conc);

    		ListA(&par, &imp, &conc);
			printf("\n\n");
			printf("Lista Par: \n");
			PrintList(&par);
			printf("\n\n");
			printf("Lista Impar: \n");
			PrintList(&imp);
			printf("\n\n");
			printf("Lista Concatenada: \n");
			PrintList(&conc);
			printf("\n\n");

			op = 0;

		}else if(op == 2){
			Listab l1;
			Listab l2;

			EmptyListB(&l1);
			EmptyListB(&l2);

			ListB(&l1, &l2);
			printf("L1 & L2: \n\n");
			PrintListB(&l1, &l2);

			srand((unsigned)time(NULL));
			int random = (rand()%12)+1;
			printf("\n");
			printf("NUMERO RANDOMICO: %d", random);
			printf("\n\n");

			GameB(&l1, &l2, random);

			op = 0;
		}else if(op == 3){
			Lista1 l1;
			Lista2 l2;
			Lista3 l3;

			EmptyListC(&l1, &l2, &l3);

			Item1* p1 = malloc(sizeof(Item1));
			Item1* p2 = malloc(sizeof(Item1));
			Item1* p3 = malloc(sizeof(Item1));
			Item1* p4 = malloc(sizeof(Item1));
			p1->prd = "arroz";
			p1->id = 10;
			p1->qtd = 5;
			p2->prd = "feijao";
			p2->id = 11;
			p2->qtd = 4;
			p3->prd = "batata";
			p3->id = 12;
			p3->qtd = 3;
			p4->prd = "cenoura";
			p4->id = 13;
			p4->qtd = 2;
			Item2* m1 = malloc(sizeof(Item2));
			Item2* m2 = malloc(sizeof(Item2));
			Item2* m3 = malloc(sizeof(Item2));
			m1->mercado = "ABC";
			m1->idm = 1;
			m2->mercado = "BH";
			m2->idm = 2;
			m3->mercado = "Rena";
			m3->idm = 3;

			
			op = 0;
		}else if(op == 0){
			printf("Finalizando programa!\n");
		}else{
			printf("Opção inválida! \n");
			printf("Finalizando programa!\n");
			op = 0;	
		}
		
	} while (op != 0);
		
}