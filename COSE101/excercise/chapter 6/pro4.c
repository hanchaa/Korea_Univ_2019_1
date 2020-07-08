#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 5
#define COL 6

void summatrix(int m1[ROW][COL], int m2[ROW][COL], int m3[ROW][COL]);
void printArray(int arr[ROW][COL]);

int main(void) {
	int a[ROW][COL] = { 0 }, b[ROW][COL] = { 0 }, c[ROW][COL] = { 0 };
	int i, j;
	
	srand(time(NULL));
	
	for(i = 0; i < ROW; i++){
		for(j = 0; j < COL; j++){
			a[i][j] = rand() % 100 + 1;
			b[i][j] = rand() % 100 + 1;
		}
	}
	
	summatrix(a, b, c);
	
	printf("Matrix1: \n");
	printArray(a);
	
	printf("Matrix2: \n");
	printArray(b);
	
	printf("result: \n");
	printArray(c);
	
	return 0;
}

void summatrix(int m1[ROW][COL], int m2[ROW][COL], int m3[ROW][COL]){
	int i, j;
	
	for(i = 0; i < ROW; i++){
		for(j = 0; j < COL; j++){
			m3[i][j] = m1[i][j] + m2[i][j];
		}
	}
}

void printArray(int arr[ROW][COL]){
	int i, j;
	
	for(i = 0; i < ROW; i++){
		for(j = 0; j < COL; j++){
			printf("%4d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}