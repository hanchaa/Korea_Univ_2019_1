#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	FILE *fp;
	char name[100], str[100], par[10000];
	char * tok;
	int cnt = 0, wcnt = 0;
	
	printf("Enter the file name and word : ");
	scanf("%s%s", name, str);
	
	fp = fopen(name, "r");
	
	if(fp == NULL){
		printf("Can't open file\n");
		exit(1);
	}
	
	while(!feof(fp)){
		fgets(par, sizeof(par), fp);
		
		tok = strtok(par, " ,().&-\n\"");
		
		while(tok != NULL){
			cnt++;
			
			if(strcmp(tok, str) == 0)
				wcnt++;
			
			tok = strtok(NULL, " ,().&-\n\"");
		}
	}
	
	printf("The finding ratio : %d/%d\n", wcnt, cnt);
	
	fclose(fp);
	return 0;
}
