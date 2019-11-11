#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef __uint128_t gint;

void fabio(char tarefa){

	int mdc(int x, int y){
		int resto;

    	do {
        	resto = x % y;

        	x = y;
        	y = resto;

    	} while (resto != 0);

    	return x;
	}

	unsigned long int r;


	if(tarefa == 'I'){

	}

	else if(tarefa == 'X'){

		//scanf()

		while(mdc(r, n) != 1){

			srand((unsigned)time(NULL));
			r = rand();
		}
	}

	else if(tarefa == 'R'){

	}

	else if(tarefa == 'T'){

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
