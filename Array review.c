#include <stdio.h>

int main() {

	// �迭�� �����ʹ�! (�迭�� �̸��� �� �迭�� ���� �ּҸ� �����ϴ� ������ ����)

	int sum, i;
	int num[10];

	for (i = 0; i < 10; i++) {

		scanf_s("%d", &num[i]);
	}

	sum = cal_sum(num); // �迭�� �̸�(���� �ּ�) ����

	printf("�հ� : %d", sum);

	return 0;
}

int cal_sum(int* arr) { 

	int sum = 0, i;

	for (i = 0; i < 10; i++) {

		sum += arr[i]; // sum += *(arr+i) �� ����
	}

	return sum;
}