#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//tipo para guardar valores muito grandes
typedef unsigned long long int u64;

//função devolve esse tipo, literalmente feito de maneira bruta
//sem passagem de argumentos etc, cada vez calcula tudo do inicio
//é para ver que demora para valores grandes -_- uau! quem diria!
u64 f1(int n) {
	assert(n>=0);
	if(n==0) {
		return 0;
	}
	if (n==1) {
		return 1;
	} 
	return f1(n-1) + f1(n-2);
}

int main (void) {
	int n;
	printf("N: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		//%llu long long unsigned é um tipo em c pelos vistos
		printf("%d: %llu\n", i, f1(i));
	}
}
