#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//ver fibRecAula.c primeiro, isto é tão estupido quanto parece
typedef unsigned long long int u64;

u64 f2(int n) {
	assert(n>=0);
	if(n==0) {
		return 0;
	} else if (n==1) {
		return 1;
	}
	u64 num, n1 = 0, n2 = 1;
	for(int i=1; i<n; i++) {
		num = n1 + n2;
		n1 = n2;
		n2 = num;
	}
	return num;
}

int main (void) {
	int n;
	printf("N: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		printf("%d: %llu\n", i, f2(i));
	}
}