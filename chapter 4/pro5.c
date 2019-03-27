#include <stdio.h>

int main(void){
	int i = 0, j;
	double sum = 0;
	
	printf("Enter pairs of item numbers and quantities.\n");
	printf("Enter -1 for the item number to end input.\n");
	
	scanf("%d", &i);
	
	while(i != -1){
		scanf("%d", &j);
		
		switch(i){
			case 1 : 
				sum += 2.98 * j;
				break;
			
			case 2 :
				sum += 4.50 * j;
				break;
		
			case 3 :
				sum += 9.98 * j;
				break;
		
			case 4 :
				sum += 4.49 * j;
				break;

			case 5 :
				sum += 6.87 * j;
				break;
		
			default :
				printf("Invalid product cod: %d\n", i);
				printf("           Quantity: %d\n", j);
				break;
		}
		
		scanf("%d", &i);
	}
	
	printf("The total retail value was: %.2f\n", sum);
	
	return 0;
}