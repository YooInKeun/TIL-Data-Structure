#include <stdio.h>

int main() {

	// 배열도 포인터다! (배열의 이름은 그 배열의 시작 주소를 저장하는 포인터 변수)

	int sum, i;
	int num[10];

	for (i = 0; i < 10; i++) {

		scanf_s("%d", &num[i]);
	}

	sum = cal_sum(num); // 배열의 이름(시작 주소) 전달

	printf("합계 : %d", sum);

	return 0;
}

int cal_sum(int* arr) { 

	int sum = 0, i;

	for (i = 0; i < 10; i++) {

		sum += arr[i]; // sum += *(arr+i) 와 동일
	}

	return sum;
}