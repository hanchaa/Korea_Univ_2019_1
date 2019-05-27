#include <stdio.h>
#include <stdlib.h>

typedef struct class_grade {
	char name[30];
	int student_id;
	int attendance;
	int midterm_exam;
	int final_exam;
	int assignment;
	int term_project;
	int total_score;
}Grade;

typedef struct class_report {
	int attendance;
	int midterm_exam;
	int final_exam;
	int assignment;
	int term_project;
	int total_score;
}Report;

void back_to_menu();
void view(const Grade * student, int cnt);
int input(Grade * student, Report * data, Report * avg, Report * mid, int cnt);
void rep(Report * avg, Report * mid, int cnt);
void grade(Grade * student, int cnt);

int main(void) {
	int menu, cnt = 0;
	Grade student[79];
	Report data[79], avg, mid;
	avg.attendance = avg.midterm_exam = avg.final_exam = avg.assignment = avg.term_project = avg.total_score = 0;

	while (1) {
		system("cls");
		printf("  COSE101 Grade Management System\n");
		printf("===================================\n");
		printf("1. View Registered Student\n");
		printf("2. Add Student\n");
		printf("3. Class Report\n");
		printf("4. View Final Grade\n");
		printf("5. Exit\n\n");
		printf("===================================\n");
		printf("Select Menu  : ");
		scanf_s("%d", &menu);

		if (menu < 1 || menu > 5) {
			while (menu < 1 || menu > 5) {
				printf("Please Enter 1 ~ 5\n");
				printf("Select Menu : ");
				scanf_s("%d", &menu);
			}
		}

		if (menu == 1)
			view(student, cnt);

		else if (menu == 2)
			cnt = input(student, data, &avg, &mid, cnt);

		else if (menu == 3)
			rep(&avg, &mid, cnt);

		else if (menu == 4)
			grade(student, cnt);

		else
			break;
	}
	return 0;
}

void back_to_menu() {
	int tmp = 0;
	while (tmp != 1) {
		printf("Enter 1 to Go Back : ");
		scanf_s("%d", &tmp);
		if (tmp != 1)
			printf("Wrong Input!\n");
	}
}

void view(const Grade * student, int cnt) {
	system("cls");

	printf("===================================\n");
	printf("         Registered Student\n");
	printf("===================================\n");

	if (cnt == 0)
		printf("There are no registered students\n");

	else {
		for (int i = 0; i < cnt; i++)
			printf("%d       %s\n", student[i].student_id, student[i].name);
	}

	printf("===================================\n");

	back_to_menu();
}

