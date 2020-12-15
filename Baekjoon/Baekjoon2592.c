#include <stdio.h>

int main(){
	int p[2][10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int n, i, j, sum = 0, max = 0;
	
	for(i = 0; i < 10; i++){
		scanf("%d", &p[0][i]);
		sum = sum + p[0][i];
	}
	
	for(i = 0; i < 10; i++){
		for(j = 0; j < i; j++){
			if(p[0][i] == p[0][j]) p[1][j]++;
		}
	}
	
	for(i = 0; i < 10; i++){
		if(p[1][i] > max) n = p[0][i];
	}
	//for(i = 0; i < 10; i++)
		//printf("%d ", p[1][i]);
	printf("%d\n%d", sum/10, n);
}