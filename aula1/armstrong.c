#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int i, n1, n2, n3, result;
	for(i=100; i<999; i++) {
		/*afinal existe % em c, possivelmente menos op que aqui
		 * mas deus me livre de ter paciencia para mudar isto agora
		 * */
		n3 = i/100;
		n2 = i/10 - 10*n3;
		n1 = i - 100*n3 - 10*n2;
		result = n1*n1*n1 + n2*n2*n2 + n3*n3*n3;
		if(i == result) {
			/*
			printf("n1: %d\n", n1);
			printf("n2: %d\n", n2);
			printf("n3: %d\n", n3);
			printf("r: %d\n", result);
			 * */
			printf("%d\n", i);
		}
	}
}