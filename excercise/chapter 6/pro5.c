#include <stdio.h>
#define row 5
#define col 6

void Sorting(int a[row][col]);

int main(void) {
	int i, j;
	
	int data[row][col] = { 0 };
	
	for(i = 0; i < row; i++){
		printf("INDEX %d\n",i);
		printf("Enter 5 Quiz scores :\n");
		
		for(j = 0; j < col - 1; j++){
			scanf("%d", &data[i][j]);
			data[i][5] += data[i][j];
		}
		printf("\n");
		
		data[i][5] /= 5;
	}
	
	Sorting(data);
	
	printf("From Highest Scores to Lowest :\n");
	for(i = 0; i < row; i++){
		printf("%d ", data[i][5]);
	}
	
	printf("\n");
	
	return 0;
}

void Sorting(int a[row][col]){
	int i, j, tmp;
	
	for(i = 0; i < row; i++){
		for(j = 0; j < row - i - 1; j++){
			if(a[j][5] < a[j + 1][5]){
				tmp = a[j][5];
				a[j][5] = a[j + 1][5];
				a[j + 1][5] = tmp;
			}
		}
	}
}