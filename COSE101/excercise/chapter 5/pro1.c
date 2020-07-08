#include <stdio.h>
#include <math.h>

double hypotenuse(double a, double b);

int main(void){
	int i;
	double a, b;
	
	for(i = 0; i < 3; i++){
		
		a = 0; b = 0;
		
		while(a <= 0 || b <= 0){
			printf("Enter the sides of the triangle: ");
			
			scanf("%lf %lf", &a, &b);
			
			if(a <= 0 || b <= 0)
				printf("Input error\n\n");
		}
		
		printf("Hypotenuse: %.1f\n\n",hypotenuse(a, b));
	}
	
	
	return 0;
}

double hypotenuse(double a, double b){
	return sqrt(a * a + b * b);
}