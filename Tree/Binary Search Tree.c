#include <stdio.h>

typedef int boolean; // c에서는 bool 타입이 없어서 typedef로 직접 구현
#define true 1
#define false 0

typedef struct node { // tree node

	int data; // node의 data
	struct node *right_child; // node의 right_child
	struct node *left_child; // node의 left_child

}node;

node* root = NULL; // root node는 전역 변수로 설정
int flag = 0; // contains 함수에서 tree에 조사하고자 하는 node가 없을 때, false 값을 리턴하기 위한 flag
			  // 이 전역변수가 없으면, false인 경우 쓰레기 값 리턴(true인 경우는 상관없음)

void initTree(int data); // tree 초기화(root node 생성)

boolean isEmpty(); // bst empty인지 체크
void makeEmpty(node *root); // bst가 empty가 되도록 clear
void inOrder(node *root); // inoredr traversal
void preOrder(node *root); // preoredr traversal
void postOrder(node *root); // postoredr traversal
boolean contains(node *root, int data); // bst에 data가 존재하는지 체크
void put(int data); // bst에 node put, 이미 같은 data값의 node가 존재하면 아무일도 일어나지 않음
node* delete(node* root, int data); // bst에서 특정 data를 가진 node 제거, 그 data를 갖는 node가 존재하지 않으면 아무일도 일어나지 않음

void initFlag(); // flag값 0으로 초기화

int main() {

	printf("isEmpty 확인 : %d\n", isEmpty(root));

	initTree(6);

	printf("isEmpty 확인 : %d\n", isEmpty(root));

	put(root, 2);
	put(root, 7);
	put(root, 7);
	put(root, 1);
	put(root, 4);
	put(root, 4);
	put(root, 3);
	put(root, 5);

	printf("Preorder Traversal : ");
	preOrder(root);
	printf("\n");

	printf("Inorder Traversal : ");
	inOrder(root);
	printf("\n");

	printf("Postorder Traversal : ");
	postOrder(root);
	printf("\n");

	printf("contains(5 확인) : %d\n", contains(root, 5));
	initFlag();

	printf("contains(8 확인) : %d\n", contains(root, 8));
	initFlag();

	printf("contains(1 확인) : %d\n", contains(root, 1));
	initFlag();

	printf("Inorder Traversal(기존) : ");
	inOrder(root);
	printf("\n");

	root = delete(root, 2);
	printf("Inorder Traversal(2 제거) : ");
	inOrder(root);
	printf("\n");

	root = delete(root, 4);
	printf("Inorder Traversal(4 제거) : ");
	inOrder(root);
	printf("\n");

	root = delete(root, 8);
	printf("Inorder Traversal(8 제거) : ");
	inOrder(root);
	printf("\n");

	printf("makeEmpty 실행\n");
	makeEmpty(root);

	printf("isEmpty 확인 : %d\n", isEmpty(root));

	return 0;
}

void initTree(int data) { // tree 초기화(root node 생성)

	node* newNode = (node*)malloc(sizeof(node));

	root = newNode;
	root->data = data;
	root->left_child = NULL;
	root->right_child = NULL;
}

boolean isEmpty() { // bst empty인지 체크

	if (root == NULL)
		return true;

	else
		return false;
}

void makeEmpty(node *root) { // bst가 empty가 되도록 clear(postorder : free(left_child)-> free(right_child)-> free(root))

	if (root != NULL) {

		makeEmpty(root->left_child);
		makeEmpty(root->right_child);
		free(root);
	}
}

void inOrder(node *root) { // inoredr traversal

	if (root != NULL) {

		inOrder(root->left_child);
		printf("%d ", root->data);
		inOrder(root->right_child);
	}
}

void preOrder(node *root) { // preoredr traversal

	if (root != NULL) {

		printf("%d ", root->data);
		preOrder(root->left_child);
		preOrder(root->right_child);
	}
}

void postOrder(node *root) { // postoredr traversal

	if (root != NULL) {

		postOrder(root->left_child);
		postOrder(root->right_child);
		printf("%d ", root->data);
	}
}

boolean contains(node *root, int data) { // bst에 data가 존재하는지 체크

	if (root != NULL) {

		if (root->data == data) { // node를 찾으면

			flag = 1; // true(flag=1) 리턴
		}

		if (flag == 0) { // node를 찾지 못했을 때

			contains(root->left_child, data); // left_child 탐색
			contains(root->right_child, data); // right_child 탐색
		}
	}

	return flag; // node를 결국 못찾으면 false(flag=0) 리턴
}

void put(node* root, int data) { // bst에 node put, 이미 같은 data값의 node가 존재하면 아무일도 일어나지 않음

	node* newNode = (node*)malloc(sizeof(node));

	newNode->data = data;

	int tmp;

	if (root->data > newNode->data) { // put되는 node의 data가 root의 data보다 작을 때

		if (root->left_child != NULL) {

			tmp = newNode->data;
			free(newNode);
			put(root->left_child, tmp); // left_child가 존재하면, 다시 put함수 호출

			return 0;
		}

		else { // left_child가 없으면, newNode가 root의 left_child가 됨

			root->left_child = newNode;
		}
	}

	else if (root->data < newNode->data) { // put되는 node의 data가 root의 data보다 클 때

		if (root->right_child != NULL) { // right_child가 존재하면, 다시 put함수 호출

			tmp = newNode->data;
			free(newNode);
			put(root->right_child, tmp);

			return 0;
		}

		else { // right_child가 없으면, newNode가 root의 right_child가 됨

			root->right_child = newNode;
		}
	}

	else if (root->data == newNode->data) { // newNode의 data값과 동일한 node가 이미 존재할 때

		printf("data값이 %d인 node가 이미 존재합니다.\n", newNode->data);
		free(newNode);
		return 0; // 함수 종료
	}

	newNode->left_child = NULL;
	newNode->right_child = NULL;
}

node* delete(node* root, int data) { // bst에서 특정 data를 가진 node 제거, 그 data를 갖는 node가 존재하지 않으면 아무일도 일어나지 않음

	struct node *node_ptr = NULL;

	if (root == NULL) {

		return root;
	}

	if (root->data > data) { // node의 data가 찾고자 하는 data보다 크면 left_child 탐색

		root->left_child = delete(root->left_child, data);
	}

	else if (root->data < data) { // node의 data가 찾고자 하는 data보다 작으면 right_child 탐색

		root->right_child = delete(root->right_child, data);
	}

	else if (root->data == data) { // 찾고자 하는 data를 갖는 node를 찾으면

		if (root->left_child == NULL){ // left_child가 NULL이면 right_child 중에 가장 값이 작은 data를 갖는 node 필요

			node_ptr = root->right_child;
			free(root);
			return node_ptr;
		}
			
		else if (root->right_child == NULL){ // right_child가 NULL이면, left_child 중 가장 상위 레벨에 있는 node 필요
			node_ptr = root->left_child;
			free(root);
			return node_ptr;
		}

		node_ptr = root->right_child;

		while (node_ptr !=NULL && node_ptr->left_child != NULL) { // data 값이 가장 작은 node 찾기

			node_ptr = node_ptr->left_child; // 가장 왼쪽에 있는 node가 data 값이 가장 작은 node
		}

		root->data = node_ptr->data;
		root->right_child = delete(root->right_child, node_ptr->data);
	}
	return root;
}

void initFlag() { // flag값 0으로 초기화

	flag = 0;
}
