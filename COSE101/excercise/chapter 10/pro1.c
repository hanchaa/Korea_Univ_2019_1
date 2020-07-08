#include <stdio.h>

int main(void){
	unsigned tmp, mask = 1 << 31;
	int cnt = 0;
	
	printf("Enter an integer: ");
	scanf("%u", &tmp);
	
	for(int i = 1; i <= 32; i++){
		if(tmp & mask)
			cnt++;
		
		tmp <<= 1;
	}
	
	printf("\nThe total number of 1s in the bit representation is %s\n", cnt % 2 ? "odd" : "even");
	
	return 0;
}