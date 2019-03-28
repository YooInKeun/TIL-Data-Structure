#include <stdio.h>

#define MAX_SIZE 10

int myQueue[MAX_SIZE];
int front = 0;
int rear = -1;

void insert(int e);
void delete();

void isFull();
void isEmpty();

void printQueue();

int main() {

	insert(5);
	insert(10);
	insert(-3);
	insert(-1);

	printQueue();

	delete();
	delete();

	printQueue();

	insert(50);

	printQueue();

	insert(2);
	insert(15);
	insert(100);
	insert(-60);
	insert(50);

	printQueue();

	insert(100);


	delete();
	delete();
	delete();
	delete();
	delete();
	delete();
	delete();
	delete();
	delete();
	delete();

	return 0;
}

void insert(int e) {

	if (rear == MAX_SIZE-1) {

		isFull();
	}

	else {

		myQueue[++rear] = e;
	}
}

void delete() {

	if (front > rear) {

		isEmpty();
	}

	else {

		myQueue[front++] = NULL;
	}
}

void isFull() {

	printf("Queue Overflow\n");
	printf("\n");

	return -1;
}

void isEmpty() {

	printf("Queue Underflow\n");
	printf("\n");

	return -1;
}

void printQueue() {

	for (int i = front; i <= rear; i++) {

		printf("%d ", myQueue[i]);
	}

	printf("\n");
}