#include<stdio.h>
#include<stdint.h>

int main(void){

	long int n = 1083581, r = 341975, x1 = 787651, s, r1, q, i;

	r1 = r % n;

	x1 = x1 / r1;

	printf("%li\n", x1);

	for(i = 0; i < n; i++){
		if(i == (x1 + (n * (i/n))))
			printf("DEU CERTO %lu\n", i);
	}

	return 0;
}