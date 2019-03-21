#include <stdio.h>

#define MAX_SIZE 10

int myStack[MAX_SIZE];
int top = -1;

void Push(int e);
void Pop();

void IsFull();
void IsEmpty();

int Top();

void printStack();

int main() {

	Push(5);
	Push(8);
	Push(-2);
	Push(-5);
	Push(64);
	Push(-15);
	Push(33);

	printStack();

	Pop();
	Pop();
	
	Top();
	printStack();

	Pop();

	printStack();
	Top();

	Push(100);
	Push(-58);
	Push(1666);
	Push(3315);
	Push(1666);
	Push(55);
	Push(1);
	Push(6);

	printStack();

	Pop();
	Pop();
	Pop();
	Pop();
	Pop();
	Pop();
	Pop();
	Pop();
	Pop();

	printStack();

	Pop();
	Pop();

	Pop();

	printStack();

	return 0;
}

void Push(int e) {

	if (top > MAX_SIZE-1) {

		IsFull();
	}

	else {

		myStack[++top] = e;
	}
}

void Pop() {

	if (top <= -1) {

		IsEmpty();
	}

	else {

		myStack[top--] = NULL;
	}

}

void IsFull() {

	printf("Stack Overflow 발생\n");
	printf("\n");

	return -1;

}

void IsEmpty() {

	printf("Stack Underflow 발생\n");
	printf("\n");

	return -1;
}

int Top() {

	printf("Top -> %d\n", myStack[top]);
	printf("\n");

	return myStack[top];
}

void printStack() {

	for (int i = top; i >=0; i--) {

		printf("%d\n", myStack[i]);
	}

	printf("\n");
}


