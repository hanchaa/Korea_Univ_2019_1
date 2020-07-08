#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 100

void display_plan(int plan[2][7]);
void two_month(int current, int usage[3][3]);
void input(int usage[3][3]);
void three_month(int current, int usage[3][3], int plan[2][7]);
void recommend(int current, int usage[3][3], int plan[2][7]);
void back_to_menu();
int remove_buffer();

int main(void) {

	int current, chk = 0;
	int usage[3][3] = { 0 };
	int plan[2][7] = { {500, 100, 200, 50, 10, 100, 20000}, {300, 100, 3000, 10, 30, 50, 45000} };
	char menu;

	srand(time(NULL));

	current = rand() % 2;

	usage[0][0] = rand() % 700 + 1;
	usage[1][0] = rand() % 700 + 1;

	usage[0][1] = rand() % 301;
	usage[1][1] = rand() % 301;

	usage[0][2] = rand() % 14951 + 50;
	usage[1][2] = rand() % 14951 + 50;


	while (1) {
		system("cls");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 \n");
		printf("弛      KU Mobile Phone Bill Calculator         弛 \n");
		printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
		printf("弛    1 : Display plans                         弛 \n");
		printf("弛    2 : Usage information for past two months 弛 \n");
		printf("弛    3 : Input this month usage                弛 \n");
		printf("弛    4 : Total fee for past 3 months           弛 \n");
		printf("弛    5 : Best plan recommendation              弛 \n");
		printf("弛    6 : Exit                                  弛 \n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n");

		while (1) {
			while ((menu = getchar()) == '\n') {}
			int tmp = remove_buffer();

			if (tmp == 0 && (menu >= '1' && menu <= '6'))
				break;
			else
				printf("Pleas Input 1 to 6!\n");
		}

		switch (menu) {
		case '1':
			display_plan(plan);
			break;

		case '2':
			two_month(current, usage);
			break;

		case '3':
			input(usage);
			break;

		case '4':
			three_month(current, usage, plan);
			break;

		case '5':
			recommend(current, usage, plan);
			break;

		case '6':
			return 0;
		}
	}
	return 0;
}

void display_plan(int plan[2][7]) {

	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 \n");
	printf("弛                Basic Plan                 弛 \n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛  Included in Plan  弛   Additional usages  弛 \n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛 Voice     弛  %dm free   弛  \\ %d / 1m     弛 \n", plan[0][0], plan[0][3]);
	printf("弛 Text      弛  %dt free   弛  \\ %d / 1t     弛 \n", plan[0][1], plan[0][4]);
	printf("弛 Data      弛  %.2fGB free 弛  \\ %d / 0.1GB弛 \n", (float)plan[0][2] / M, plan[0][5] * 10);
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛 Basic fee 弛  \\ %d                      弛 \n", plan[0][6]);
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n\n");

	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 \n");
	printf("弛             More Data Plan                弛 \n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛  Included in Plan  弛   Additional usages  弛 \n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛 Voice     弛  %dm free   弛  \\ %d / 1m     弛 \n", plan[1][0], plan[1][3]);
	printf("弛 Text      弛  %dt free   弛  \\ %d / 1t     弛 \n", plan[1][1], plan[1][4]);
	printf("弛 Data      弛  %.2fGB free弛  \\ %d / 0.1GB 弛 \n", (float)plan[1][2] / M, plan[1][5] * 10);
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛 Basic fee 弛 \\ %d                       弛 \n", plan[1][6]);
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n");

	back_to_menu();
}

void two_month(int current, int usage[3][3]) {

	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 \n");
	printf("弛           Last two months usage           弛 \n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛  My Plan : %-14s                 弛 \n", current == 0 ? "Basic Plan" : "More Data Plan");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛           弛   Feburary   弛     March      弛 \n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛  Voice    弛  %6d min  弛  %6d min    弛 \n", usage[0][0], usage[1][0]);
	printf("弛  Text     弛  %6d text 弛  %6d text   弛 \n", usage[0][1], usage[1][1]);
	printf("弛  Data     弛  %6.2f GB   弛  %6.2f GB     弛 \n", (float)usage[0][2] / M, (float)usage[1][2] / 100);
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n");

	back_to_menu();
}

