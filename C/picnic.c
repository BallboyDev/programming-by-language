#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>
/*
#define false 0
#define true 1
*/
typedef enum {false = 0, true = 1} bool;

int n;	// 학생수 
bool areFriends[10][10];	// 친구 관계를 가리키는 배열

int countPairings(bool taken[10]) {
	int firstFree = -1;
	int i, pairWith;
	for (i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1) return 1;
	int ret = 0;
	for (pairWith = firstFree+1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			// ret = ret + countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

int main(int argc, char *argv[]) {
	int n_cases, a, b, m, i;// 변수 선언
	int* p;
	bool taken[10];
	int answers[10];
	
	scanf("%d", &n_cases);	// 테스트 케이스의 수를 입력 받음 
	
	// 입력받은 테스트 케이스 수 만큼 짝짓기를 반복함 
	for (i = 0; i < n_cases; i++) {			
		// 초기화 
		for(a = 0; a < 10; a++)
			for(b = 0; b < 10; b++)
				areFriends[a][b] = false;
		
		for(a = 0; a < 10; a++)
			taken[a] = false;
		// 초기화 끝 
		
		// 학생 수와 짝의 수를 입력 받음
		scanf("%d %d", &n, &m);

		// 친구 정보를 한줄로 읽어들임 
		p = (int*)malloc(sizeof(int)*2*m);
		for(a = 0; a < 2*m; a++)
			scanf("%d", &p[a]);
				
		// 한줄로 읽어들인 친구 정보를 2차원 배열에 저장함 
		for(a = 0; a < 2*m; a += 2)
			areFriends[p[a]][p[a+1]] = true;
		
		// 테스트 케이스 i의 정답을 저장함 
		answers[i] = countPairings(taken);
	}
	
	// 모든 테스트 케이스의 계산 결과를 출력함 
	for (i = 0; i < n_cases; i++){
		printf("%d\n", answers[i]);
	}
	return 0;
}
