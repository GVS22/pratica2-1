#include "problema2.h"

void Verify(char *str, Pilha *p1){

	for(int i = 0; str[i] != '\0'; i++){
		Itemp d;
		d.val = str[i];
		if(str[i] == '('){
			PUSH(p1, d);
		}else if(str[i] == ')'){
			POP(p1, &d);
		}
	}
	for(int i=p1->top-1; i>=p1->base; i--){
		if(p1->base == p1->top){
			printf("Parenteses balanceados!\n");
		}else if(p1->vet[i].val == '('){
			printf("Parenteses Desbalanceados!\n");
			printf("Parenteses que nao se fecham:\n");
			PilhaImprime(p1);
		}
	}	
}

void PilhaMain(){
    int op = 1;
	do{
        printf("-------------------------------------\n");
		printf("-------| PROBLEMA 2 : PILHAS |-------\n");
		printf(" ------|(1) letra a          |-------\n");
		printf(" ------|(2) letra b          |-------\n");
		printf(" ------|(3) letra c          |-------\n");
		printf(" ------|(0) para sair        |-------\n");
		printf("-------------------------------------\n");
		scanf("%d", &op);
		printf("\n\n");

        if(op == 1){
			Pilha p1;
    		PilhaVazia(&p1);
            char str[] = "(())(())(";
            Verify(str, &p1);
            op = 0;
        }else if(op == 2){
            op = 0;
        }else if(op == 3){
            op = 0;
        }else if(op == 0){
            op = 0;
        }
    }while(op != 0);
    	

}