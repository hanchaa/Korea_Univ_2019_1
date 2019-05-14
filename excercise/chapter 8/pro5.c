#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void encryptor(char s[][10], char cipher[]);
void decryptor(char s[][10], char cipher[]);

int main(void){
	char s[10][10] = {"craftbeer", "metallica", "whitewine", "champagne", "bourgogne", "sandiego", "lafayette", "pinotnoir", "sauvignon", "dondiablo"}, cipher[10];
	
	srand(time(NULL));
	
	encryptor(s, cipher);
	
	decryptor(s, cipher);
	
	return 0;
}

void encryptor(char s[][10], char cipher[]){
	int tmp = rand() % 10, key = rand() % 19 + 1;
	
	strcpy(cipher, s[tmp]);
	
	for(int i = 0; cipher[i]; i++){
		if(cipher[i] + key > 'z')
			cipher[i] = cipher[i] + key - 'z' + 'a' - 1;
		else
			cipher[i] = cipher[i] + key;
	}
	
	printf("        - Encryptor -\n");
	printf(" Selected word: %s\n", s[tmp]);
	printf(" Selected value of the Key: %d\n", key);
	printf(" Ciphertext: %s\n\n", cipher);
}

void decryptor(char s[][10], char cipher[]){
	int i, j;
	
	printf("         - Decoder -\n");
	printf(" Ciphertext input: %s\n\n\n", cipher);
	
	for(i = 1; i <= 19; i++){
		printf("> Guess %d <\n", i);
		printf("  Key: %d\n", i);
		
		for(j = 0; cipher[j]; j++){
			cipher[j]--;
			if(cipher[j] < 'a')
				cipher[j] = 'z';
		}
		
		printf("  Plaintext: %s\n", cipher);
		
		for(j = 0; j < 10; j++){
			if(strcmp(s[j], cipher) == 0){
				printf("Found the correct answer!\n\n");
				break;
			}
		}
		
		if(j <= 9)
			break;
		
		if(j > 9)
			printf("Matching word not found.\n\n");
	}
	
	printf("result: '%d' was selected as the Key.\n", i);
	printf("         '%s' was the Plaintext.\n", cipher);
}