void input(int usage[3][3]) {

	float tmp;

	system("cls");

	printf("=================================\n");

	while (1) {
		printf("Input your usages of voice : ");
		scanf("%d", &usage[2][0]);

		if (usage[2][0] >= 0)
			break;

		printf("Wrong Input!\n");
	}

	while (1) {
		printf("Input your usages of text : ");
		scanf("%d", &usage[2][1]);

		if (usage[2][1] >= 0)
			break;

		printf("Wrong Input!\n");
	}

	while (1) {
		printf("Input your usages of data : ");
		scanf("%f", &tmp);

		if (tmp >= 0)
			break;

		printf("Wrong Input!\n");
	}

	usage[2][2] = (int)((tmp + 0.005) * M);

	back_to_menu();
}

void three_month(int current, int usage[3][3], int plan[2][7]) {
	int extra[5] = { 0 }, sum[5] = { 0 };

	for (int i = 0; i < 3; i++) {
		if (usage[i][2] < plan[current][2]) {
			extra[i + 1] = plan[current][2] - usage[i][2];

			if (extra[i + 1] > plan[current][2] / 10)
				extra[i + 1] = plan[current][2] / 10;
		}

		sum[i] = plan[current][6];
		for (int j = 0; j < 2; j++) {
			if (usage[i][j] > plan[current][j])
				sum[i] += (usage[i][j] - plan[current][j]) * plan[current][j + 3];
		}
		if (usage[i][2] > plan[current][2] + extra[i])
			sum[i] += (usage[i][2] - plan[current][2] - extra[i]) * plan[current][5];
	}

	system("cls");

	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 \n");
	printf("弛                     My three months usage                  弛 \n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛 My Plan : %-14s                                   弛 \n", current == 0 ? "Basic Plan" : "More Data Plan");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛           弛   Feburary   弛     March      弛     April      弛 \n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛 Voice     弛  %6d min  弛  %6d min    弛  %6d min    弛 \n", usage[0][0], usage[1][0], usage[2][0]);
	printf("弛 Text      弛  %6d text 弛  %6d text   弛  %6d text   弛 \n", usage[0][1], usage[1][1], usage[2][1]);
	printf("弛 Data      弛  %6.2f GB   弛  %6.2f GB     弛  %6.2f GB     弛 \n", (float)usage[0][2] / M, (float)usage[1][2] / M, (float)usage[2][2] / M);
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛 Extra Data弛  %6.2f GB   弛  %6.2f GB     弛  %6.2f GB     弛 \n", (float)extra[1] / M, (float)extra[2] / M, (float)extra[3] / M);
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛 Total Fee 弛  \\ %7d   弛  \\ %7d     弛  \\ %7d     弛 \n", sum[0], sum[1], sum[2]);
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n");

	back_to_menu();
}

void recommend(int current, int usage[3][3], int plan[2][7]) {
	int sum1 = plan[0][6], sum2 = plan[1][6];

	int avg[3] = { 0 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			avg[i] += usage[j][i];
		}
		avg[i] = (int)((float)avg[i] / 3 + 0.5);
	}

	for (int i = 0; i < 3; i++) {
		if (avg[i] > plan[0][i])
			sum1 += (avg[i] - plan[0][i]) * plan[0][i + 3];
		if (avg[i] > plan[1][i])
			sum2 += (avg[i] - plan[1][i]) * plan[1][i + 3];
	}

	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 \n");
	printf("弛         Average usage of 3-month          弛 \n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛  My Plan : %-14s                 弛 \n", current == 0 ? "Basic Plan" : "More Data Plan");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛  Average usage of voice : %5d           弛 \n", avg[0]);
	printf("弛  Average usage of text : %6d           弛 \n", avg[1]);
	printf("弛  Average usage of data : %6.2f           弛 \n", (float)avg[2] / M);
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛  Basic Plan Fee :      \\%7d           弛 \n", sum1);
	printf("弛  More Data Plan Fee  : \\%7d           弛 \n", sum2);
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
	printf("弛  We recommend to use %-14s       弛 \n", sum1 < sum2 ? "Basic Plan" : "More Data Plan");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n");

	back_to_menu();
}

void back_to_menu() {

	char a;

	while (1) {
		printf("  Back to main menu Y/N : ");
		while ((a = getchar()) == '\n') {}
		int tmp = remove_buffer();

		if (a == 'Y' && tmp == 0)
			break;

		else if (tmp == 1)
			printf("  Please Input Y/N!\n");

		else if (a != 'N')
			printf("  Please Input Y/N!\n");
	}
}

int remove_buffer() {
	int tmp = 0;

	while (getchar() != '\n') {
		tmp = 1;
	}

	return tmp;
}