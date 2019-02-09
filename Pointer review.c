#include <stdio.h>

int main() {

	// 포인터의 기본 개념 복습

	int a = 1, b = 2;
	int* p;

	p = &a;

	printf("p의 값(= a의 주소) : %d\n", p);
	printf("p가 가리키고 있는 값(= a의 값) : %d\n", *p);

	a = 3;

	printf("p가 가리키고 있는 값(= 변경된 a의 값) : %d\n", *p);

	b = *p;

	printf("b의 값(= p가 가리키고 있는 값) : %d\n", b);

	return 0;
}