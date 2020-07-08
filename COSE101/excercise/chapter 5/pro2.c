#include <stdio.h>

void perfect(int a);

int main(void){
	int i;
	
	printf("For the integers from 1 to 1000:\n");
	
	for(i = 2; i <= 1000; i++)
		perfect(i);
	
	return 0;
}

void perfect(int a){
	int sum = 0, i;
	
	for(i = 1; i <= a / 2; i++){
		if(a % i ==0)
			sum += i;
	}
	
	if(sum == a)
		printf("%d is perfect\n", a);
}