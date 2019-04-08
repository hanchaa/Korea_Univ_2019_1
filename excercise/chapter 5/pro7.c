#include <stdio.h>

int combination(int n, int r);

long long factorial(int a);

int main(void){
	int n, r;
	
	while(1){
		printf("Enter the inputs : ");
		scanf("%d %d", &n, &r);
		
		if((n >= 5 && n <= 20) && (r >= 5 && r <= 20) && n >= r)
			break;
		
		else
			printf("Input Error!\n\n");
	}
	
	printf("nCr : %d\n", combination(n, r));
	
	return 0;
}

int combination(int n, int r){
	return factorial(n) / (factorial(r) * factorial(n-r));
}

long long factorial(int a){
	if(a == 1)
		return 1;
	else
		return a * factorial(a - 1);
}