#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void) {
	int n; 
	double num;
	double c1 = 0.44721359549995793928;
	double c2 = 0.48121182505960344750;
	printf("N: ");
	scanf("%d", &n);
	for(double i=0; i<n; i++) {
		num = round(c1 * pow(M_E, (i*c2)));
		printf("%1.0f\n", num);
	}
}