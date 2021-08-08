#include "problema4.h"

void EmptyClient(Listacl *l){
    l->first = (Blockcl*) malloc (sizeof(Blockcl));
	l->last  = l->first;
	l->first->prox = NULL;
}

void ClientInsert(Listacl *l, Itemcl d){
    l->last->prox = (Blockcl*) malloc (sizeof(Blockcl));
	l->last = l->last->prox;
	l->last->data = d;
	l->last->prox = NULL;
}

void ClientPrint(Listacl *l){
    Blockcl *aux;

	aux = l->first->prox;
	while(aux != NULL){
		printf("Cliente: %s\n", aux->data.client);
		aux = aux->prox;
	}
}

void EmptyProd(Pilhapp *p){
	p->base = (Blockpp*) malloc (sizeof(Blockpp));
	p->top  = p->base;
	p->base->prox = NULL;
}

void PushProd(Pilhapp *p, Itempp d){
    Blockpp *aux = (Blockpp*) malloc (sizeof(Blockpp));
	aux->data = d;
	aux->prox = p->top;
	p->top = aux;
}



void PopProd(Pilhapp *p, Itempp *d){
    Blockpp *aux;

	if(p->base == p->top || p == NULL){
		printf("PILHA VAZIA!\n");
		return;
	}
	
	aux = p->top;
	p->top = aux->prox;
	*d = aux->data;
}

void ProdImprime(Pilhapp *p){
    Blockpp *aux;

	aux = p->top;
	while(aux != p->base){
		printf("Produto: %s\n", aux->data.produto);
        printf("Valor: %.2f\n", aux->data.val);
		aux = aux->prox;
	}

}

void FilaFVazia(Filaff *f){
    f->first = (Blockff*) malloc (sizeof(Blockff));
	f->last  = f->first;
	f->first->prox = NULL;
}

void EnfileiraF(Filaff *f, Itemff d){
    f->last->prox = (Blockff*) malloc (sizeof(Blockff));
	f->last = f->last->prox;
	f->last->data = d;
	f->last->prox = NULL;
}

void DesenfileiraF(Filaff *f, Itemff *d){
    Blockff *aux;

	if(f->first == f->last || f == NULL || f->first->prox == NULL){
		printf("FILA VAZIA!\n");
		return;
	}
	
	aux = f->first;
	f->first = f->first->prox;
	d->cliente   = aux->data.cliente;
	free(aux);
}

void FFImprime(Filaff *f){
    Blockff *aux;

	aux = f->first->prox;
	while(aux != NULL){
		printf("%s\n", aux->data.cliente);
		aux = aux->prox;
	}
}

void problema4(){
    
}