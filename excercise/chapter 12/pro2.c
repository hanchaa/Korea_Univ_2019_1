#include <stdio.h>
#include <stdlib.h>

struct stackNode {
	int data;
	struct stackNode* nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode* StackNodePtr;

void push(StackNodePtr* topPtr, int info);
int pop(StackNodePtr* topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions(void);

int isEmpty(StackNodePtr topPtr) {
	return topPtr == NULL;
}

void printStack(StackNodePtr currentPtr) {
	if (currentPtr == NULL) {
		printf("Stack is empty. \n\n");
	}
	else {
		printf("The Stack is : \n");

		while (currentPtr != NULL) {
			printf(" %d --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		printf("NULL \n\n");
	}
}

void instructions() {
	printf("Enter your choice : \n");
	printf("\t 1 to to push a value on the stack. \n");
	printf("\t 2 to to pop a value off the stack. \n");
	printf("\t 3 to end program. \n");
}

void push(StackNodePtr* topPtr, int info) {
	StackNodePtr newPtr = malloc(sizeof(StackNode));

	if (newPtr != NULL) {
		newPtr->data = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}
	else
		printf("%d not inserted. No memory available.\n", info);
}

int pop(StackNodePtr* topPtr) {
	StackNodePtr temp = *topPtr;
	int res = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	free(temp);
	return res;
}

void main() {
	StackNodePtr stackPtr = NULL;
	int choice;
	int value;

	instructions();
	printf("? ");
	scanf("%d", &choice);

	while (choice != 3) {
		switch (choice) {
		case 1:
			while (!getchar());
			printf("Enter a integer: ");
			scanf("%d", &value);
			push(&stackPtr, value);
			printStack(stackPtr);
			break;

		case 2:
			while (!getchar());
			if (!isEmpty(stackPtr)) {
				printf("The popped value is %d. \n", pop(&stackPtr));
			}
			printStack(stackPtr);
			break;

		default:
			while (!getchar());
			printf("Invalid choice. \n\n");
			instructions();
			break;
		}
		printf("? ");
		scanf("%d", &choice);
	}
	printf("End of run. \n");
}