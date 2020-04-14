#include <stdio.h>
#include <stdlib.h>

int factorial (int);
int verif (int[]);
int i[10];

int main (void) {
	int n, result;
	int num, a[6], indx;
	i[0] = 1;
	for(n=1; n<10; n++) {
		i[n]=i[n-1] * n;
	}
	for(n=1; n<1000000; n++) {
		num = n;
		a[5] = num/100000;
		num = num - a[5] * 100000;
		a[4] = num/10000;
		num = num - a[4] * 10000;
		a[3] = num/1000;
		num = num - a[3] * 1000;
		a[2] = num/100;
		num = num - a[2] * 100;
		a[1] = num/10;
		num = num - a[1] * 10;
		a[0] = num;
		indx = verif(a);
		result = 0;
		for(;indx>=0;indx--) {
			result += i[a[indx]];
			if(result==n) {
				printf("%d\n", n);
			}
		}
	}
	
}
int verif (int n[]) {
	int j;
	for(j=5; j>=0; j--) {
		if(n[j]!=0) {
			return j;
		}
	}
}
int factorial (int n)
{
	int i, fact = 1;
	for (i = n; i >1; i--) {
		fact *= i;
	}
	return fact;
}