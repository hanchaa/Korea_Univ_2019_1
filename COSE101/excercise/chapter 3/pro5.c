#include <stdio.h>

int main(void) {
	int cnt = 1, gross_sale, salary;

	while (cnt <= 4) {
		printf("Enter Employee %d's sales in dollars: ", cnt);
		scanf("%d", &gross_sale);

		salary = 200;

		if (gross_sale >= 3000)
			salary += gross_sale * 0.09;
		
		printf("Employee %d's salary is : %d\n\n", cnt, salary);

		cnt++;
	}

	return 0;
}