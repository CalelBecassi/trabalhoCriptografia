#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>

typedef __uint128_t gint;
bool verificado = false;

int mdc(int x, int y){
		int resto;

    	do {
        	resto = x % y;

        	x = y;
        	y = resto;

    	} while (resto != 0);

    	return x;
	}

void fabio(char tarefa){

	unsigned long int r, x, n, s, v;
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

			while(mdc(r, n) != 1){

				srand((unsigned)time(NULL));
				r = rand();
			}

			x = (((r % n) * r) % n); //x Sempre o mesmo, e depois de rodar tarefe P o x passa a ser o mesmo do x da P

			printf("C %lu\n", x);
		}
		else{

			printf("E\n"); //FALTA FINALIZAR PROGRAMA APÓS ERRO
		}
	}

	else if(tarefa == 'P'){

		if(verificado){

			scanf("%lu", &r);

			x = (((r % n) * r) % n);

			printf("C %lu\n", x);
		}
		else{

			printf("E\n"); //FALTA FINALIZAR PROGRAMA APÓS ERRO
		}
	}

	else if(tarefa == 'R'){

		scanf("%d", &b);

		if(b == 0)
			printf("%lu\n", r);
		
		else if
			r * s % n //tem que adaptar pra caso r 128 bits
	}
}

void patricia(char tarefa){


}

void teodoro(char tarefa){ // TODO CAGADO

	unsigned long int p, q;
	char num[50];
	__uint128_t n;

	if(tarefa == 'I'){

		scanf("%lu", &p);
		printf("%lu\n", p );
		scanf("%lu", &q);

		//n = 340282366920938463463374607431768;

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

	return 0;
}
