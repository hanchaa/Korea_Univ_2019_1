#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void){
	char s[80];
	int cnt[26] = {0};
	
	printf("Enter three lines of text:\n");
	
	for(int i = 0; i < 3; i++){
		
		fgets(s, 80, stdin);
		
		for(int j = 0; s[j] != '\0'; j++)
			s[j] = tolower(s[j]);
		
		for(int j = 0; j < 26; j++){
			char *tmp = s;
			
			while(tmp = strchr(tmp, 'a' + j)){
				cnt[j]++;
				tmp++;
			}	
		}
		
	}
	
	printf("\nThe total occurrences of each character:\n");
	for(int i = 0; i < 26; i++){
		printf("%c: %2d\n", 'a' + i, cnt[i]);
	}
	return 0;
}