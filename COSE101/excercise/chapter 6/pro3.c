#include <stdio.h>
#define SIZE 30

void stringReverse(char strArray[]);

int main(void) {
	char strArray[SIZE] = "Print this string backward.";
	
	printf("%s\n", strArray);
	
	stringReverse(strArray);
	
	printf("\n");
	return 0;
}

void stringReverse(char strArray[]){
	if(strArray[0] != '\0'){
		stringReverse(&strArray[1]);
		printf("%c",strArray[0]);
	}
}