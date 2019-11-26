#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>

bool verificado = false, resp = false, validar = true;

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
	unsigned long int r, x, n, s, v, y, ok;
	int b;

	while(tarefa != 'T'){

		scanf("%c", &tarefa);

		switch(tarefa){
		
			case 'I':

				scanf("%lu %lu %lu", &n, &s, &v);

				ok = (((s * s) % n) * v) % n;//FALTA COLOCAR PRA 128BITS
				if(ok == 1){
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

void patricia(){

	char tarefa;
	unsigned long int n, v, x, fabx;
	int b, t, torig;

	while(tarefa != 'T'){

		scanf("%c", &tarefa);

		switch(tarefa){

			case 'I':

				scanf("%lu %lu %d", &n, &v, &t);
				torig = t;

				if(t > 50 || t < 3)
					printf("E\n");
				
				else
					printf("C\n");

			break;

			case 'Q':

				if(validar){

					scanf("%lu", &x);

					srand((unsigned)time(NULL));
					b = rand() % 2;

					printf("C %d\n", b);
					validar = false;
				}
				else
					printf("E\n");

			break;

			case 'V':

				scanf("%lu", &fabx);

				if (t == 0){
					printf("E\n");
					break;
				}

				if(b == 0){

					if(((fabx * fabx) % n) == x){
						
						printf("C %d", --t);
						validar = true;
					}

					else
						printf("E %d\n", t);//TAMBÉM DEVE REINICIAR O CONTADOR?
				}

				else if(b == 1){

					if(((((fabx * fabx) % n) * v) % n) == x){

						printf("C %d", --t);
						validar = true;
					}

					else
						printf("E %d\n", t);//TAMBÉM DEVE REINICIAR O CONTADOR?
				}

			break;

			case 'C':

				scanf("%lu %d %lu", &x, &b, &fabx);

				if (t == 0){
					printf("E 0\n");
					break;
				}
			
				if(b == 0){

					if((((__uint128_t)fabx * fabx) % n) == x){
						
						printf("C %d\n", --t);
						validar = true;
					}

					else{
					
						printf("E %d\n", t);
						t = torig;
					}
				}

				else if(b == 1){

					if((((((__uint128_t)fabx * fabx) % n) * v) % n) == x){

						printf("C %d\n", --t);
						validar = true;
					}

					else{

						printf("E %d\n", t);
						t = torig;
					}
				}

			break;
		}
	}
	printf("C\n");
}

void teodoro(){ // TODO CAGADO

	unsigned long int p, q, n;
	char tarefa;

	while(tarefa != 'T'){

		scanf("%c", &tarefa);

		switch(tarefa){

			case 'I':

				scanf("%lu %lu", &p, &q);
				n = p * q;
				printf("C %lu\n", n);

			break;	

			case 'A':
			break;

			case 'F':
			break;
		}
	}
	printf("C\n");
}

void ester(){

}

int main(int argc, char *argv[]){

	switch(*argv[1]){

		case 'F':
			fabio();
		break;

		case 'P':
			patricia();
		break;

		case 'T':
			teodoro();
		break;

		case 'E':
			ester();
		break;
	}

	return 0;
}