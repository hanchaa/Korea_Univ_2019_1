#include <stdio.h>

int ulcase(char a);

int main(void){
	char a;
	int tmp;
	
	printf("Enter the Character : ");
	
	scanf("%c", &a);
	
	tmp = ulcase(a);
	
	if(tmp == 0)
		printf("%c: Lowercase\n", a);
	
	else if(tmp == 1)
		printf("%c: Uppercase\n", a);
	
	else
		printf("INPUT IS NOT AN ALPHABET\n");

	return 0;
}

int ulcase(char a){
	if(a >= 97 && a <= 122)
		return 0;
	
	else if(a >= 65 && a <= 90)
		return 1;
	
	else
		return 2;
}