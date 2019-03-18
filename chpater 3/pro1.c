#include <stdio.h>

int main(void){
	int a, b, cnt, sum = 0;
	printf("Enter twp omtegers : ");
	scanf("%d %d", &a, &b);
	cnt = a;
	while(cnt<=b){
		sum += cnt;
		cnt++;
	}
	printf("The sum of all integers between %d and %d is %d\n",a ,b ,sum);
}