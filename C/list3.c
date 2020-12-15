#include <stdio.h>

typedef struct List{
	int data;
	struct List *link;
} List;

List *slist = NULL; //시작 리스트

void error(){printf("실행된다\n");}

void create(List *list1){	//list1 = 생성된 리스트의 주소가 저장될 곳, list2 = 다음에 올 리스트 주소
	int num;
	
	List *plist;
	plist = (List*)malloc(sizeof(List));
	scanf("%d", &num);
	plist->data = num;
	plist->link = list1;
	list1 = plist;
}

void insert(){
	int num;
	List* plist;
	printf("원소 추가 위치를 선택하세요\n");
	// 1. 맨앞, 2. 맨뒤, 3. 중간(위치 선정)
	
	scanf("%d", &num);
	
	switch(num){
		case 1:
			create(slist);
			break;
			
		case 2:
			plist = &slist->link;
			error();
			while(1){
				error();
				if(&plist->link == NULL) {
					error();
					create(plist);
					break;
				}
				else {
					error();
					plist = &plist->link;
				}
			}
			break;
			
		case 3:
			break;
	}
}

void delete(){}

void find(){}

void print(List* list){
	List* plist = list;
	while(plist != NULL){
		printf("%d->", plist->data);
		plist = plist->link;
	}
	printf("\n");
}

int main(){
	int num, i;
	
	while(1){
		printf("======================\n");
		printf("1. 원소 검색\n2. 원소 추가\n3. 원소 삭제\n4. 배열원소 출력\n5. 종료\n");
		printf("======================\n");
		printf("메뉴를 선택하세요 : ");
		scanf("%d", &num);
		
		
		switch(num){
			case 1:
				find();
				break;
			case 2:
				insert();
				break;
			case 3:
				delete();
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