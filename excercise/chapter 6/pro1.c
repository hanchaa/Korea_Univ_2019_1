#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

int main(void) {
	int array[SIZE];
	int i = 0, j = 0, tmp;
	
	srand(time(NULL));
	
	while(i < SIZE){
		tmp = rand() % 20 + 1;
		
		for(j = 0; j < i; j++){
			if(tmp == array[j])
				break;
		}
		
		if(j == i){
			array[i] = tmp;
			i++;
		}
		
	}
	
	for(i = 0; i < SIZE; i++)
		printf("Array[ %d ] = %d\n", i, array[i]);
	
	return 0;
}
