#include <stdio.h>

void f(char *string1, char *string2);

int main(void){
	char string1[80], string2[80];
	int tmp;
	
	printf("Enter two strings: ");
	scanf("%s %s", string1, string2);
	
	f(string1, string2);
	
	printf("%s\n", string1);
}

void f(char *string1, char *string2){
	int i = 0, j = 0;
	
	while(1){
		if(*(string1 + i) == '\0')
			break;
		
		i++;
	}
	
	while(*(string1 + i) = *(string2 + j)){
		i++;
		j++;
	}
	
}