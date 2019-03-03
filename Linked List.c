#include <stdio.h>
#include <stdlib.h>

typedef struct _node{ // node ����ü
	int data;
	struct _node* next;
}node;

typedef node* nptr; // node ������ ��Ī : nptr

typedef struct _list{ // list ����ü
	int count;
	nptr head;
}list;

// typedef�� ��Ī�� �������, ��Ī�� ���� �ܺο��� ������ ����ü ������ ������ �� ���� 

void init(list* lptr); // ����Ʈ �ʱ�ȭ
void insert(list* lptr, int val, int pos); // ����Ʈ ����
void delete(list* lptr, int pos); // ����Ʈ ����
int search(list* lptr, int val); // ����Ʈ �˻�
void modify(list* lptr, int val, int pos); // ����Ʈ ����
void print_list(list* lptr); // ����Ʈ ���

int main() {

	return 0;
}