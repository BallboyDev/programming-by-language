/*============================================
파일이름 : list4.c
함수기능 : c언어 단일 연결리스트의 구현
최종수정 : 2016-11-21 05:15
copyright ⓒ 2013 S.W.Yang All Rights Reserved
============================================*/

#include <stdio.h>
#include <stdlib.h>

typedef struct List{
	int data;
	struct List *link;
} List;

List* slist;

void error(){
	printf("실행\n");
}

void create(List **list){
	int num;
	
	scanf("%d", &num);
	
	List *plist;
	List *temp = NULL;

	plist = (List*)malloc(sizeof(List));
	
	plist->data = num;
	temp = *list;
	*list = plist;
	plist->link = temp;	
}

void Delete(List **list){
	List* rlist = *list;
	*list = (*list)->link;
	free(rlist);
}

void insert(){
	int num1, num2, i = 1;
	List* plist;
	plist = slist;

	printf("원소 추가 위치를 선택하세요\n");
	printf("\t1. 배열 맨앞\n\t2. 배열 맨뒤\n\t3. 원소 추가 위치 사용자 지정\n\t메뉴 선택 : ");
	scanf("%d", &num1);

	switch(num1){
	case 1:
		create(&slist);	//slist의 주소를 넘긴다.
		break;
	case 2:
		while(plist->link != NULL){
			plist=plist->link;
		}
		create(&plist->link);
		break;
	case 3:
		printf("추가위치 : ");
		scanf("%d", &num2);

		while(i < num2){
			plist = plist->link;
			i++;
		}
		create(&plist->link);
		break;
	}
}

void remove(){
	int num, num2, i = 1;
	List *plist = slist;

	printf("원소 삭제 위치를 선택하세요\n");
	printf("\t1. 배열 맨앞\n\t2. 배열 맨뒤\n\t3. 원소 추가 위치 사용자 지정\n\t메뉴 선택 : ");
	scanf("%d", &num);

	switch(num){
	case 1:
		Delete(&slist);
		break;
	case 2:
		while(plist->link->link != NULL){
			plist= plist->link;
		}

		Delete(&plist->link);
		plist->link = NULL;
		break;
	case 3:
		printf("삭제위치 : ");
		scanf("%d", &num2);

		while(i < num2){
			plist = plist->link;
			i++;
		}
		Delete(&plist->link);
		break;
	}
}

void homework(List* plist){
	int num1, num2, sum = 0, i = 1;

	printf("과제를 선택하세요\n");
	printf("\t1. 14번 문제\n\t2. 15번 문제\n\t3. 17번 문제\n\t메뉴 선택 : ");
	scanf("%d", &num1);

	switch(num1){
	case 1:
		printf("문제 : 리스트의 모든 데이터값을 더하시오\n");
		while(plist != NULL){
			sum = sum + plist->data;
			plist = plist->link;
		}
		printf("리스트의 모든 값의 합은 %d 입니다.\n", sum);
		break;
		
	case 2:
		printf("문제 : 리스트에 특정한 데이터값의 개수를 구하시오\n");
		printf("찾을 데이터 값 : ");
		scanf("%d", &num2);
		while(plist != NULL){
			if(plist->data == num2) sum++;
			plist = plist->link;
		}
		printf("특정한 데이터값을 가지는 노드의 수는 %d개 입니다.\n", sum);
		break;

	case 3:
		printf("문제 : 홀수 번째에 있는 노드를 모두 삭제하라\n");
		List* tlist = plist;
		plist = plist->link;
		slist = plist;
		free(tlist);
		error();
		for(;;){
			List* tlist = plist->link;
			if(tlist == NULL) break;
			error();
			plist->link = tlist->link;
			plist = tlist->link;
			if(plist == NULL) break;
			error();
			free(tlist);
			error();
		}
		break;
	}
}

void print(List *plist){
	while(plist != NULL){
		printf("%d -> ", plist->data);
		plist = plist->link;
	}
	printf("탐색이 종료 되었습니다.\n");
}

int main(){
	int num;
	char yes = NULL;
	FILE* list;
	
	while(1){
		printf("======================\n");
		printf("1. 과제 메뉴\n2. 원소 추가\n3. 원소 삭제\n4. 배열원소 출력\n5. 종료\n");
		printf("======================\n");
		printf("메뉴를 선택하세요 : ");
		scanf("%d", &num);
		
		
		switch(num){
			case 1:
				homework(slist);
				break;
			case 2:
				insert();
				break;
			case 3:
				remove();
				break;
			case 4:
				print(slist);
				break;
			case 5:		// 저장 기능 추가!!!!
				exit(1);
				break;
		}	
	}
}