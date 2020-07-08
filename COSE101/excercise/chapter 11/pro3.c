#include <stdio.h>
#include <stdlib.h>

void printfMatrix(int mat[2][3]);
void fprintfMatrix(int mat[2][3], FILE *fp);

int main(void){
	int stid, res[2][3], input1[2][3], input2[2][3];
	
	FILE *f1 = fopen("input1.txt", "r");
	FILE *f2 = fopen("input2.txt", "r");
	FILE *f3 = fopen("result.txt", "w");
	
	if(f1 == NULL || f2 == NULL){
		printf("Input files could not be opened\n");
		exit(1);
	}
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			fscanf(f1, "%d", &input1[i][j]);
			fscanf(f2, "%d", &input2[i][j]);
			res[i][j] = input1[i][j] + input2[i][j];
		}
	}
	printf("Input1 Matrix:\n");
	printfMatrix(input1);
	
	printf("Input2 Matrix:\n");
	printfMatrix(input2);
	
	printf("Result Matrix:\n");
	fprintfMatrix(res, f3);
	
	fclose(f1);
	fclose(f2);
	fclose(f3);

	return 0;
}

void printfMatrix(int mat[2][3]){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}

void fprintfMatrix(int mat[2][3], FILE *fp){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			printf("%d\t", mat[i][j]);
			fprintf(fp, "%d\t", mat[i][j]);
		}
		printf("\n");
		fprintf(fp, "\n");
	}
}