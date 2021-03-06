#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

typedef struct polyNode { // Polynomial Node 구현

	float coef;
	int exp;
	struct polyNode* nextLink;
	struct polyNode* prevLink;

}polyNode;

polyNode* createNode(float coef, int exp); // Node 생성
void insertNode(polyNode** firstNode, polyNode* newNode); // Node 삽입(항의 Exponent 값에 맞게 알맞은 위치에 삽입)
void printList(polyNode** firstNode); // Linked List 출력

polyNode* Addition(polyNode** poly1, polyNode** poly2); // 두 개의 Polynomial의 합
polyNode* Multiplication(polyNode** poly1, polyNode** poly2); // 두 개의 Polynomial의 곱
float Evaluation(polyNode** poly, int x); // x 값이 주어질 때, Polynomial 계산하기

int main() {

	polyNode* A = NULL;
	polyNode* B = NULL;
	polyNode* C = NULL;

	polyNode* D = NULL; // D = A + B
	polyNode* E = NULL; // E = A + C
	polyNode* F = NULL; // F = B + C

	polyNode* G = NULL; // G = A * B
	polyNode* H = NULL; // H = A * C
	polyNode* I = NULL; // I = B * C

	int x;
	float result;

	insertNode(&A, createNode(5, 3));
	insertNode(&A, createNode(-1, 1));
	insertNode(&A, createNode(2, 4));
	insertNode(&A, createNode(-5, 4));
	insertNode(&A, createNode(6, 0));

	printf("A = ");
	printList(&A);

	insertNode(&B, createNode(-1, 3));
	insertNode(&B, createNode(6, 1));
	insertNode(&B, createNode(5, 0));
	insertNode(&B, createNode(-3, 2));

	printf("B = ");
	printList(&B);

	insertNode(&C, createNode(1, 4));
	insertNode(&C, createNode(2, 5));
	insertNode(&C, createNode(5, 1));
	insertNode(&C, createNode(-2, 2));
	insertNode(&C, createNode(6, 1));

	printf("C = ");
	printList(&C);

	D = Addition(&A, &B);

	printf("D(= A + B) = ");
	printList(&D);

	E = Addition(&A, &C);

	printf("E(= A + C) = ");
	printList(&E);

	F = Addition(&B, &C);

	printf("F(= B + C) = ");
	printList(&F);
	
	G = Multiplication(&A, &B);

	printf("G(= A * B) = ");
	printList(&G);

	H = Multiplication(&A, &C);

	printf("H(= A * C) = ");
	printList(&H);

	I = Multiplication(&B, &C);
	
	printf("I(= B * C) = ");
	printList(&I);
	
	printf("대입할 정수 x 값을 입력하세요 : ");
	scanf_s("%d", &x);
	printf("\n");
	printf("Evaluation of Polynomials with given a value %d", x);
	printf("\n\n");
	result = Evaluation(&A, x);
	printf("Result of A = %.2f", result);
	printf("\n");

	result = Evaluation(&B, x);
	printf("Result of B = %.2f", result);
	printf("\n");

	result = Evaluation(&C, x);
	printf("Result of C = %.2f", result);
	printf("\n");

	result = Evaluation(&D, x);
	printf("Result of D = %.2f", result);
	printf("\n");

	result = Evaluation(&F, x);
	printf("Result of F = %.2f", result);
	printf("\n");

	result = Evaluation(&I, x);
	printf("Result of I = %.2f", result);
	printf("\n");

	printf("\n");
	
	return 0;
}

