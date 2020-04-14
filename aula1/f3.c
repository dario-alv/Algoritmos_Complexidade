#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int n;
	int i, j, r = 0, cont=0;
	printf("a iniciar f3...\n");
	printf("n: ");
	scanf("%d", &n);
	for(i=1; i<=n; i++) {
		for(j=i; j<=n; j++) {
			r += j;
			cont++;
		}
	}
	printf("r: %d\n", r);
	printf("cont: %d\n", cont);
}

