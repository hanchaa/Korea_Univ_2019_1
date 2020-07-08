#include <stdio.h>

int main(void){
	int i = 0, num, cnt = 1;
	
	printf("Input the value of range edge : ");
	scanf("%d", &i);
	
	if(i < 50 || i > 100){
		printf("Wrong Input! range edge should be from 50 ~ 100\n");
		return 1;
	}
	
	printf("The Roman numeral equivalence Table from 1 to %d\n", i);
	printf("------------------------------------------------\n");
	printf("Decimal Numbers\tRoman Numerals\n");
	printf("------------------------------------------------\n");
	
	do{
		num = cnt;
		printf("%d\t\t",cnt);
		
		while(num / 100){
			printf("C");
			num %= 100;	
		}

		while(num / 90){
			printf("XC");
			num %= 90;
		}

		while(num / 50){
			printf("L");
			num -= 50;
		}

		while(num / 40){
			printf("XL");
			num -= 40;
		}

		while(num / 10){
			printf("X");
			num -= 10;
		}
		
		while(num / 9){
			printf("IX");
			num -= 9;
		}
		
		while(num / 5){
			printf("V");
			num -= 5;
		}
		
		while(num / 4){
			printf("IV");
			num -= 4;
		}
		
		while(num > 0){
			printf("I");
			num--;
		}
		printf("\n");
		
		cnt++;
	}while(cnt <= i);
	
	return 0;
}