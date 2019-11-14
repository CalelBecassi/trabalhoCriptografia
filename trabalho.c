#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef __uint128_t gint;

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

	unsigned long int r, x;
	bool verificado = false;

	if(tarefa == 'I'){

		if(((((s * s) % n) * v) % n) == 1){
			printf("C\n");
			verificado = true;
		}
		else
			printf("E\n");
	}

	else if(tarefa == 'X'){

		if(verificado){

			while(mdc(r, n) != 1){

				srand((unsigned)time(NULL));
				r = rand();
			}

			x = (((r % n) * r) % n); /******************* PAREI AQUI **********/
		}
		else
			printf("E\n");
	}

	else if(tarefa == 'R'){

	}
}

void patricia(char tarefa){


}

void teodoro(char tarefa){

	unsigned long int p, q;
	char num[50];
	__uint128_t n;

	if(tarefa == 'I'){

		scanf("%lu", &p);
		printf("%lu\n", p );
		scanf("%lu", &q);

		n = 340282366920938463463374607431768;

		sprintf(num, "%lu", n);

		printf("%s\n", num);
	}
}

int main(int argc, char *argv[]){

	teodoro('I');

	return 0;
}
