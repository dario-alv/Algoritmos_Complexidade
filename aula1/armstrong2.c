#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int a1, a2, a3, result, n = 99;
	for(a3=1; a3<=9; a3++) {
		for(a2=0; a2<=9; a2++) {
			for(a1=0; a1<=9; a1++) {
				n++;
				result = a1*a1*a1 + a2*a2*a2 + a3*a3*a3;
				if(n == result) {
					printf("%d\n", n);
				}
			}
		}
	}
}