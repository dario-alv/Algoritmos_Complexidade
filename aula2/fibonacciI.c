#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int n, ant1, ant2, num;
	printf("N: ");
	scanf("%d", &n);
	if(n>=1) {
		printf("%d\n", 0);
	}
	if(n>=2) {
		printf("%d\n", 1);
	}
	if(n>2) {
		ant2 = 0;
		ant1 = 1;
		for(int i=3; i<=n; i++) {
			num = ant2 + ant1;
			printf("%d\n", num);
			ant2 = ant1;
			ant1 = num;
		}
	}
}