#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

int main(void) {
	int array[SIZE];
	int i = 0, j = 0, tmp, cnt;
	
	srand(time(NULL));
	
	for(cnt = 0; cnt < SIZE; cnt++){
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
	
	for(cnt = 0; cnt < i; cnt++)
		printf("Array[ %d ] = %d\n", cnt, array[cnt]);
	
	return 0;
}
