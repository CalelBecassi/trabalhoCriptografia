#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>

bool verificado = false, resp = false;

unsigned long int mdc(int x, int y){
		int resto;

    	do {
        	resto = x % y;

        	x = y;
        	y = resto;

    	} while (resto != 0);

    	return x;
}

void fabio(){

	char tarefa;
	unsigned long int r, x, n, s, v, y;
	int b;

	while(tarefa != 'T'){

		scanf("%c", &tarefa);

		switch(tarefa){
		
			case 'I':

				scanf("%lu %lu %lu", &n, &s, &v);

				if(((((s * s) % n) * v) % n) == 1){
					printf("C\n");
					verificado = true;
				}
				else
					printf("E\n");

			break;

			case 'X':

				if(verificado){

					r = 0;
					while(mdc(r, n) != 1){

						srand((unsigned)time(NULL));//falta usar "busca binaria" pra ele ser uniformemente distribuído
						r = rand();
					}

					x = (((r % n) * r) % n);

					printf("C %lu\n", x);
				}
				else{

					printf("E\n");
					exit(0);
				}

			break;

			case 'P':

				if(verificado){

					scanf("%lu", &r);

					x = (((r % n) * r) % n);

					printf("C %lu\n", x);
				}
				else{

					printf("E\n");
					exit(0);
				}

			break;

			case 'R': //falta corrigir a impressão de erro caso ja tiver respondido

				scanf("%d", &b);

				if(verificado == false){

					printf("E\n");
					// exit(0); depende de como for não responder a mais de uma tentativa de validação
				}

				if(b == 0 /*&& resp == false*/){

					printf("C %lu\n", r);
					r = 0;
					resp = true;
				}

				else if(b == 1 /*&& resp == false*/){

					y = (((r % n) * s) % n); //tem que adaptar pra caso r 128 bits
					printf("C %lu\n", y);
					r = 0;
					resp = true;
				}

				else
					printf("E\n");
					// exit(0); depende de como for não responder a mais de uma tentativa de validação
				
			break;
		}
	}

	printf("C\n");
}	

void patricia(char tarefa){

}

/*void teodoro(char tarefa){ // TODO CAGADO

	unsigned long int p, q;
	char num[50];

	if(tarefa == 'I'){

		scanf("%lu", &p);
		printf("%lu\n", p );
		scanf("%lu", &q);

		n = 340282366920938463l;

		sprintf(num, "%lu", n);

		printf("%s\n", num);
	}
}*/

int main(int argc, char *argv[]){

	switch(*argv[1]){

		case 'F':
			fabio();
		break;
	}

	return 0;
}
