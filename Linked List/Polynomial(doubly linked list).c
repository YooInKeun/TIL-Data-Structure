#include <stdio.h>
#include <stdlib.h>

typedef struct polyNode { // Polynomial Node 구현

	float coef;
	int exp;
	struct polyNode* nextLink;
	struct polyNode* prevLink;

}polyNode;

polyNode* creatNode(float coef, int exp); // Node 생성
void addNode(polyNode** head, polyNode* newNode); // Node 추가
void printList(polyNode** head); // Linked List 출력

int main() {

	polyNode* A = NULL;
	polyNode* B = NULL;

	// A = 3x^2 - 5x^1 + 6

	addNode(&A, creatNode(3, 2));
	addNode(&A, creatNode(-5, 1));
	addNode(&A, creatNode(6, 0));

	printf("A : ");
	printList(&A);
	printf("\n");

	// B = -7x^3 + 3x^2 - 5

	addNode(&B, creatNode(-7, 3));
	addNode(&B, creatNode(3, 2));
	addNode(&B, creatNode(-5, 0));

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

void addNode(polyNode** head, polyNode* newNode) { // Node 추가

	if (*head == NULL) { // List에 Node가 없으면 head가 첫 번째 newNode를 가리킴

		*head = newNode;
	}

	else { // List에 Node가 있으면

		polyNode* tail = *head;

		while (tail->nextLink != NULL) { // head가 가리키는 첫 번째 Node부터 순차적으로 탐색해서 마지막 Node 발견 시

			tail = tail->nextLink;
		}

		tail->nextLink = newNode; // 마지막 Node의 nextLink는 추가된 Node를 가리킴
		newNode->nextLink = NULL; // 새로 추가된 Node의 nextLink는 NULL 값
		newNode->prevLink = tail; // 새로 추가된 Node의 prevLink는 이전의 마지막 Node를 가리킴
	}
}

void printList(polyNode** head) { // Linked List 출력

	polyNode* current = *head;
	float myCoef; // 계수의 부호를 판별
	int myExp;

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