polyNode* createNode(float coef, int exp) { // Node 생성

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

		/*

		< Case 4가지 >

		List에 newNode의 Exponent와 동일한 Node가 존재하지 않을 때

		[Case 1] newNode가 맨 앞에 insert 되는 경우
		[Case 2] newNode가 중간에 insert 되는 경우
		[Case 3] newNode가 맨 뒤에 insert 되는 경우

		List에 newNode의 Exponent와 동일한 Node가 존재할 때

		[Case 4] insert 하는 경우, 기존의 항을 기존의 항과 newNode의 합으로 저장

		(insert 삽입을 진행하고, 보다 깔끔한 식을 위해 차수가 같은 항끼리는 더하기 진행)

		*/

		int myCase = 1; // newNode가 맨 앞에 insert 되는 경우

		while (nodePtr->exp >= newNode->exp) { // nodePtr이 가리키는 Node의 Exponent 값과 newNode의 Exponent 값 비교

			if (nodePtr->nextLink != NULL) { // nodePtr의 nextLink가 NULL이 아니면

				if (nodePtr->exp == newNode->exp) { // Exponenent 값이  같을 경우

					myCase = 4; // Case 4
					break;
				}

				else { // Exponenent 값이  같지 않고, newNode가 중간에 insert 되는 경우

					nodePtr = nodePtr->nextLink;
					myCase = 2; // Case 2
				}
			}

			else if (nodePtr->nextLink == NULL) { // nodePtr의 nextLink가 NULL이면, newNode가 맨 뒤에 insert 되는 경우

				if (nodePtr->exp == newNode->exp) { // Exponenent 값이  같을 경우

					myCase = 4; // Case 4
					break;
				}

				myCase = 3; // Case 3
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

		else if (myCase == 3) { // newNode가 마지막에 insert

			nodePtr->nextLink = newNode;
			newNode->prevLink = nodePtr;
		}

		else if (myCase == 4) { // 기존의 항을 기존의 항과 newNode의 합으로 저장

			nodePtr->coef += newNode->coef;
			free(newNode); // newNode 메모리 해제
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

			else if (current->nextLink->coef < 0) { // 만약 다음 항의 부호가 - 면, + 기호를 출력할 필요가 없음

				printf(" ");
			}
		}

		current = current->nextLink;
	}

	printf("\n\n");
}

polyNode* Addition(polyNode** poly1, polyNode** poly2) { // 두 개의 Polynomial의 합

	polyNode* nodePtr1 = *poly1;
	polyNode* nodePtr2 = *poly2;

	polyNode* myList = NULL; // poly1과 poly2의 합을 담을 List
	int myCase;

	while (!(nodePtr1 == NULL || nodePtr2 == NULL)) { // nodePtr1과 nodePtr2 둘 중에 하나라도 NULL이 될 때까지 더하기 진행

		if (nodePtr1->exp > nodePtr2->exp) {

			insertNode(&myList, createNode(nodePtr1->coef, nodePtr1->exp));
			nodePtr1 = nodePtr1->nextLink;
		}

		else if (nodePtr1->exp == nodePtr2->exp) {

			insertNode(&myList, createNode(nodePtr1->coef + nodePtr2->coef, nodePtr1->exp));
			nodePtr1 = nodePtr1->nextLink;
			nodePtr2 = nodePtr2->nextLink;
		}

		else if (nodePtr1->exp < nodePtr2->exp) {

			insertNode(&myList, createNode(nodePtr2->coef, nodePtr2->exp));
			nodePtr2 = nodePtr2->nextLink;
		}

		/*

		< Case 2가지 >

		[Case 1] 다항식 poly1의 차수가 다항식 poly2의 차수보다 클 때
		[Case 2] 다항식 poly2의 차수가 다항식 poly1의 차수보다 클 때

		*/

		if (nodePtr1 == NULL) {

			myCase = 1;
		}

		else if (nodePtr2 == NULL) {

			myCase = 2;
		}

		else {

			myCase = 3;
		}
	}

	if (myCase == 1) {

		while (nodePtr2 != NULL) {

			insertNode(&myList, createNode(nodePtr2->coef, nodePtr2->exp));
			nodePtr2 = nodePtr2->nextLink;
		}
	}

	else if (myCase == 2) {

		while (nodePtr1 != NULL) {

			insertNode(&myList, createNode(nodePtr1->coef, nodePtr1->exp));
			nodePtr1 = nodePtr1->nextLink;
		}
	}

	return myList;
}

polyNode* Multiplication(polyNode** poly1, polyNode** poly2) { // 두 개의 Polynomial의 곱

	polyNode* nodePtr1 = *poly1;
	polyNode* nodePtr2 = *poly2;

	polyNode* myList = NULL; // poly1과 poly2의 곱을 담을 List

	while (nodePtr1 != NULL) { // poly1의 첫 항을 시작으로 poly2의 각각의 항과 곱하기

		while (nodePtr2 != NULL) { // poly2가 NULL이 될 때까지, 즉 poly2를 모두 탐색할 때까지

			insertNode(&myList, createNode(nodePtr1->coef * nodePtr2->coef, nodePtr1->exp + nodePtr2->exp)); // insertNode 함수에 같은 항끼리 더해주는 기능이 있음
			nodePtr2 = nodePtr2->nextLink;
		}

		nodePtr1 = nodePtr1->nextLink;
		nodePtr2 = *poly2; // poly1의 다음 항과 곱하기 연산을 또 해야하기 때문에, nodePtr2를 poly2로 초기화
	}

	return myList;
}

float Evaluation(polyNode** poly, int x) { // x 값이 주어질 때, Polynomial 계산하기

	float result = 0;

	polyNode* nodePtr = *poly;

	while (nodePtr != NULL) {

		result = result + (nodePtr->coef)*pow(x, nodePtr->exp);
		nodePtr = nodePtr->nextLink;
	}

	return result;
}
