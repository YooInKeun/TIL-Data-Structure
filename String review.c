#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int read_line(char str[], int limit);

int main() {

	// 문자열 입력 및 출력

	char buffer[BUFFER_SIZE];
	int k;

	while (1) {

		printf("문자열 입력 : ");

		k = read_line(buffer, BUFFER_SIZE); // 문자열 읽는 함수 구현(fgets의 한계점 보완)

		/* fgets(buffer, BUFFER_SIZE, stdin); // gets()와 달리, 문자열의 길이 제한(안전)
		buffer[strlen(buffer) - 1] = '\0'; // fgets는 마지막에 \n을 저장하므로, \0으로 바꿈 */

		//gets(buffer); // 문자열의 길이를 제한하지 않아 안전하지 않음

		//scanf_s("%s", buffer); // 문자열의 이름은 그 문자열의 시작 주소를 저장하는 포인터 변수(배열도 포인터다!)

		//printf("문자열 출력 : %s, 문자열 길이 : %d\n", buffer, strlen(buffer));

		printf("문자열 출력 : %s, 문자열 길이 : %d\n", buffer, k);
	}

	return 0;
}

int read_line(char str[], int limit) {

	int ch, i = 0;

	while ((ch = getchar()) != '\n') {
		if (i < limit) {
			str[i++] = ch;
		}
	}

	str[i] = '\0';

	return i;
}