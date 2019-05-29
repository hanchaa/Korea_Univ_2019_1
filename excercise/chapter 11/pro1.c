#include <stdio.h>

int main(void){
	
	FILE *fr, *fw;
	char name[80], tmp[80];
	
	printf("Enter the name of file to read: ");
	scanf("%s", name);
	
	fr = fopen(name, "r");
	
	if(fr == NULL){
		printf("FILE %s read error! \n", name);
	}
	
	printf("Enter the name of file to write: ");
	scanf("%s", name);
	
	fw = fopen(name, "w");
	
	while(fgets(tmp, 80, fr) != NULL){
		if(tmp[0] != '\n')
			fprintf(fw, "%s", tmp);
	}
	
	fclose(fr);
	fclose(fw);
	
	printf("Copy txt complete!\n");
	
	return 0;
}