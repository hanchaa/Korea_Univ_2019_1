#include <stdio.h>

void f(unsigned int a);

int main(void){
	
	unsigned int tmp;
	
	do{
		printf("Enter a number 1 and 999999999: ");
		scanf("%d", &tmp);
	}while(tmp > 999999999);
	
	printf("The number with its digits reversed is: ");
	
	f(tmp);
	
	printf("\n");
	
	return 0;
}

void f(unsigned int a){
	printf("%d", a % 10);
	
	if(a / 10 > 0)
		f(a / 10);
}