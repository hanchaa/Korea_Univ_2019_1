#include <stdio.h>

int checkCase(char cha);
void convertCharCase(char *sPtr);

int main(void){
	char str[] = "PoINteR is vERy ImPorTAnt in C pRoGraMMing, SO STudEnt nEEd tO pRACtiCe usING poINTer";
	
	printf("Original String 1 :\n%s\n\n", str);

	convertCharCase(str);
	
	printf("Converted String 2 :\n%s\n", str);
}

int checkCase(char cha){
	if(cha >= 'a' && cha <= 'z')
		return 0;
	if(cha >= 'A' && cha <= 'Z')
		return 1;
}

void convertCharCase(char *sPtr){
	
	int tmp;
	
	for(int i = 0; *(sPtr + i); i++){
		
		tmp = checkCase(*(sPtr + i));
		if(tmp == 0)
			*(sPtr + i) -= 32;
		
		if(tmp == 1)
			*(sPtr + i) += 32;
	}
}