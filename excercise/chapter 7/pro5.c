#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void f(int *arr);

int main(void){
	srand(time(NULL));
	
	int i, arr[N];
	
	for(i = 0; i < N; i++){
		arr[i] = rand() % 100 + 1;
		printf("%d ", arr[i]);
	}
	
	printf("\n");
	
	f(arr);
}

void f(int *arr){
	for(int i = N - 1; i >= 0; i--)
		printf("%d ", *(arr + i));
	
	printf("\n");
}