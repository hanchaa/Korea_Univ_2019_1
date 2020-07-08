#include <stdio.h>

int main(void){
	int i, num;
	
	printf("Decimal\t\tBinary\n");
	
	for(i = 0; i <= 15; i++){
		
		num = i;
		
		printf("%d\t\t%d", i, num / 8 ? 1 : 0);
		num %= 8;
		
		printf("%d", num / 4 ? 1 : 0);
		num %= 4;
		
		printf("%d", num / 2 ? 1 : 0);
		num %= 2;
		
		printf("%d\n", num / 1 ? 1 : 0);
	}
	
	return 0;
}