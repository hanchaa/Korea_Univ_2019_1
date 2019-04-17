#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void plan();
void two_month(int plan, float feb[], float mar[]);
void input(float apr[]);
void total();
void recommend();

int main(void) {
	
	int menu, current;
	float tmp;
	
	float feb[5] = { 0 }, mar[5] = { 0 }, apr[5] = { 0 };
	
	srand(time(NULL));
	
	current = rand() % 2;
	
	feb[0] = rand() % 700 + 1;
	mar[0] = rand() % 700 + 1;
	
	feb[1] = rand() % 300;
	mar[1] = rand() % 300;
	
	feb[2] = (float)(rand() % 14501 + 500) / 100;
	mar[2] = (float)(rand() % 14501 + 500) / 100;
	
	while(1){
		system("cls");
		printf("┌──────────────────────────────────────────────┐\n");
		printf("│     KU Mobile Phone Bill Calculator          │\n");
		printf("├──────────────────────────────────────────────┤\n");
		printf("│   1 : Display plans                          │\n");
		printf("│   2 : Usage information for past two months  │\n");
		printf("│   3 : Input this month usage                 │\n");
		printf("│   4 : Total fee for past 3 months            │\n");
		printf("│   5 : Best plan recommendation               │\n");
		printf("│   6 : Exit                                   │\n");
		printf("└──────────────────────────────────────────────┘\n");
		printf("Enter menu : ");
		
		scanf("%d", &menu);
		
		if(menu == 6) break;
		
		switch(menu){
			case 1 :
				plan();
				break;
			
			case 2 :
				two_month(current, feb, mar);
				break;
			
			case 3 :
				input(apr);
				break;
			
			case 4 :
				break;
			
			case 5 :
				break;

		}
	}
	return 0;
}

void plan(){
	char a;
	
	while(1){
		system("cls");
		printf("┌──────────────────────────────────────────────┐\n");
		printf("│                 Basic Plan                   │\n");
		printf("├──────────────────────────────────────────────┤\n");
		printf("│   Included in Plan  │   Additional usages    │\n");
		printf("├──────────────────────────────────────────────┤\n");
		printf("│Voice       │ 500m free    │ \\ 50 / 1m        │\n");
		printf("│Text        │ 100t free    │ \\ 10 / 1m        │\n");
		printf("│Data        │ 2.00GB free  │ \\ 1000 / 0.1GB   │\n");
		printf("├──────────────────────────────────────────────┤\n");
		printf("│Basic fee   │ \\ 20000                         │\n");
		printf("└──────────────────────────────────────────────┘\n\n");
		
		printf("┌──────────────────────────────────────────────┐\n");
		printf("│             More Data Plan                   │\n");
		printf("├──────────────────────────────────────────────┤\n");
		printf("│   Included in Plan  │   Additional usages    │\n");
		printf("├──────────────────────────────────────────────┤\n");
		printf("│Voice       │ 300m free    │ \\ 10 / 1m        │\n");
		printf("│Text        │ 100t free    │ \\ 30 / 1m        │\n");
		printf("│Data        │ 30.00GB free │ \\ 500 / 0.1GB    │\n");
		printf("├──────────────────────────────────────────────┤\n");
		printf("│Basic fee   │ \\ 45000                         │\n");
		printf("└──────────────────────────────────────────────┘\n");
		
		while(1){
			printf("Back to main menu Y/N : ");
			scanf("\n%c", &a);
			
			if(a == 'N' || a == 'Y')
				break;
			
			printf("Wrong Input\n");
		}
		if(a == 'Y')
			break;
	}
}

void two_month(int plan, float feb[], float mar[]){
	char a;
	while(1){
		system("cls");
		printf("┌───────────────────────────────────────────────┐\n");
		printf("│          Last two months usage                │\n");
		printf("├───────────────────────────────────────────────┤\n");
		printf("│  My Plan : %-14s                     │\n", plan == 0 ? "Basic Plan" : "More Data Plan");
		printf("├───────────────────────────────────────────────┤\n");
		printf("│           │   Feburary     │     March        │\n");
		printf("├───────────────────────────────────────────────┤\n");
		printf("│  Voice    │  %6.0f min    │  %6.0f min      │\n", feb[0], mar[0]);
		printf("│  Text     │  %6.0f text   │  %6.0f text     │\n", feb[1], mar[1]);
		printf("│  Data     │  %6.2f GB     │  %6.2f GB       │\n", feb[2], mar[2]);
		printf("└───────────────────────────────────────────────┘\n");

		while(1){
			printf("Back to main menu Y/N : ");
			scanf("\n%c", &a);
			
			if(a == 'N' || a == 'Y')
				break;
			
			printf("Wrong Input\n");
		}
		if(a == 'Y')
			break;
	}
}

void input(float apr[]){
	printf("=================================\n");
	printf("Input your usages of voice : ");
	scanf("%f", &apr[0]);
	
	printf("Input your usages of text : ");
	scanf("%f", &apr[1]);
	
	printf("Input your usages of data : ");
	scanf("%f", &apr[2]);
}