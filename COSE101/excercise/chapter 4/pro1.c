#include <stdio.h>

int main(void){
	int a, max, cnt = 1;
	
	printf("Enter the number: ");
	scanf("%d",&max);
	
	do{
		printf("Enter the number: ");
		scanf("%d",&a);
		
		if(a > max)
			max = a;
		
		cnt++;
	}while(cnt <= 4);

	printf("Largest is %d\n", max);
	
	return 0;
}