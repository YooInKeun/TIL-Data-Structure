#include <stdio.h>
#include <stdlib.h>

typedef struct _node{ // node 구조체
	int data;
	struct _node* next;
}node;

typedef node* nptr; // node 포인터 별칭 : nptr

typedef struct _list{ // list 구조체
	int count;
	nptr head;
}list;

// typedef로 별칭을 지어줘야, 별칭을 통해 외부에서 변수나 구조체 선언이 가능한 것 같다 

void init(list* lptr); // 리스트 초기화
void insert(list* lptr, int val, int pos); // 리스트 삽입
void delete(list* lptr, int pos); // 리스트 삭제
int search(list* lptr, int val); // 리스트 검색
void modify(list* lptr, int val, int pos); // 리스트 수정
void print_list(list* lptr); // 리스트 출력

int main() {

	return 0;
}