#include <stdio.h>

int add(int, int);
int sub(int, int);
int mul(int, int);

int main(void){
	int (*func[3])(int, int) = {add, sub, mul};
	char op[3] = {'+', '-', '*'};
	int menu, a, b;
	
	while(1){
		printf("0.Addition\n");
		printf("1.Subtraction\n");
		printf("2.Multiplication\n");
		printf("3.End\n");
		printf("select the operation: ");
		
		scanf("%d", &menu);
		
		if(menu == 3)
			break;
		
		printf("Enter the two numbers: ");
		scanf("%d %d",&a ,&b);
		printf("\n\t%d %c %d = %d\n\n", a, op[menu], b, func[menu](a, b));
	}
}

int add(int a, int b){
	return a + b;
}
	
int sub(int a, int b){
	return a - b;
}
	
int mul(int a, int b){
	return a * b;
}