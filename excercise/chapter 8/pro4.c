#include <stdio.h>
#include <string.h>

int main(void){
	char s[10][50];
	
	for(int i = 0; i < 10; i++){
		printf("Enter a string: ");
		scanf("%s", s[i]);
	}
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 9 - i; j++){
			if(strcmp(s[j], s[j + 1]) > 0){
				char tmp[50];
				strcpy(tmp, s[j]);
				strcpy(s[j], s[j + 1]);
				strcpy(s[j + 1], tmp);
			}
		}
	}
	
	printf("\nThe strings in sorted order are:\n");
	for(int i = 0; i < 10; i++)
		printf("%s\n", s[i]);
	
	return 0;
}