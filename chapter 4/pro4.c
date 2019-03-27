#include <stdio.h>

int main(void){
	int i, j;
	for(i = 1; i <= 5; i++){
		
		for(j = 5 - i; j >= 1; j--)
			printf(" ");
		
		for(j = 1; j <= i * 2 -1; j++)
			printf("*");
		
		printf("\n");
	}
	
	for(i = 4; i >= 1; i--){
		
		for(j = 5 - i; j >= 1; j--)
			printf(" ");
		
		for(j = 1; j <= i * 2 - 1; j++)
			printf("*");
		
		printf("\n");
	}
	
	return 0;
}