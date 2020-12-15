#include <stdio.h>

void getChe(int min, int max) {
    int *arr;
	int i, j;
    arr = (int *)malloc(sizeof(int) * max);

    // 입력받은 수 만큼 배열에 모두 초기화 해둔다
    for (i = 2; i <= max; i++) {
        arr[i] = i;
		// printf("%d ", arr[i]);
    }
    
    for (i = 2; i <= max; i++) { 
        if (arr[i] == 0) // 이미 체크된 수의 배수는 확인하지 않는다
            continue;
        for (j = i + i; j <= max; j = j + i) { // i를 제외한 i의 배수들은 0으로 체크
            arr[j] = 0;
        }
    }

    // print
    for (i = min; i <= max; i++) {
        if (arr[i] != 0){
			// printf("error!!!\n");
            printf("%d\n", arr[i]);
		}
    }
	free(arr);
}

int main(){
	
	int m ,n;
	scanf("%d %d", &m, &n);
	// printf("error!!!\n");
	getChe(m, n);
	// printf("error###\n");
}