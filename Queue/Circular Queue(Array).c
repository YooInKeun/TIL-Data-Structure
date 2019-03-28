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

	printQueue();

	insert(100);

	printQueue();

	insert(50);

	printQueue();

	delete();
	delete();
	delete();
	delete();

	printQueue();

	delete();
	delete();
	delete();
	delete();
	delete();

	printQueue();

	delete();

	printQueue();

	delete();

	return 0;
}

void insert(int e) {

	if (rear !=-1 && (rear+1)%MAX_SIZE == front%MAX_SIZE) {

		isFull();
	}

	else {

		++rear;
		myQueue[rear%MAX_SIZE] = e;
	}
}

void delete() {

	if (front > rear) {

		isEmpty();
	}

	else {

		myQueue[front%MAX_SIZE] = NULL;
		++front;
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

	int tmp;

		for (int i = front; i <= rear ; i++) {

			tmp = i % MAX_SIZE;

			printf("%d ", myQueue[tmp]);

		}

	printf("\n");
}