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

long int euclidesEstendido(long int a, long int b){

    long int m2, m1, m, n2, n1, n, resto, quo, borig;

	borig = b;

	m2 = 1; m1 = 0;
	n2 = 0; n1 = 1;

	do{
		resto = a % b;
		quo = a / b;

		m = m2 - (m1 * quo);
		n = n2 - (n1 * quo);
		m2 = m1; m1 = m; n2 = n1; n1 = n;

		a = b;
		b = resto;

	} while(resto != 0);

	if(m2 < 0)
		return (m2 + borig);
	else
		return m2;

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

				ok = ((((__uint128_t)s * s) % n) * v) % n;
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

						srand((unsigned)time(NULL));
						r = rand();
					}

					x = (((__uint128_t)r * r) % n);

					printf("C %lu\n", x);
				}
				else{

					printf("E\n");
				}

			break;

			case 'P':

				if(verificado){

					scanf("%lu", &r);

					if(r > n){
						printf("E\n");
						break;
					}

					x = (((__uint128_t)r * r) % n);

					printf("C %lu\n", x);
					resp = false;
				}
				else{

					printf("E\n");
				}

			break;

			case 'R':

				scanf("%d", &b);

				if(verificado == false){

					printf("E\n");
				}

				if(b == 0 && resp == false){

					printf("C %lu\n", r);
					r = 0;
					resp = true;
				}

				else if(b == 1 && resp == false){

					y = (((__uint128_t)r * s) % n);
					printf("C %lu\n", y);
					r = 0;
					resp = true;
				}

				else
					printf("E\n");
				
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
				
				else{
					printf("C\n");
					verificado = true;
				}

			break;

			case 'Q':

				if(validar && verificado){

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

				if (t == 0 || verificado == false){
					printf("E\n");
					break;
				}

				if(b == 0){

					if((((__uint128_t)fabx * fabx) % n) == x){
						
						printf("C %d", --t);
						validar = true;
					}

					else{
						
						printf("E %d\n", t);
						t = torig;
					}
				}

				else if(b == 1){

					if((((((__uint128_t)fabx * fabx) % n) * v) % n) == x){

						printf("C %d", --t);
						validar = true;
					}

					else{
						
						printf("E %d\n", t);
						t = torig;
					}
				}

			break;

			case 'C':

				if(verificado == false){
					printf("E\n");
					break;
				}

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

void teodoro(){

	long int p, q, n, s, v, ss;
	char tarefa;

	while(tarefa != 'T'){

		scanf("%c", &tarefa);

		switch(tarefa){

			case 'I':

				scanf("%li %li", &p, &q);
				n = p * q;
				printf("C %li\n", n);

				verificado = true;

			break;	

			case 'A':

				if(verificado == false){
					printf("E\n");
					break;
				}

				srand((unsigned)time(NULL));
				s = rand() % (n - 1);

				printf("%li\n", s);

			break;

			case 'F':

				if(verificado == false){
					printf("E\n");
					break;
				}

				scanf("%li", &s);
				ss = ((__uint128_t)s * s);

				v = euclidesEstendido(ss, n);

				if(((((((__uint128_t)s * s) % n) * v) % n) == 1) && s < n)
					printf("C %li\n", v);
				else
					printf("E\n");

			break;
		}
	}
	printf("C\n");
}

void ester(){

	char tarefa;
	unsigned long int n, v, x, fabx, x0, x1, s;
	int b;

	while(tarefa != 'T'){

		scanf("%c", &tarefa);

		switch(tarefa){

			case 'I':

				scanf("%lu %lu", &n, &v);
				printf("C\n");

				verificado = true;

			break;

			case 'P':

				if(verificado == false){
					printf("E\n");
					break;
				}

				scanf("%d", &b);

				if(b == 0){
					
					srand((unsigned)time(NULL));
					fabx = rand();
					x = (((__uint128_t)fabx * fabx) % n);

					printf("C %lu %lu\n", x, fabx);
				}

				else if(b == 1){

					srand((unsigned)time(NULL));
					fabx = rand();
					
					x = (((((__uint128_t)fabx * fabx) % n) * v) % n);

					printf("C %lu %lu\n", x, fabx);
				}

			break;

			case 'S':

				if(verificado == false){
					printf("E\n");
					break;
				}

				scanf("%lu %lu", &x0, &x1);

				s = (euclidesEstendido(x0, n) * x1) % n;

				printf("C %lu\n", s);

			break;
		}
	}
	printf("C\n");
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