#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define len 100

struct employee {
	int employee_id;
	char* name;
};

void add(FILE *fp);
void disp(FILE *fp);
void upd(FILE *fp);

int main(void) {
	FILE *fp = fopen("employee.txt", "rb+");
	int menu;

	while (1) {
		printf("============================\n");
		printf("MENU:\n");
		printf("============================\n");
		printf("1. Add a record\n");
		printf("2. Display the file\n");
		printf("3. Update the record\n");
		printf("4. Exit\n");
		printf("============================\n");

		while (1) {
			printf("Enter your choice: ");
			scanf("%d", &menu);

			if (menu >= 1 && menu <= 4)
				break;

			printf("Please input 1 ~ 4\n");
		}

		if (menu == 1)
			add(fp);

		else if (menu == 2)
			disp(fp);

		else if (menu == 3)
			upd(fp);

		else
			break;
	}
	fclose(fp);
	return 0;
}

void add(FILE *fp) {
	struct employee data = { 0, "" };
	int id;
	char name[len] = "";

	printf("\nENTER THE EMPLOYEE ID :\n");
	scanf("%d", &id);
	getchar();

	fseek(fp, (id - 1) * (sizeof(data.employee_id) + sizeof(name)), SEEK_SET);
	fread(&data.employee_id, sizeof(data.employee_id), 1, fp);

	if (data.employee_id != 0)
		printf("Employee id %d already exist\n\n", id);

	else {
		data.employee_id = id;

		printf("ENTER THE EMPLOYEE NAME :\n");
		fgets(name, len, stdin);

		data.name = name;

		fseek(fp, (data.employee_id - 1) * (sizeof(data.employee_id) + sizeof(name)), SEEK_SET);
		fwrite(&data.employee_id, sizeof(data.employee_id), 1, fp);
		fwrite(data.name, sizeof(name), 1, fp);
		printf("\n");
	}
}

void disp(FILE *fp) {
	rewind(fp);

	printf("\n============================\n");
	printf("ID\tNAME\n");
	printf("============================\n");
	while (!feof(fp)) {
		struct employee data = { 0, "" };
		char name[len] = "";

		fread(&data.employee_id, sizeof(data.employee_id), 1, fp);
		fread(name, sizeof(name), 1, fp);
		data.name = name;

		if (data.employee_id != 0)
			printf("%d\t%s", data.employee_id, data.name);
	}
	printf("============================\n");
	printf("Press any button to go back to main menu\n\n");

	while (_getch() == 0) {
	}
}

void upd(FILE *fp) {
	int id;
	struct employee data = { 0, "" };

	char name[len] = "";

	printf("\nENTER THE EMPLOYEE ID FOR UPDATE :\n");
	scanf("%d", &id);
	getchar();
	
	fseek(fp, (id - 1) * (sizeof(data.employee_id) + sizeof(name)), SEEK_SET);
	fread(&data.employee_id, sizeof(data.employee_id), 1, fp);

	if (data.employee_id == 0)
		printf("Employee id %d does not exist\n\n", id);
	else {
		data.employee_id = id;

		printf("ENTER THE EMPLOYEE NAME TO BE UPDATED :\n");
		fgets(name, len, stdin);
		data.name = name;

		fseek(fp, (id - 1) * (sizeof(data.employee_id) + sizeof(name)) + sizeof(data.employee_id), SEEK_SET);
		fwrite(data.name, sizeof(name), 1, fp);

		printf("\n");
	}
}