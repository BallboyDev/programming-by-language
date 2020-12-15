#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, j;
	int score, std, length, num;
	int *p;
	float aver;
	
	scanf("%d", &std);
	
	for(i = 0; i < std; i++){
		scanf("%d", &length);
		num = 0;
		score = 0;
		
		p = (int*)malloc(sizeof(int) * length);
		for(j = 0; j < length; j++){
			scanf("%d", &p[j]);
			
			score = score + p[j];
		}
		aver = (float)score / length;
		
		for(j = 0; j < length; j++){
			if(p[j] > aver)
				num++;
		}
		
		aver = (float)num / length * 100;
		printf("%.3f%%\n", aver);
		
		free(p);
	}
}