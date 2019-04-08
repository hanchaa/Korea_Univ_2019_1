#include <stdio.h>

void i_to_a(int a);

int main(void){
	int a;
	while(1){
		printf("Enter the inputs : ");
		scanf("%d",&a);
		
		if(a >= 100000 && a <= 999999)
			break;
		else
			printf("Input Error!\n");
	}
	
	i_to_a(a);
	
	printf("\n");
	
	return 0;
}

void i_to_a(int a){
	int tmp;
	
	if(a >= 100)
		i_to_a(a / 100);
	
	tmp = a % 100;
	
	if(tmp > 25) tmp %= 26;
	
	printf("%c ", tmp + 65);
}