#include <stdio.h>

int main(){
	int i, j, num, temp;
	long int sum = 0;
	int* p;
	int length;
	
	scanf("%d", &length);
	p = (int*)malloc(sizeof(int)*length);
	
	for(i = 0; i < length; i++){
		scanf("%d", &num);
		p[i] = num;
	}
	for(i = 0; i < length-1; i++){
		for(j = i+1; j < length; j++){
			// if(p[i] != p[j]){  //혹시 같은수 중복은 제외하는가 해서 넣어 봤습니다.
				temp = p[i]*p[j];
				// printf("%d\n", temp);	// 출력결과가 어떻게 되는지 확인차 넣었습니다.
				sum = sum + temp;
			// }
		}
	}
	
	printf("%d", sum);
}