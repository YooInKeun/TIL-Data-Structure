#include <stdio.h>

typedef struct treeNode{ // Tree ����ü

	int data;
	struct treeNode* leftChild;
	struct treeNode* rightChild;

}treeNode;

treeNode* root = NULL; // Root Node�� ���� ������ ����

void initTree(int data); // Tree �ʱ�ȭ(Root Node ����)
treeNode* addChild(treeNode* parrent, char pos, int data); // Child Node ����

int main() {

	initTree(1);

	addChild(root, 'L', 2);
	addChild(root, 'R', 3);

	return 0;
}

void initTree(int data) { // Tree �ʱ�ȭ(Root Node ����)

	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));

	root = newNode;
	root->data = data;
	root->leftChild = NULL;
	root->rightChild = NULL;
}

treeNode* addChild(treeNode *parrent, char pos, int data) { // Child Node ����

	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));

	newNode->data = data;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	if (pos == 'L') {

		if (parrent->leftChild != NULL) {
			
			printf("leftChild�� �̹� �����մϴ�\n");
			free(newNode); // �̹� Node�� �����ϸ� �����Ҵ��ߴ� newNode free

			return 0;
		}

		parrent->leftChild = newNode;
	}

	else if (pos == 'R') {

		if (parrent->rightChild != NULL) {

			printf("rightChild�� �̹� �����մϴ�\n");
			free(newNode);

			return 0;
		}

		parrent->rightChild = newNode;
	}
}