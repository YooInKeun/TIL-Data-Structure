#include <stdio.h>

typedef struct treeNode{ // Tree 구조체

	int data;
	struct treeNode* leftChild;
	struct treeNode* rightChild;

}treeNode;

treeNode* root = NULL; // Root Node는 전역 변수로 설정

void initTree(int data); // Tree 초기화(Root Node 생성)
treeNode* addChild(treeNode* parrent, char pos, int data); // Child Node 생성

int main() {

	initTree(1);

	addChild(root, 'L', 2);
	addChild(root, 'R', 3);

	return 0;
}

void initTree(int data) { // Tree 초기화(Root Node 생성)

	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));

	root = newNode;
	root->data = data;
	root->leftChild = NULL;
	root->rightChild = NULL;
}

treeNode* addChild(treeNode *parrent, char pos, int data) { // Child Node 생성

	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));

	newNode->data = data;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	if (pos == 'L') {

		if (parrent->leftChild != NULL) {
			
			printf("leftChild가 이미 존재합니다\n");
			free(newNode); // 이미 Node가 존재하면 동적할당했던 newNode free

			return 0;
		}

		parrent->leftChild = newNode;
	}

	else if (pos == 'R') {

		if (parrent->rightChild != NULL) {

			printf("rightChild가 이미 존재합니다\n");
			free(newNode);

			return 0;
		}

		parrent->rightChild = newNode;
	}
}