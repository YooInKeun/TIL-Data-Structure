#include <stdio.h>

typedef int boolean; // c에서는 bool 타입이 없어서 typedef로 직접 구현
#define true 1
#define false 0

typedef struct node { // Tree Node

	int data; // node의 data
	struct node *right_child; // node의 right_child
	struct node *left_child; // node의 left_child

}node;

node* root = NULL; // Root Node는 전역 변수로 설정

void initTree(int data); // Tree 초기화(Root Node 생성)
boolean isEmpty(); // BST Empty인지 체크
void makeEmpty(); // BST가 Empty가 되도록 Clear
void inOrder(node *root); // Inoredr Traversal
void preOrder(node *root); // Preoredr Traversal
void postOrder(node *root); // Postoredr Traversal
boolean contains(int data); // BST에 Data가 존재하는지 체크
void put(int data); // BST에 Node Putting, 이미 같은 data값의 Node가 존재하면 아무일도 일어나지 않음
void delete(int data); // BST에서 특정 Data를 가진 Node 제거, 그 Data를 갖는 Node가 존재하지 않으면 아무일도 일어나지 않음

int main() {

	printf("%d\n", isEmpty(root));

	initTree(6);

	printf("%d\n", isEmpty(root));

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

	return 0;
}

void initTree(int data) { // Tree 초기화(Root Node 생성)

	node* newNode = (node*)malloc(sizeof(node));

	root = newNode;
	root->data = data;
	root->left_child = NULL;
	root->right_child = NULL;
}

boolean isEmpty() { // BST Empty인지 체크

	if (root == NULL)
		return true;

	else
		return false;
}

void makeEmpty() { // BST가 Empty가 되도록 Clear

}

void inOrder(node *root) { // Inoredr Traversal

	if (root != NULL) {

		inOrder(root->left_child);
		printf("%d ", root->data);
		inOrder(root->right_child);
	}
}

void preOrder(node *root) { // Preoredr Traversal

	if (root != NULL) {

		printf("%d ", root->data);
		preOrder(root->left_child);
		preOrder(root->right_child);
	}
}

void postOrder(node *root) { // Postoredr Traversal

	if (root != NULL) {

		postOrder(root->left_child);
		postOrder(root->right_child);
		printf("%d ", root->data);
	}
}

boolean contains(int data) { // BST에 Data가 존재하는지 체크

}

void put(node* root, int data) { // BST에 Node Putting, 이미 같은 data값의 Node가 존재하면 아무일도 일어나지 않음

	node* newNode = (node*)malloc(sizeof(node));

	newNode->data = data;

	int tmp;

	if (root->data > newNode->data) { // putting되는 node의 data가 root의 data보다 작을 때

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

	else if (root->data < newNode->data) { // putting되는 node의 data가 root의 data보다 클 때

		if (root->right_child != NULL) { // rightt_child가 존재하면, 다시 put함수 호출

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

void delete(int data) { // BST에서 특정 Data를 가진 Node 제거, 그 Data를 갖는 Node가 존재하지 않으면 아무일도 일어나지 않음

}