#include <stdio.h>

int main(void){
	int a = -1, fac = 1, cnt;
	
	while(a < 0){
		printf("Enter a positive integer: ");
		scanf("%d", &a);
	}
	
	cnt = a;
	
	while(cnt >= 1){
		fac *= cnt--;
	}
	
	printf("%d! is %d\n", a, fac);
	
	return 0;
}