#include <stdio.h>

int main(void){
	int num, sum = 0;
	
	printf("Input : ");
	scanf("%d",&num);
	
	printf("Output :\n");
	
	printf("%d\t",num % 10);
	if((num % 10) % 2 == 1) sum = sum + (num % 10);
	num = num / 10;
	
	printf("%d\t",num % 10);
	if((num % 10) % 2 == 1) sum = sum + (num % 10);
	num = num / 10;
	
	printf("%d\t",num % 10);
	if((num % 10) % 2 == 1) sum = sum + (num % 10);
	num = num / 10;
	
	printf("%d\t",num % 10);
	if((num % 10) % 2 == 1) sum = sum + (num % 10);
	num = num / 10;
	
	printf("%d\n",num);
	if(num % 2 == 1) sum = sum + num;
	
	printf("%d",sum);
	
	return 0;
}