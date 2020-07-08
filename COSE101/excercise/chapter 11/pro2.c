#include <stdio.h>
#include <stdlib.h>

struct ku{
	char name[30], major[30];
	int id, grade;
} student;

int main(void){
	int stid;
	
	FILE *fr = fopen("student_file.txt", "w");
	
	for(int i = 0; i < 5; i++){
		printf("Name Student_number Grade Major: ");
		scanf("%s%d%d%s", student.name, &student.id, &student.grade, student.major);
		fprintf(fr, "%s %d %d %s\n", student.name, student.id, student.grade, student.major);
	}
	
	fclose(fr);
		
	FILE *fp = fopen("student_file.txt", "r");
	if(fp == NULL){
		printf("Something wrong \n");
		exit(1);
	}
	
	printf("Insert the student number to find: ");
	scanf("%d", &stid);
	
	while(!feof(fp)){
		fscanf(fp, "%s%d%d%s", student.name, &student.id, &student.grade, student.major);
		
		if(student.id == stid){
			printf("The major of student with ID %d is %s\n", stid, student.major);
			break;
		}
	}
	
	fclose(fp);
	return 0;
}