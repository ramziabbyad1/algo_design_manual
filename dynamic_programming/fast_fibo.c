#include "stdio.h"
#include "stdlib.h"

long fib_fast(int n) {
	long back1, back2, next;
	back1 = 1; back2 = 0; next = 0;
	if( n == 0 ) return 0;
	if( n == 1 ) return 1;
	int i = 1;
	for(; i < n; i++) {
		next = back1 + back2;
		long temp = back1;
		back1 = next;
		back2 = temp;
	}
	return next;
}

int main(int argc,char *argv[]) {
	long result = fib_fast(atoi(argv[1]));	
	printf("%ld\n", result);
}

