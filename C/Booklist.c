/*============================================
파일이름 : Booklist.c
함수기능 : 이중 연결리스트를 활용한 도서 관리 프로그램
최종수정 : 
기타설명 : 배동기 선배님의 과제
copyright ⓒ 2013 S.W.Yang All Rights Reserved
============================================*/

#include <stdio.h>

typedef struct List{
	struct List *llink;
	struct Data *data;
	struct List *rlink;
} List;

typedef struct booktype{
	char book[30];		// 책이름
	char author[15];	// 저자
	char publisher[10];	// 출판사
	char prics[10];		// 가격
	char year[5];		// 발행년도
} Data;

int err = 0;

void error(){	// 실행 중 에러 확인 용도, error();
	printf("실행 %d\n", err);
	err++;
}

void insert(){
	
}

void list(){
	
}

void quit(){
	
}

void create(){
	
}

int main(){
	int num, i;
	char c;
	
	while(1){
		printf("1. insert\n2. list\n3. quit\n");
		printf("Select Manu : ");
		scanf("%d", &num);
		
		
		switch(num){
			case 1:		// 도서 추가
				insert();
				break;
			case 2:		// 도서 검색
				list();
				break;
			case 3:		// 프로그램 종료
				printf("프로그램을 종료 하시겠습니까? : (Y/N)");
				scanf(" %c", &c);
				if(c == 'y' || c == 'Y')
					quit();
				break;
		}
	}
}