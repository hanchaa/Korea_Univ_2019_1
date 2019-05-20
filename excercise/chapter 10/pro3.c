#include <stdio.h>

unsigned reverseBits(unsigned bits);
void displaybits(unsigned bits);

int main(void){
	unsigned tmp, result;
	
	printf("Enter an unsigned integer: ");
	scanf("%u", &tmp);
	
	printf("\nBefore bits are reversed:\n%u = ", tmp);
	displaybits(tmp);
	
	result = reverseBits(tmp);
	printf("After bits are reversed:\n%u = ", result);
	displaybits(result);
	return 0;
}

unsigned reverseBits(unsigned bits){
	unsigned mask = 1, temp = 0;
	int i;
	
	for(i = 0; i <= 15; i++){
		temp <<= 1;
		temp |= (bits & mask);
		bits >>= 1;
	}
	
	return temp;
}

void displaybits(unsigned bits){
	unsigned mask = 1 << 15;
	
	for(int i = 1; i <= 16; i++){
		printf("%d", bits & mask ? 1 : 0);
		if(i % 8 == 0)
			printf(" ");
		
		bits <<= 1;
	}
	printf("\n\n");
}
