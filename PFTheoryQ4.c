//Muhammad Hamza Siddiqui 
//25K-0653 BCS-1G
#include <stdio.h>

void Push(int stack[], int size, int *topPoint);
void Pop(int stack[], int *topPoint);
void Peek(int stack[], int top);
void Display(int stack[], int top);
int main() {
	int size;
	printf("Enter the size of the Stack \n");
	scanf("%d", &size);
	int stack[size], top = -1 , choice;
	while (choice != 5) {
		printf("---------- STACK MENU ---------- \n");
		printf("For Push (1) \n");
		printf("For Pop (2) \n");
		printf("For Peek (3) \n");
		printf("For Display (4) \n");
		printf("To Exit (5) \n");
		printf("-------------------------------- \n");
		scanf("%d", &choice);
		switch (choice) {
			case 1: {
				Push(stack, size, &top );
				break;
			}
			case 2: {
				Pop(stack, &top);
				break;
			}
			case 3: {
				Peek(stack, top);
				break;
			}
			case 4: {
				Display(stack, top);
				break;
			}
			case 5: {
				printf("Exited Sucessfully!");
				break;
			}
			default: {
				printf("Invalid Choice! \n");
				break;
			}
		}
	}
	return 0;
}
void Push(int stack[], int size, int *topPoint) {
	int value;
	if (*topPoint == size - 1) {
		printf("Stack Overflow! Cannot push more elements \n");
	} else {
		printf("Enter value to push: ");
		scanf("%d", &value);
		(*topPoint)++;
		stack[*topPoint] = value;
		printf("%d pushed into stack.\n", value);
	}
}
void Pop(int stack[], int *topPoint) {
	if (*topPoint == -1) {
		printf("Stack Underflow! No item to pop \n");
	} else {
		printf("Popped Value: %d \n", stack[*topPoint]);
		(*topPoint)--;
	}
}
void Peek(int stack[], int top) {
	if (top == -1) {
		printf("Stack is empty \n");
	} else {
		printf("Top Value: %d \n", stack[top]);
	}
}
void Display(int stack[], int top) {
	int i;
	if (top == -1) {
		printf("Stack is empty \n");
	} else {
		printf("Stack elements: ");
		for (i = top; i >= 0; i--) {
			printf("%d ", stack[i]);
		}
		printf("\n");
	}
}


