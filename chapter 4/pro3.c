#include <stdio.h>

int main(void){
	int i = -1, j = -1, k, res = 1;
	
	while(i < 0){
		printf("Enter the base number: ");
		scanf("%d", &i);
	}
	
	while(j < 0){
		printf("Enter the exponent number: ");
		scanf("%d", &j);
	}
	
	for(k = 1; k <= j; k++){
		res *= i;
	}
	
	printf("%d^%d is %d\n", i, j, res);
	return 0;
}