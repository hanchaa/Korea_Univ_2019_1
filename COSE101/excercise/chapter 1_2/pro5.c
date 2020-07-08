#include <stdio.h>

int main(void) {
	int num, sum = 0;

	printf("Input : ");
	scanf_s("%d", &num);

	printf("Output :\n");

	printf("%d   ", num % 10);
	if ((num % 10) % 2 == 1) sum = sum + (num % 10);
	num = num / 10;

	printf("%d   ", num % 10);
	if ((num % 10) % 2 == 1) sum = sum + (num % 10);
	num = num / 10;

	printf("%d   ", num % 10);
	if ((num % 10) % 2 == 1) sum = sum + (num % 10);
	num = num / 10;

	printf("%d   ", num % 10);
	if ((num % 10) % 2 == 1) sum = sum + (num % 10);
	num = num / 10;

	printf("%d\n", num);
	if (num % 2 == 1) sum = sum + num;

	printf("%d\n", sum);

	return 0;
}