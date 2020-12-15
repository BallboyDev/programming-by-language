#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

void insert(ListNode** list){
	ListNode *new;
	int num = 2;		// 임시
	
	switch(num){
		case 1: // 리스트 맨앞
			new = create();
			new->link = list;
			*list = new;
			break;
		case 2: // 리스트 맨뒤
			break;
		case 3: // 리스트 중간
			break;
	}
}

void delete(){}

void print(){}

void find  							// 다시 생각해보기 insert에서 리스트 연결이 아닌 create에서 연결하는 걸로 그러면 create함수를 리턴 할 필요도 없어 지고 자료 관리도 편해진다.

ListNode *create(){
	ListNode *new;
	new = (ListNode*)malloc(sizeof(ListNode));
	// new->data = 5;
	new->link = NULL;
	return (new);
}

int main(){
	int num, i;
	ListNode *list1 = NULL;
	
	while(1){
		printf("======================\n");
		printf("1. 원소 검색\n2. 원소 추가\n3. 원소 삭제\n4. 배열원소 출력\n5. 종료\n");
		printf("======================\n");
		printf("메뉴를 선택하세요 : ");
		scanf("%d", &num);
		
		switch(num){
			case 1:
				break;
			case 2:
				inselt(&list1);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
		}
	}
}