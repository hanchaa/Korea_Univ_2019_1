#include <stdio.h>

int main(void){
	int a, num, cnt = 0;
	
	printf("Enter a 5-digit number: ");
	scanf("%d", &a);
	
	if ( a < 0)
		return 1;
	if( a > 99999)
		return 1;
	
	num = a;
	
	while(num > 0){
		if(num % 10 == 7) cnt++;
		
		num /= 10;
	}
	
	printf("The number %d has %d seven(s) in it\n", a, cnt);
	
	return 0;
}