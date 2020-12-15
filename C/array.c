#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 200000

int array[MAX_LIST_SIZE];

void error(){
	int tt;
	for(tt = 0; tt < 20; tt++){
		printf("%d ", array[tt]);
	}
	printf("\n");
}

void find(){
	int num, i, sum = 0;
	printf("찾을 원소를 입력하세요 : ");
	scanf("%d", &num);
	for(i = 0;; i++){
		if(num == array[i]) {printf("%d 번째 원소 입니다.\n", i); sum++;}
		if(array[i] == 0) break;
	}
	if(sum == 0) printf("찾는 원소가 없습니다.");
}

void insert(){
	int num1, num2, lim, i;
	
	printf("원소 추가 위치를 선택하세요\n");
	printf("\t1. 배열 맨앞\n\t2. 배열 맨뒤\n\t3. 원소 추가 위치 사용자 지정\n\t4. 원소 다중 입력\n\t메뉴 선택 : ");
	scanf("%d", &num1);
	switch(num1){
		case 1:
			for(i = 9999; i > 0; i--){
				array[i] = array[i-1];
			}
			scanf("%d", &array[0]);
			break;
		case 2:
			for(i = 0;;i++){
				if(array[i] == 0){
					scanf("%d", &array[i]);
					break;
				}
			}
			break;
		case 3:
			printf("추가위치 : ");
			scanf("%d", &num2);
			for(i = 9999; i > num2; i--){
				array[i] = array[i - 1];
			}
			scanf("%d", &array[num2]);
			break;
		case 4:	
			printf("추가위치 : ");
			scanf("%d", &num2);
			printf("입력할 원소 개수 : ");
			scanf("%d", &lim);
			for(i = 9999; i >= num2+lim; i--){
				array[i] = array[i - lim];
			}
			for(i = num2; i < num2+lim; i++){
				scanf("%d", &array[i]);
			}
			break;
	}
}

void delete(){
	int num1, num2, num3, temp, i, j;
	
	printf("원소 삭제 위치를 선택하세요\n");
	printf("\t1. 배열 맨앞\n\t2. 배열 맨뒤\n\t3. 원소 추가 위치 사용자 지정\n\t4. 원소 다중 삭제\n\t5. 특정원소 삭제\n\t메뉴 선택 : ");
	scanf("%d", &num1);
	switch(num1){
		case 1:
			for(i = 1;; i++){
				array[0] = array[1];
				if(array[i] == 0){
					array[i-1] = 0;
					break;
				}
			}
			break;
		case 2:
			for(i = 0;; i++){
				if(array[i] == 0){
					array[i-1] = 0;
					break;
				}
			}
			break;
		case 3:
			printf("위치 지정 : ");
			scanf("%d", &num2);
			for(i = num2;; i++){
				array[i] = array[i+1];
				if(array[i] == 0) break;
			}
			break;
		case 4:
			printf("삭제할 범위(시작위치 종료위치) : ");
			scanf("%d %d", &num2, &num3);
			temp = num3 - num2;
			for(i = num3; i < 9999; i++){
				array[i - temp] = array[i + 1];
			}
			break;
		case 5:
			temp = 0;
			printf("리스트에서 삭제할 원소 : ");
			scanf("%d", &num2);
			for(i = 0;; i++){
				if(array[i] == 0) break;
				else if(array[i] == num2){
					for(j = i;; j++){
						array[j] = array[j+1];
						if(array[j] == 0) break;
					}
					temp++;
					printf("%d번째 원소를 삭제했습니다.\n", i);
				}
			}
			if(temp == 0) printf("삭제할 원소가 없습니다.\n");
			else printf("%d개의 원소를 삭제했습니다.\n", temp);
	}
}

void print(){
	int i;
	for(i = 0 ;; i++){
		if(array[i] == 0) break;
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(){
	
	int num, i;
	
	for(i = 0; i < 10; i++){
		array[i] = i + 1;
	}
	
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
				print();
				break;
			case 5:
				exit(1);
				break;
		}	
	}
}