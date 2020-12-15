#include <stdio.h>

int main(){
	int* p;
	int length, max = 0, sum = 0, i;
	float result;
	
	scanf("%d", &length);
	
	p = (int*)malloc(sizeof(int)*length);
	
	for(i = 0; i < length; i++){
		scanf("%d", &p[i]);
		if(p[i] > max) max = p[i];
		sum = sum + p[i];
	}
	
	result = (float)sum/max*100/3;
	printf("%.2f", result);
	scanf("%d", &max)
}