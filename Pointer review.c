#include <stdio.h>

int main() {

	// �������� �⺻ ���� ����

	int a = 1, b = 2;
	int* p;

	p = &a;

	printf("p�� ��(= a�� �ּ�) : %d\n", p);
	printf("p�� ����Ű�� �ִ� ��(= a�� ��) : %d\n", *p);

	a = 3;

	printf("p�� ����Ű�� �ִ� ��(= ����� a�� ��) : %d\n", *p);

	b = *p;

	printf("b�� ��(= p�� ����Ű�� �ִ� ��) : %d\n", b);

	return 0;
}