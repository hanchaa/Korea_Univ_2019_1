#include <stdio.h>

int main(void){
	int a, b, start, end, sum = 0;
	
	printf("Enter two integers : ");
	scanf("%d %d", &a, &b);
	
	if(a <= b){
		start = a;
		end = b;
	}
	
	else{
		start = b;
		end = a;
	}
	
	while(start <= end){
		sum += start;
		start++;
	}
	
	printf("The sum of all integers between %d and %d is %d\n",a ,b ,sum);

	return 0;
}