#include <stdio.h>

int main(){
	int** p;
	int length, i, j;
	
	scanf("%d", &length);
	
	p = (int**)malloc(sizeof(int)*length);
	*p = (int*)malloc(sizeof(int)*length);
	
	for(i = 0; i < length; i++){
		for(j = 0; j < length; j++){
			scanf("%d", &p[i][j]);
		}
	}
	
	for(i = 0; i < length; i++){
		for (j = 0; j < length; j++){
			printf("%d", p[i][j]);
		}
		printf("\n");
	}
}