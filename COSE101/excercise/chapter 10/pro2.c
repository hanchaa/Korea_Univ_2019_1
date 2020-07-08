#include <stdio.h>

unsigned power2(unsigned number, unsigned pow);
void displaybits(unsigned bits);

int main(void){
	unsigned number, pow, result;
	
	printf("Enter two integers: ");
	scanf("%u %u", &number, &pow);
	
	printf("number:\n");
	displaybits(number);
	
	printf("pow:\n");
	displaybits(pow);
	
	result = power2(number, pow);
	printf("%d * 2^%d = %d\n", number, pow, result);
	displaybits(result);
	
	
	return 0;
}

unsigned power2(unsigned number, unsigned pow){
	return number << pow;	
}

void displaybits(unsigned bits){
	unsigned mask = 1 << 15;
	
	printf("\t");
	
	for(int i = 1; i <= 16; i++){
		printf("%d", bits & mask ? 1 : 0);
		if(i % 8 == 0)
			printf(" ");
		
		bits <<= 1;
	}
	printf("\n\n");
}
