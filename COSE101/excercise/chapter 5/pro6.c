#include <stdio.h>

int gcd(int a, int b);

int main(void){
	int a, b;
	
	do{
		printf("Enter two positive integers: ");
		scanf("%d %d", &a, &b);
		
		if(a <= 0 || b <= 0)
			printf("Wrong Input, Try again!\n\n");
	}while(a <= 0 || b <= 0);
	
	printf("GCD of %d and %d is %d.\n", a, b, gcd(a, b));
	
	return 0;
}

int gcd(int a, int b){
	if(b != 0)
		return gcd(b, a % b);
	
	else
		return a;
	
}