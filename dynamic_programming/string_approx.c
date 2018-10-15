#include "stdio.h"

#define MATCH 0
#define INSERT 1
#define DELETE 2
#define SWAP 3

int length(char *c) {
	int i = 0;
	while ( c[i] != '\0' ) ++i;
  return(i);
}
int max(int a, int b){ if(a < b) return b; return a;}
int indel(char c) { return(1); }
int match(char c, char b) {
	if( c == b) return(0);
	return(1);
}

int swap(char *c, char *t, int i, int j) {
	if(i < 2 || j < 2) return(2);
	if(c[i] == t[j-1] && c[i-1] == t[j]) return (1);

}

int string_compare(char *c, char *t, int i, int j) {
	int k; int opt[3]; 

  //printf("%i %i\n", i, j);
	if(i <= 0) return (j* indel(' '));
	if(j <= 0) return (i* indel(' '));
	opt[MATCH]  = string_compare(c, t, i-1, j-1) + match(c[i], t[j]);
	opt[INSERT] = string_compare(c, t, i, j-1) + indel(t[j]);
	opt[DELETE] = string_compare(c, t, i-1, j) + indel(c[i]);
	opt[SWAP]   = string_compare(c, t, i-2, j-2) + swap(c, t, i, j);
	
	int lowest_cost = opt[MATCH];
	for(k = INSERT; k <= SWAP; k++) {
		if(opt[k] < lowest_cost ) lowest_cost = opt[k];
	}
	return (lowest_cost);
}


int main(int argc, char *argv[]){

	char *c = argv[1];
	char *t = argv[2];
	
	int cost = string_compare(c, t, length(c)-1, length(t)-1); 
	printf("length of %s = %d \nlength of %s is %d\n", c, length(c), t, length(t));

	printf("Minimum cost of converting %s to %s is %d\n", c, t, cost);

}
