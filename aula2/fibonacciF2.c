#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void) {
	int n; 
	double num, fi;
	fi = (1.0 + sqrt(5.0)) / 2.0;
	printf("N: ");
	scanf("%d", &n);
	for(double i=0; i<n; i++) {
		num = round(pow(fi, i)/sqrt(5.0));
		printf("%1.0f\n", num);
	}
}