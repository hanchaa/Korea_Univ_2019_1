#include <stdio.h>

int main(){
	int a, b, c, d, e;
	
	int max = 0, min = 2e9;
	
	printf("Input 5 integers : ");
	scanf("%d %d %d %d %d",&a ,&b ,&c ,&d ,&e);
	
	if(a > max) max = a;
	if(b > max) max = b;
	if(c > max) max = c;
	if(d > max) max = d;
	if(e > max) max = e;
	
	if(a < min) min = a;
	if(b < min) min = b;
	if(c < min) min = c;
	if(d < min) min = d;
	if(e < min) min = e;
	
	printf("The largest value is %d\n",max);
	printf("The smallest value is %d\n",min);
	
	return 0;
}