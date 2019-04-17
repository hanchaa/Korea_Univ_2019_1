#include <stdio.h>
#define SIZE 15

int BinarySearch(const int b[], int serachKey, int low, int high);
void printHeader(void);
void printRow(const int b[], int low, int mid, int high);

int main(void) {
	int a[SIZE];
	int i;
	int key;
	int result;
	
	for(i = 0; i < SIZE; i++){
		a[i] = i * 2;
	}
	
	printf("Enter a number betweent 0 and 28: ");
	scanf("%d", &key);
	
	printHeader();
	
	result = BinarySearch(a, key, 0, SIZE - 1);
	
	if(result != -1) {
		printf("%d found in array element %d\n", key, result);
	}
	else{
		printf("%d not found\n", key);
	}
	
	return 0;
}

int BinarySearch(const int b[], int searchKey, int low, int high){
	int middle;
	
	while(low <= high){
		middle = (low + high) / 2;
		
		printRow(b, low, middle, high);
		
		if(searchKey == b[middle])
			return middle;
		
		else if(searchKey < b[middle])
			high = middle - 1;
		
		else
			low = middle + 1;
	}
	
	return -1;
}

void printHeader(){
	int i;
	
	printf("\nSubscripts:\n");
	
	for(i = 0; i < SIZE; i++){
		printf("%3d ", i);
	}
	
	printf("\n");
	
	for(i = 1; i <= 4 * SIZE; i++){
		printf("-");
	}
	
	printf("\n");
}

void printRow(const int b[], int low, int mid, int high){
	int i;
	
	for(i = 0; i < SIZE; i++){
		
		if(i < low || i > high){
			printf("    ");
		}
		
		else if(i == mid){
			printf("%3d*", b[i]);
		}
		
		else{
			printf("%3d ", b[i]);
		}
	}
	
	printf("\n");
}