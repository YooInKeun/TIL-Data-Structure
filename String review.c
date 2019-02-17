#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int read_line(char str[], int limit);

int main() {

	// ���ڿ� �Է� �� ���

	char buffer[BUFFER_SIZE];
	int k;

	while (1) {

		printf("���ڿ� �Է� : ");

		k = read_line(buffer, BUFFER_SIZE); // ���ڿ� �д� �Լ� ����(fgets�� �Ѱ��� ����)

		/* fgets(buffer, BUFFER_SIZE, stdin); // gets()�� �޸�, ���ڿ��� ���� ����(����)
		buffer[strlen(buffer) - 1] = '\0'; // fgets�� �������� \n�� �����ϹǷ�, \0���� �ٲ� */

		//gets(buffer); // ���ڿ��� ���̸� �������� �ʾ� �������� ����

		//scanf_s("%s", buffer); // ���ڿ��� �̸��� �� ���ڿ��� ���� �ּҸ� �����ϴ� ������ ����(�迭�� �����ʹ�!)

		//printf("���ڿ� ��� : %s, ���ڿ� ���� : %d\n", buffer, strlen(buffer));

		printf("���ڿ� ��� : %s, ���ڿ� ���� : %d\n", buffer, k);
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