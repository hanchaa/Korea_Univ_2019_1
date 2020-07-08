#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{
	char name[80];
	int stdnum;
};

typedef struct student Student;

int main(void){
	
	Student data[5];
	char text[80];
	
	for(int i = 0; i < 5; i++){
		printf("<%d> Enter student name / student number: ", i + 1);
		fgets(text, 80, stdin);
		
		strcpy(data[i].name, strtok(text, "/"));
		data[i].stdnum = atoi(strtok(NULL, "/"));
	}
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 4 - i; j++){
			if(data[j].stdnum > data[j + 1].stdnum){
				Student tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
	
	printf("ID\t\tName\n");
	for(int i = 0; i < 5; i++)
		printf("%d\t%s\n", data[i].stdnum, data[i].name);
	
	return 0;
}
