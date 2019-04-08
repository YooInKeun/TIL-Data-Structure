#include <stdio.h>
#include <stdlib.h>

typedef struct polyNode { // Polynomial Node 구현

	float coef;
	int exp;
	struct polyNode* nextLink;
	struct polyNode* prevLink;

}polyNode;

polyNode* creatNode(float coef, int exp); // Node 생성
void insertNode(polyNode** firstNode, polyNode* newNode); // Node 삽입(항의 Exponent 값에 맞게 알맞은 위치에 삽입)
void printList(polyNode** firstNode); // Linked List 출력

int main() {

	polyNode* A = NULL;
	polyNode* B = NULL;

	insertNode(&A, creatNode(3, 2));
	insertNode(&A, creatNode(-5, 1));
	insertNode(&A, creatNode(6, 0));
	insertNode(&A, creatNode(5, 5));
	insertNode(&A, creatNode(-10, 4));
	insertNode(&A, creatNode(50, 0));
	insertNode(&A, creatNode(15, 5));

	printf("A : ");
	printList(&A);
	printf("\n");

	insertNode(&B, creatNode(-7, 3));
	insertNode(&B, creatNode(3, 1));
	insertNode(&B, creatNode(5, 3));
	insertNode(&B, creatNode(-5, 0));
	insertNode(&B, creatNode(10, 6));
	insertNode(&B, creatNode(3, 2));
	insertNode(&B, creatNode(-5, 0));
	insertNode(&B, creatNode(10, 5));
	insertNode(&B, creatNode(6, 2));

	printf("B : ");
	printList(&B);
	printf("\n");

	return 0;
}

polyNode* creatNode(float coef, int exp) { // Node 생성

	polyNode* newNode = (polyNode*)malloc(sizeof(polyNode)); // Node 동적할당

	newNode->coef = coef;
	newNode->exp = exp;
	newNode->nextLink = NULL;
	newNode->prevLink = NULL;

	return newNode;
}

void insertNode(polyNode** firstNode, polyNode* newNode) { // Node 삽입(항의 Exponent 값에 맞게 알맞은 위치에 삽입)

	if (*firstNode == NULL) { // List에 Node가 없으면 firstNode가 첫 번째 newNode를 가리킴

		*firstNode = newNode;
	}

	else { // List에 Node가 있으면

		polyNode* nodePtr = *firstNode;

		// Case 3가지
		// 1. newNode가 맨 앞에 insert 되는 경우
		// 2. newNode가 중간에 insert 되는 경우
		// 3. newNode가 맨 뒤에 insert 되는 경우

		int myCase = 1; // newNode가 맨 앞에 insert 되는 경우

		while (nodePtr->exp > newNode->exp) { // nodePtr이 가리키는 Node의 Exponent 값과 newNode의 Exponent 값 비교

			if (nodePtr->nextLink != NULL) { // nodePtr의 nextLink가 NULL이 아니면, newNode가 중간에 insert 되는 경우

				nodePtr = nodePtr->nextLink;
				myCase = 2;
			}

			else { // nodePtr의 nextLink가 NULL이면, newNode가 맨 뒤에 insert 되는 경우

				myCase = 3;
				break;
			}
		}

		if (myCase == 1) { // newNode가 맨 앞에 insert

			*firstNode = newNode;
			newNode->nextLink = nodePtr;
			nodePtr->prevLink = newNode;
		}

		else if (myCase == 2) { // newNode가 중간에 insert

			newNode->nextLink = nodePtr;
			newNode->prevLink = nodePtr->prevLink;
			nodePtr->prevLink->nextLink = newNode;
			nodePtr->prevLink = newNode;
		}

		else if(myCase == 3) { // newNode가 마지막에 insert

			nodePtr->nextLink = newNode;
			newNode->prevLink = nodePtr;
		}
	}
}

void printList(polyNode** firstNode) { // Linked List 출력

	polyNode* current = *firstNode;
	float myCoef; // 계수의 부호를 판별
	int myExp; // 지수가 0인지 아닌지를 판별

	while (current != NULL) {

		myCoef = current->coef;
		myExp = current->exp;

		if (myCoef != 0) { // 계수가 0이 아니고

			if (myExp == 0) { // 지수가 0이면

				printf("%.2f", myCoef); // 계수 값만 출력(지수가 0이면 어차피 상수값이기 때문)
			}

			else { // 지수가 0이 아니면

				printf("%.2fx^%d", myCoef, myExp); // 계수와 지수 값 모두 출력
			}
		}

		if (current->nextLink != NULL) { // 예외 처리를 위해 조건문 추가(안써주면 런타임 에러 발생)

			if (current->nextLink->coef > 0) { // 만약 다음 항의 부호가 + 면, + 출력

				printf(" +");
			}

			else if (current->nextLink->coef < 0) { //  // 만약 다음 항의 부호가 - 면, + 기호를 출력할 필요가 없음

				printf(" ");
			}
		}

		current = current->nextLink;
	}

	printf("\n");
}
