#include <stdio.h>

int main(void){
	int cnt = 1, gross_sale;
	
	while(cnt <= 4){
		printf("Enter Employee %d's sales in dollars: ",cnt);
		scanf("%d",&gross_sale);
		
		if(gross_sale >= 3000)
			printf("Employee %d's salary is : %d\n\n", cnt, (int)(200 + gross_sale * 0.09));
		else
			printf("Employee %d's salary is : 200\n\n", cnt);
		
		cnt++;
	}
	
	return 0;
}