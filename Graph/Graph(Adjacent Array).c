#include <stdio.h>

#define MAX_SIZE 10

int Graph[MAX_SIZE][MAX_SIZE] = {0, };

void printGraph();
void connectEdge();

int main() {

	printGraph();
	connectEdge();
	printGraph();

	return 0;
}

void printGraph() {

	for (int i = 0; i < MAX_SIZE; i++) {

		for (int j = 0; j < MAX_SIZE; j++) {

			printf("%d ", Graph[i][j]);
		}
		printf("\n");
	}
}

void connectEdge() {

	int v1 = 0, v2 = 0;

	while (v1 != -1) {

		printf("연결할 Vertex를 입력하세요 : \n");

		scanf_s("%d %d", &v1, &v2);

		Graph[v1][v2] = 1;
		Graph[v2][v1] = 1;
	}
}