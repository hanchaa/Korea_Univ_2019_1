#include <stdio.h>

int main(void){
	int tmp;
	
	printf("Input an integer : ");
	
	scanf("%d",&tmp);
	
	if(tmp % 2 == 0){
		printf("%d is an even integer\n",tmp);
	}
	if(tmp % 2 == 1){
		printf("%d is an odd integer\n",tmp);
	}
	
	return 0;
}