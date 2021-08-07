#include "problema3.h"

int fat(int n){
    int fatorial = 0;
    for(fatorial = 1; n > 1; n = n - 1){
        fatorial = fatorial * n;
    }
    return fatorial;
}

int combinacao(int n, int p){   
    int c;
    int aux;
    aux = n - p;
    c = fat(n);
    c = c/(fat(p)*fat(aux));
    return c;
}

void Binomio(int n, char x, char y, FilaDR *res){

    for(int j = 0; j <= n; j++){
        if(j < n){
            char *str = malloc(sizeof(str));
            sprintf(str, "%d(%c^%d * %c^%d) + ", combinacao(n, j), x,n-j, y, j);
            ItemR r;
            r.result = str;
            EnfileiraRes(res, r);
        }else if(j == n){
            char *str = malloc(sizeof(str));
            sprintf(str, "%d(%c^%d * %c^%d)\n", combinacao(n, j), x,n-j, y, j);
            ItemR r;
            r.result = str;
            EnfileiraRes(res, r);    
        }
    }
}

void FilaMain(){
    int op; 
    printf("-------------------------------------\n");
	printf("-------| PROBLEMA 3 : FILAS  |-------\n");
	printf(" ------|(1) letra a          |-------\n");
	printf(" ------|(2) letra b          |-------\n");
	printf(" ------|(0) para sair        |-------\n");
	printf("-------------------------------------\n");
	scanf("%d", &op);
	printf("\n\n");

    if(op == 1){
        FilaD f;
        FilaDVazia(&f);
        FilaDR res;
        FilaResVazia(&res);
        int max = 7;
        for(int i = 2; i < max; i++){
            Itemf d;
            d.k = i;
            d.x = 'a';
            d.y = 'b';
            Enfileira(&f, d);   
        }
        FilaDImprime(&f);
        printf("\n");
        Blockf *aux;
        aux = f.first->prox;
        while(aux != NULL){
            Binomio(aux->data.k, aux->data.x, aux->data.y, &res);
            aux = aux->prox;
        }
        FilaResImprime(&res);
        op = 0;
    }else if(op == 2){

    }else if(op == 0){
        op = 0;
    }else{
        op = 0;
    }
}   
