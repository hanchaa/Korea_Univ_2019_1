#include <stdio.h>
#include <string.h>

int main(void){
	char s[80];
	int cnt[80] = {0};
	
	printf("Enter three lines of text:\n");
	
	for(int i = 0; i < 3; i++){
		fgets(s, 80, stdin);
		
		char *token = strtok(s, ". \n");
		
		while(token != NULL){
			cnt[strlen(token)]++;
			
			token = strtok(NULL, ". \n");
		}
	}
	
	printf("\n");
	
	for(int i = 1; i < 80; i++){
		if(cnt[i] > 1)
			printf("%d words of length %d\n", cnt[i], i);
		
		else if(cnt[i] == 1)
			printf("%d word of length %d\n", cnt[i], i);
	}
	return 0;
}