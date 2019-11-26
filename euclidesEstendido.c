#include<stdio.h>

void euclidesEstendido(int a, int b){

    int m2, m1, m, n2, n1, n, resto, quo, aorig, borig;

	aorig = a;
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

	if(((aorig*m2) + (borig * n2)) == a)
		printf("DEU CERTO m = %d n = %d\n", m2, n2);
}

int main(void){
	euclidesEstendido(294, 108);

	return 0;
}