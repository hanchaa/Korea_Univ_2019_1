#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int menu;
	
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
				break;
			
			case 2 :
				break;
			
			case 3 :
				break;
			
			case 4 :
				break;
			
			case 5 :
				break;

		}
	}
	return 0;
}