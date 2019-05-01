#include <stdio.h>

void f(int *a, int *b, int *c);

int main(void){
	int a, b, c;
	
	printf("Enter three numbers: ");
	scanf("%d %d %d", &a, &b, &c);
	
	printf("Befroe: a = %d, b = %d, c = %d\n", a, b, c);
	
	f(&a, &b, &c);
	
	printf("After: a = %d, b = %d, c = %d\n", a, b, c);
}

void f(int *a, int *b, int *c){
	*a += 1;
	
	*b *= *c;
	
	int tmp = *b;
	*b = *c;
	*c = tmp;
}