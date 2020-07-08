#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip(void);

int main(void){
	int t = 0, h = 0, i;
	
	srand(time(NULL));
	
	for(i = 1; i <= 100; i++){
		if(flip() == 1)
			h++;
		
		else
			t++;
		
		if(i % 10 == 0)
			printf("\n");
	}
	
	printf("\n");
	
	printf("The total number of Heads was %d\n", h);
	printf("The total number of Tails was %d\n", t);
	
	return 0;
}

int flip(void){
	if(rand() % 2 == 0){
		printf("Tails ");	
		return 0;
	}
	
	else{
		printf("Heads ");
		return 1;
	}
}