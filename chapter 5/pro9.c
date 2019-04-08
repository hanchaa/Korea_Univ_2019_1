#include <stdio.h>

void tower(int c, int start, int end, int tmp);

int main(void){
	int n;
	
	printf("Enter the starting number of disks: ");
	scanf("%d", &n);
	
	tower(n, 1, 3, 2);
	
	return 0;
}

void tower(int c, int start, int end, int tmp){
	if(c > 0){
		tower(c - 1, start, tmp, end);
		
		printf("%d --> %d\n", start, end);
		
		tower(c - 1, tmp, end, start);
	}
}