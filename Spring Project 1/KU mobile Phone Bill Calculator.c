#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void display_plan(float plan[2][7]);
void two_month(int current, float usage[3][3]);
void input(float usage[3][3]);
void three_month(int current, float usage[3][3], float plan[2][7]);
void recommend(int current, float usage[3][3], float plan[2][7]);

int main(void) {

	int menu, current, chk = 0;

	float usage[3][3] = { 0 };
	float plan[2][7] = { {500, 100, 2, 50, 10, 1000, 20000}, {300, 100, 30, 10, 30, 500, 45000} };

	srand(time(NULL));

	/*
	current = 0;

	usage[0][0] = 258; usage[1][0] = 310;
	usage[0][1] = 85; usage[1][1] = 195;
	usage[0][2] = 21.89; usage[1][2] = 1.55;
	*/
	current = rand() % 2;

	usage[0][0] = rand() % 700 + 1;
	usage[1][0] = rand() % 700 + 1;

	usage[0][1] = rand() % 300;
	usage[1][1] = rand() % 300;

	usage[0][2] = (float)(rand() % 14501 + 500) / 100;
	usage[1][2] = (float)(rand() % 14501 + 500) / 100;


	while (1) {
		system("cls");
		printf("┌──────────────────────────────────────────────┐\n");
		printf("│      KU Mobile Phone Bill Calculator         │\n");
		printf("├──────────────────────────────────────────────┤\n");
		printf("│    1 : Display plans                         │\n");
		printf("│    2 : Usage information for past two months │\n");
		printf("│    3 : Input this month usage                │\n");
		printf("│    4 : Total fee for past 3 months           │\n");
		printf("│    5 : Best plan recommendation              │\n");
		printf("│    6 : Exit                                  │\n");
		printf("└──────────────────────────────────────────────┘\n");

		while (1) {
			printf("  Enter menu : ");
			scanf("%d", &menu);

			if (menu >= 1 && menu <= 6)
				break;
			printf("  Wrong Input!\n");
		}

		switch (menu) {
		case 1:
			display_plan(plan);
			break;

		case 2:
			two_month(current, usage);
			break;

		case 3:
			input(usage);
			break;

		case 4:
			three_month(current, usage, plan);
			break;

		case 5:
			recommend(current, usage, plan);
			break;

		case 6:
			return 0;
		}
	}
	return 0;
}

void display_plan(float plan[2][7]) {
	char a;

	while (1) {
		system("cls");
		printf("┌───────────────────────────────────────────┐\n");
		printf("│                Basic Plan                 │\n");
		printf("├───────────────────────────────────────────┤\n");
		printf("│  Included in Plan  │   Additional usages  │\n");
		printf("├───────────────────────────────────────────┤\n");
		printf("│ Voice     │  %.0fm free   │  \\ %.0f / 1m     │\n", plan[0][0], plan[0][3]);
		printf("│ Text      │  %.0ft free   │  \\ %.0f / 1m     │\n", plan[0][1], plan[0][4]);
		printf("│ Data      │  %.2fGB free │  \\ %.0f / 0.1GB│\n", plan[0][2], plan[0][5]);
		printf("├───────────────────────────────────────────┤\n");
		printf("│ Basic fee │  \\ %.0f                      │\n", plan[0][6]);
		printf("└───────────────────────────────────────────┘\n\n");

		printf("┌───────────────────────────────────────────┐\n");
		printf("│             More Data Plan                │\n");
		printf("├───────────────────────────────────────────┤\n");
		printf("│  Included in Plan  │   Additional usages  │\n");
		printf("├───────────────────────────────────────────┤\n");
		printf("│ Voice     │  %.0fm free   │  \\ %.0f / 1m     │\n", plan[1][0], plan[1][3]);
		printf("│ Text      │  %.0ft fre    │  \\ %.0f / 1m     │\n", plan[1][1], plan[1][4]);
		printf("│ Data      │  %.2fGB free│  \\ %.0f / 0.1GB │\n", plan[1][2], plan[1][5]);
		printf("├───────────────────────────────────────────┤\n");
		printf("│ Basic fee │ \\ %.0f                       │\n", plan[1][6]);
		printf("└───────────────────────────────────────────┘\n");

		while (1) {
			printf("  Back to main menu Y/N : ");
			scanf("\n%c", &a);

			if (a == 'N' || a == 'Y')
				break;

			printf("  Wrong Input!\n");
		}
		if (a == 'Y')
			break;
	}
}

void two_month(int current, float usage[3][3]) {
	char a;
	while (1) {
		system("cls");
		printf("┌───────────────────────────────────────────┐\n");
		printf("│           Last two months usage           │\n");
		printf("├───────────────────────────────────────────┤\n");
		printf("│  My Plan : %-14s                 │\n", current == 0 ? "Basic Plan" : "More Data Plan");
		printf("├───────────────────────────────────────────┤\n");
		printf("│           │   Feburary   │     March      │\n");
		printf("├───────────────────────────────────────────┤\n");
		printf("│  Voice    │  %6.0f min  │  %6.0f min    │\n", usage[0][0], usage[1][0]);
		printf("│  Text     │  %6.0f text │  %6.0f text   │\n", usage[0][1], usage[1][1]);
		printf("│  Data     │  %6.2f GB   │  %6.2f GB     │\n", usage[0][2], usage[1][2]);
		printf("└───────────────────────────────────────────┘\n");

		while (1) {
			printf("  Back to main menu Y/N : ");
			scanf("\n%c", &a);

			if (a == 'N' || a == 'Y')
				break;

			printf("  Wrong Input!\n");
		}
		if (a == 'Y')
			break;
	}
}

