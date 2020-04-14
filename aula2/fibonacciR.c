#include <stdio.h>
#include <stdlib.h>

void f(int, int, int, int);
int num;

int main (void) {
	int n;
	printf("N: ");
	scanf("%d", &n);
	if(n>2) {
		printf("%d\n%d\n", 0, 1);
		num = 0;
		f(0, 1, 3, n);
	} else if(n==2){
		printf("%d\n%d\n", 0, 1);
	} else if(n==1) {
		printf("%d\n", 0);
	}
}

void f(int n1, int n2, int i, int n) {
	num = n1 + n2;
	printf("%d\n", num);
	if(i!=n){
		f(n2, num, i+1, n);
	}
}