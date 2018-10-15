#include "stdio.h"
#include "stdlib.h"
#define MAX 45

void print(long b[MAX][MAX], int n, int k)
{
	int i, j;
	for(i = 0; i <= n; i++) {
		for(j = 0; j <= i; j++) {
			printf("%ld  ", b[i][j]);
		}
		printf("\n");
	}
}
long binom_coeff(n, k) 
int n,k;
{
	long b[MAX][MAX];
	int i,j;
	for(i = 0; i <= n; i++) { b[i][0] = 1;}
	for(j = 1; j <= n; j++) { b[j][j] = 1;}//you can stop at k, but to get Pascal's triangle you need to go to n
	for(i = 2; i <= n; i++) {
		for(j = 1; j < i; j++) { //again, u can stop at k, but to get lower triangle u need to stop at i-1
			b[i][j] = b[i-1][j-1] + b[i-1][j];
		}
	}
	print(b, n, k);
	return b[n][k];
}

int main(int argc,char *argv[]) {
	long result = binom_coeff(atoi(argv[1]), atoi(argv[2]));	
	printf("\nresult %ld\n", result);
}

