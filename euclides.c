#include<stdio.h>

int main(void){

    int x = 294, y = 108, resto;

    	do {
        	resto = x % y;

        	x = y;
        	y = resto;

    	} while (resto != 0);

    	printf("%d", x);

    return 0;
}