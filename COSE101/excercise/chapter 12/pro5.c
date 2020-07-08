#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
	char data[30];
	struct list *next;
} List, *Listptr;

void printlist(Listptr sPtr, int cnt);
void insert(Listptr *sPtr, char *str);
void delete(Listptr *ptr);
void merge(Listptr *sPtr, Listptr *s1);

void main() {
	FILE *fr = fopen("input1.txt", "r");
	char  str[30];
	Listptr s1 = NULL, s2 = NULL, start = NULL;

	while (!feof(fr)) {
		fscanf(fr, "%s", str);
		insert(&s1, str);
	}
	printlist(s1, 1);
	printf("\n");
	fclose(fr);

	fr = fopen("input2.txt", "r");

	while (!feof(fr)) {
		fscanf(fr, "%s", str);
		insert(&s2, str);
	}
	printlist(s2, 2);
	printf("\n");
	fclose(fr);

	while (s1 != NULL)
		merge(&start, &s1);
	while (s2 != NULL)
		merge(&start, &s2);
	printlist(start, 3);

}

void printlist(Listptr sPtr, int cnt) {
	FILE *fw = fopen("output.txt", "w");

	if (sPtr == NULL)
		printf("List empty!\n");
	else {
		if (cnt == 3) {
			printf("Result linked list: %s", sPtr->data);
			fprintf(fw, "%s\n", sPtr->data);
		}
		else
			printf("Input linked list %d: %s", cnt, sPtr->data);

		sPtr = sPtr->next;

		while (sPtr != NULL) {
			printf(" -> %s", sPtr->data);
			if (cnt == 3)
				fprintf(fw, "%s\n", sPtr->data);
			sPtr = sPtr->next;
		}

		printf("\n");
	}

	fclose(fw);
}

void insert(Listptr *sPtr, char *str) {
	Listptr new = malloc(sizeof(List)), current = *sPtr, pre = NULL;

	if (new != NULL) {
		strcpy(new->data, str);
		new->next = NULL;

		while (current != NULL) {
			pre = current;
			current = current->next;
		}

		if (pre == NULL)
			*sPtr = new;
		else
			pre->next = new;
	}
	else
		printf("%s not inserted. No memory available\n", str);
}

void merge(Listptr *sPtr, Listptr *s1) {
	Listptr pre = NULL, current = *sPtr, temp;

	while (current != NULL && strcmp((*s1)->data, current->data) > 0) {
		pre = current;
		current = current->next;
	}

	if (current != NULL && strcmp(current->data, (*s1)->data) == 0)
		delete(s1);

	else if (pre == NULL) {
		*sPtr = *s1;
		*s1 = (*s1)->next;
		(*sPtr)->next = current;
	}

	else {
		temp = *s1;
		*s1 = (*s1)->next;
		pre->next = temp;
		temp->next = current;
	}

}

void delete(Listptr *ptr) {
	Listptr temp = *ptr;
	*ptr = (*ptr)->next;
	free(temp);
}
