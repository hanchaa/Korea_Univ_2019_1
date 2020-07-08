#include <stdio.h>

int f(char *string1, char *string2);

int main(void){
	char string1[80], string2[80];
	int tmp;
	
	printf("Enter two strings: ");
	scanf("%s %s", string1, string2);
	
	tmp = f(string1, string2);
	
	if(tmp == 1)
		printf("%s and %s are equal.\n", string1, string2);
	else
		printf("%s and %s are not equal.\n", string1, string2);
}

int f(char *string1, char *string2){
	int i = 0;
	
	while(*(string1 + i) != '\0' || *(string2 + i) != '\0'){
		if(*(string1 + i) != *(string2 + i))
			return 0;
		
		i++;
	}
	
	return 1;
}