#include <stdio.h>
#include <stdlib.h>

int main(void){
	char s[6];
	int sum = 0;
	
	for(int i = 0; i < 4; i++){
		printf("Enter an integer string: ");
		scanf("%s", s);
		sum += atoi(s);
	}
	
	printf("\nThe total of the values is %d\n", sum);
	
	return 0;
}