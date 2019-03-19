#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int value;
	struct _node* next;
}node;

typedef node* nptr;

typedef struct _list {
	int count;
	nptr head;
}list;

void init(list* lptr);
void insert(list* lptr, int value, int position);
void delete(list* lptr, int position);
int search(list* lptr, int value);
void modify(list* lptr, int value, int position);
void print_list(list* lptr);


void init(list* lptr) {
	//initialize the list
	lptr->count = 0;
	lptr->head = NULL;
}

void insert(list* lptr, int value, int position) {
	//insert value to proper position
	if (position<1 || position>(lptr->count) + 1) {
		printf("Position Out of Bound\n");
		return;
	}
	nptr new_nptr = (node*)malloc(sizeof(node));
	new_nptr->value = value;

	if (position == 1) {
		new_nptr->next = lptr->head;
		lptr->head = new_nptr;
	}
	else {
		nptr tmp = lptr->head;
		int i;
		for (i = 1; i<position - 1; i++) {
			tmp = tmp->next;
		}
		new_nptr->next = tmp->next;
		tmp->next = new_nptr;
	}
	lptr->count++;
}

void delete(list* lptr, int position) {
	//delete an item on the position
	if (position<1 || position>(lptr->count)) {
		printf("Position Out of Bound\n");
		return;
	}
	nptr tmp = lptr->head;

	if (position == 1) {
		lptr->head = tmp->next;
		free(tmp);
	}
	else {
		int i;
		for (i = 1; i<position - 1; i++) {
			tmp = tmp->next;
		}
		nptr tmp2 = tmp->next;
		tmp->next = tmp2->next;
		free(tmp2);
	}
	lptr->count--;
}

int search(list* lptr, int value) {
	//traverse the list and
	//find the first position of the value (first from head)
	//if not exist, return 0
	nptr tmp = lptr->head;
	int i = 1;
	while (tmp != NULL) {
		if (value == tmp->value) break;
		i++;
		tmp = tmp->next;
	}
	if (i>lptr->count) {
		printf("The value %d is NOT exists\n", value);
		return 0;
	}
	else {
		printf("The value %d is at position %d in the list\n", value, i);
		return i;
	}
}

void modify(list* lptr, int value, int position) {
	if (position<1 || position>(lptr->count)) {
		printf("Position Out of Bound\n");
		return;
	}
	nptr tmp = lptr->head;

	int i;
	for (i = 1; i<position; i++) {
		tmp = tmp->next;
	}
	tmp->value = value;
}

void print_list(list* lptr) {
	nptr tmp = lptr->head;
	printf("List value: ");
	while (tmp != NULL) {
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
	printf("Total: %d value(s)\n", lptr->count);
}

int main() {
	list* mylist = (list*)malloc(sizeof(list));
	init(mylist);

	insert(mylist, 5, 1);
	insert(mylist, 7, 2);
	insert(mylist, 3, 3);
	insert(mylist, -5, 4);
	insert(mylist, 6, 5);
	insert(mylist, 3, 6);
	insert(mylist, 6, 7);
	insert(mylist, 9, 8);

	print_list(mylist);

	delete(mylist, 3);
	delete(mylist, 5);

	print_list(mylist);

	search(mylist, 6);
	search(mylist, 9);
	search(mylist, 0);

	modify(mylist, 100, 1);
	modify(mylist, 101, 2);

	print_list(mylist);

	return 0;
}

// 출처 : https://milvus.tistory.com/17