void input(float usage[3][3]) {

	system("cls");

	printf("=================================\n");
	printf("Input your usages of voice : ");
	scanf("%f", &usage[2][0]);

	printf("Input your usages of text : ");
	scanf("%f", &usage[2][1]);

	printf("Input your usages of data : ");
	scanf("%f", &usage[2][2]);
}

void three_month(int current, float usage[3][3], float plan[2][7]) {
	float extra[5] = { 0 }, sum[5] = { 0 };
	char a;

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
		if (floor(usage[i][2] * 10) > (plan[current][2] + extra[i]) * 10)
			sum[i] += (floor(usage[i][2] * 10) - (plan[current][2] + extra[i]) * 10) * plan[current][5];
	}

	while (1) {
		system("cls");

		printf("┌────────────────────────────────────────────────────────────┐\n");
		printf("│                     My three months usage                  │\n");
		printf("├────────────────────────────────────────────────────────────┤\n");
		printf("│ My Plan : %-14s                                   │\n", current == 0 ? "Basic Plan" : "More Data Plan");
		printf("├────────────────────────────────────────────────────────────┤\n");
		printf("│           │   Feburary   │     March      │     April      │\n");
		printf("├────────────────────────────────────────────────────────────┤\n");
		printf("│ Voice     │  %6.0f min  │  %6.0f min    │  %6.0f min    │\n", usage[0][0], usage[1][0], usage[2][0]);
		printf("│ Text      │  %6.0f text │  %6.0f text   │  %6.0f text   │\n", usage[0][1], usage[1][1], usage[2][1]);
		printf("│ Data      │  %6.2f GB   │  %6.2f GB     │  %6.2f GB     │\n", usage[0][2], usage[1][2], usage[2][2]);
		printf("├────────────────────────────────────────────────────────────┤\n");
		printf("│ Extra Data│  %6.2f GB   │  %6.2f GB     │  %6.2f GB     │\n", extra[1], extra[2], extra[3]);
		printf("├────────────────────────────────────────────────────────────┤\n");
		printf("│ Total Fee │  \\ %7.0f   │  \\ %7.0f     │  \\ %7.0f     │\n", sum[0], sum[1], sum[2]);
		printf("└────────────────────────────────────────────────────────────┘\n");

		while (1) {
			printf("  Back to main menu Y/N : ");
			scanf("\n%c", &a);

			if (a == 'N' || a == 'Y')
				break;

			printf("  Wrong Input!\n");
		}
		if (a == 'Y')
			break;
	}
}

void recommend(int current, float usage[3][3], float plan[2][7]) {
	char a;
	int sum1 = plan[0][6], sum2 = plan[1][6];

	float avg[3] = { 0 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			avg[i] += usage[j][i];
		}

		if (i == 2)
			avg[i] /= 3;
		else
			avg[i] = (int)(avg[i] / 3);
	}

	for (int i = 0; i < 3; i++) {
		if (i == 2) {
			if (avg[i] > plan[0][2])
				sum1 += (floor(avg[i] * 10) - plan[0][2] * 10) * plan[0][5];
			if (avg[i] > plan[1][2])
				sum2 += (floor(avg[i] * 10) - plan[1][2] * 10) * plan[1][5];
		}
		else {
			if (avg[i] > plan[0][i])
				sum1 += (avg[i] - plan[0][i]) * plan[0][i + 3];
			if (avg[i] > plan[1][i])
				sum2 += (avg[i] - plan[1][i]) * plan[1][i + 3];
		}
	}
	while (1) {
		system("cls");
		printf("┌───────────────────────────────────────────┐\n");
		printf("│         Average usage of 3-month          │\n");
		printf("├───────────────────────────────────────────┤\n");
		printf("│  My Plan : %-14s                 │\n", current == 0 ? "Basic Plan" : "More Data Plan");
		printf("├───────────────────────────────────────────┤\n");
		printf("│  Average usage of voice : %5.0f           │\n", avg[0]);
		printf("│  Average usage of text : %6.0f           │\n", avg[1]);
		printf("│  Average usage of data : %6.2f           │\n", avg[2]);
		printf("├───────────────────────────────────────────┤\n");
		printf("│  Basic Plan Fee :      \\%7d           │\n", sum1);
		printf("│  More Data Plan Fee  : \\%7d           │\n", sum1);
		printf("├───────────────────────────────────────────┤\n");
		printf("│  We recommend to use %-14s       │\n", sum1 < sum2 ? "Basic Plan" : "More Data Plan");
		printf("└───────────────────────────────────────────┘\n");

		while (1) {
			printf("  Back to main menu Y/N : ");
			scanf("\n%c", &a);

			if (a == 'N' || a == 'Y')
				break;

			printf("  Wrong Input!\n");
		}
		if (a == 'Y')
			break;
	}
}