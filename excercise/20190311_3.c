#include <stdio.h>

int main(void){
	int max, min, a, b, c, tmp;
	
	printf("Input 5 integers : ");
	
	scanf("%d %d %d %d %d",&max ,&min ,&a ,&b ,&c);
	
	if(max < min){
		tmp = max;
		max = min;
		min = tmp;
	}
	
	if(a > max) max = a;
	if(b > max) max = b;
	if(c > max) max = c;
	
	if(a < min) min = a;
	if(b < min) min = b;
	if(c < min) min = c;
	
	printf("The largest value is %d\n",max);
	printf("The smallest value is %d\n",min);
	
	return 0;
}