int input(Grade * student, Report * data, Report * avg, Report * mid, int cnt) {
	system("cls");

	printf("===================================\n");
	if (cnt < 79) {
		printf("Student Name : ");
		scanf_s("%s", student[cnt].name, 30);

		printf("Student ID : ");
		scanf_s("%d", &student[cnt].student_id);

		while (1) {
			printf("attendance (0 ~ 10) : ");
			scanf_s("%d", &student[cnt].attendance);
			if (student[cnt].attendance < 0 || student[cnt].attendance > 10)
				printf("Please input 0 ~ 10\n");
			else
				break;
		}

		data[cnt].attendance = student[cnt].attendance;
		avg->attendance += student[cnt].attendance;

		for (int i = cnt; i > 0; i--) {
			if (data[i].attendance < data[i - 1].attendance) {
				int tmp = data[i].attendance;
				data[i].attendance = data[i - 1].attendance;
				data[i - 1].attendance = tmp;
			}
		}

		if ((cnt + 1) % 2 == 0)
			mid->attendance = (data[cnt / 2].attendance + data[cnt / 2 + 1].attendance) / 2;
		else
			mid->attendance = data[cnt / 2].attendance;

		while(1) {
			printf("Assignment (0 ~ 10) : ");
			scanf_s("%d", &student[cnt].assignment);
			if (student[cnt].assignment < 0 || student[cnt].assignment > 10)
				printf("Please input 0 ~ 10\n");
			else
				break;
		}

		data[cnt].assignment = student[cnt].assignment;
		avg->assignment += student[cnt].assignment;

		for (int i = cnt; i > 0; i--) {
			if (data[i].assignment < data[i - 1].assignment) {
				int tmp = data[i].assignment;
				data[i].assignment = data[i - 1].assignment;
				data[i - 1].assignment = tmp;
			}
		}

		if ((cnt + 1) % 2 == 0)
			mid->assignment = (data[cnt / 2].assignment + data[cnt / 2 + 1].assignment) / 2;
		else
			mid->assignment = data[cnt / 2].assignment;

		while (1) {
			printf("Mideterm Exam (0 ~ 30) : ");
			scanf_s("%d", &student[cnt].midterm_exam);
			if (student[cnt].midterm_exam < 0 || student[cnt].midterm_exam > 30)
				printf("Pleas input 0 ~ 30\n");
			else
				break;
		}

		data[cnt].midterm_exam = student[cnt].midterm_exam;
		avg->midterm_exam += student[cnt].midterm_exam;

		for (int i = cnt; i > 0; i--) {
			if (data[i].midterm_exam < data[i - 1].midterm_exam) {
				int tmp = data[i].midterm_exam;
				data[i].midterm_exam = data[i - 1].midterm_exam;
				data[i - 1].midterm_exam = tmp;
			}
		}

		if ((cnt + 1) % 2 == 0)
			mid->midterm_exam = (data[cnt / 2].midterm_exam + data[cnt / 2 + 1].midterm_exam) / 2;
		else
			mid->midterm_exam = data[cnt / 2].midterm_exam;

		while (1) {
			printf("Final Exam (0 ~ 30) : ");
			scanf_s("%d", &student[cnt].final_exam);
			if (student[cnt].final_exam < 0 || student[cnt].final_exam > 30)
				printf("Please input 0 ~ 30\n");
			else
				break;
		}

		data[cnt].final_exam = student[cnt].final_exam;
		avg->final_exam += student[cnt].final_exam;

		for (int i = cnt; i > 0; i--) {
			if (data[i].final_exam < data[i - 1].final_exam) {
				int tmp = data[i].final_exam;
				data[i].final_exam = data[i - 1].final_exam;
				data[i - 1].final_exam = tmp;
			}
		}

		if ((cnt + 1) % 2 == 0)
			mid->final_exam = (data[cnt / 2].final_exam + data[cnt / 2 + 1].final_exam) / 2;
		else
			mid->final_exam = data[cnt / 2].final_exam;

		while (1) {
			printf("Term Project (0 ~ 20) : ");
			scanf_s("%d", &student[cnt].term_project);
			if (student[cnt].term_project < 0 || student[cnt].term_project > 20)
				printf("Please input 0 ~ 20\n");
			else
				break;
		}

		data[cnt].term_project = student[cnt].term_project;
		avg->term_project += student[cnt].term_project;

		for (int i = cnt; i > 0; i--) {
			if (data[i].term_project < data[i - 1].term_project) {
				int tmp = data[i].term_project;
				data[i].term_project = data[i - 1].term_project;
				data[i - 1].term_project = tmp;
			}
		}

		if ((cnt + 1) % 2 == 0)
			mid->term_project = (data[cnt / 2].term_project + data[cnt / 2 + 1].term_project) / 2;
		else
			mid->term_project = data[cnt / 2].term_project;

		data[cnt].total_score = student[cnt].total_score = student[cnt].attendance + student[cnt].assignment + student[cnt].midterm_exam + student[cnt].final_exam + student[cnt].term_project;
		avg->total_score += student[cnt].total_score;

		for (int i = cnt; i > 0; i--) {
			if (data[i].total_score < data[i - 1].total_score) {
				int tmp = data[i].total_score;
				data[i].total_score = data[i - 1].total_score;
				data[i - 1].total_score = tmp;
			}
		}

		if ((cnt + 1) % 2 == 0)
			mid->total_score = (data[cnt / 2].total_score + data[cnt / 2 + 1].total_score) / 2;
		else
			mid->total_score = data[cnt / 2].total_score;

		cnt++;
	}

	else
		printf("Max Student!\n");

	back_to_menu();

	return cnt;
}

void rep(Report * avg, Report * mid, int cnt) {

	system("cls");
	printf("             Class report\n");
	printf("===================================\n");
	if (cnt == 0)
		printf("There are no registered students\n");
	else {
		printf(" Field        Average  | Median\n");
		printf("===================================\n");
		printf("Attendance  :    %2d    |     %2d\n", avg->attendance / cnt, mid->attendance);
		printf("Assignment  :    %2d    |     %2d\n", avg->assignment / cnt, mid->assignment);
		printf("Mideterm    :    %2d    |     %2d\n", avg->midterm_exam / cnt, mid->midterm_exam);
		printf("Final       :    %2d    |     %2d\n", avg->final_exam / cnt, mid->final_exam);
		printf("Term Proejct:    %2d    |     %2d\n", avg->term_project / cnt, mid->term_project);
		printf("Total       :    %2d    |     %2d\n\n", avg->total_score / cnt, mid->total_score);
	}
	printf("===================================\n");

	back_to_menu();
}

void grade(Grade * student, int cnt) {
	system("cls");
	printf("==========================================\n");
	printf("             Final Grade\n");
	printf("==========================================\n");
	if (cnt == 0)
		printf("There are no registered students\n");
	else {
		printf("StudentID       Total Score     Grade\n");
		for (int i = 0; i < cnt; i++) {
			char res;
			if (student[i].total_score >= 90)
				res = 'A';
			else if (student[i].total_score >= 80)
				res = 'B';
			else if (student[i].total_score >= 70)
				res = 'C';
			else
				res = 'D';
			printf("%d      %-3d             %c\n", student[i].student_id, student[i].total_score, res);
		}
	}
	printf("==========================================\n");
	back_to_menu();
}