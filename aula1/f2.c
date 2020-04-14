#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int n;
	int i, j, r = 0;
	printf("a iniciar f2...\n");
	printf("n: ");
	scanf("%d", &n);
	for(i=1; i<=n; i++) {
		for(j=1; j<=i; j++) {
			r += 1;
		}
	}
	printf("r: %d\n", r);
}

