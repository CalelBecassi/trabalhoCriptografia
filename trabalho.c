#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>

typedef __uint128_t gint;
bool verificado = false, resp = false/*, iniciado = false*/;

unsigned long int mdc(int x, int y){
		int resto;

    	do {
        	resto = x % y;

        	x = y;
        	y = resto;

    	} while (resto != 0);

    	return x;
	}

void fabio(char tarefa){

	unsigned long int r, x, n, s, v, y;
	int b;

	if(tarefa == 'I'){

		scanf("%lu %lu %lu", &n, &s, &v);

		if(((((s * s) % n) * v) % n) == 1){
			printf("C\n");
			verificado = true;
		}
		else
			printf("E\n");
	}

	else if(tarefa == 'X'){ //ERRO,SEMPRE QUE EXECUTA A TAREFA, O x É O MESMO E DEVERIA SER DIFERENTE

		if(verificado){

			while(mdc(r, n) != 1){//não ta entrando após ter sido executado 1x

				srand((unsigned)time(NULL));//falta usar "busca binaria" pra ele ser uniformemente distribuído
				r = rand();
				printf("%lu\n", r); //pra testar os r gerados e se entra no laço
			}

			x = (((r % n) * r) % n); //x Sempre o mesmo, e depois de rodar tarefe P o x passa a ser o mesmo do x da P

			printf("C %lu\n", x);
			//iniciado = true;
		}
		else{

			printf("E\n");
			exit(0);
		}
	}

	else if(tarefa == 'P'){

		if(verificado){

			scanf("%lu", &r);

			x = (((r % n) * r) % n);

			printf("C %lu\n", x);
		}
		else{

			printf("E\n");
			exit(0);
		}
	}

	else if(tarefa == 'R'){ //falta corrigir a impressão de erro caso não foi iniciado ainda

		scanf("%d", &b);

		/*if(resp || iniciado == false){
			printf("E\n");
			exit(0);
		}*/

		if(b == 0){

			printf("C %lu\n", r);
			r = 0;
			resp = true;
		}
		
		else if(b == 1){

			y = (((r % n) * s) % n); //tem que adaptar pra caso r 128 bits
			printf("C %lu\n", y);
			r = 0;
			resp = true;
		}

		else
			printf("E\n");
	}
}

void patricia(char tarefa){


}

void teodoro(char tarefa){ // TODO CAGADO

	unsigned long int p, q;
	char num[50];
	gint n;

	if(tarefa == 'I'){

		scanf("%lu", &p);
		printf("%lu\n", p );
		scanf("%lu", &q);

		n = 340282366920938463l;

		sprintf(num, "%lu", n);

		printf("%s\n", num);
	}
}

int main(int argc, char *argv[]){

	char tarefa;

	while(tarefa != 'T'){ //o ideal é não sair da função chamada, e não do jeito que está

		fabio(tarefa);
		scanf("%c", &tarefa);
	}

	printf("C\n");

	return 0;
}
