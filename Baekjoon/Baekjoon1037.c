#include <stdio.h>

int main(){
	int* p;
	int n, i, num, max = 0, min = 1000000;
	
	scanf("%d", &n);
	p = (int*)malloc(sizeof(int)*n);
	
	for(i = 0; i < n; i++){
		scanf("%d", &p[i]);
		if(p[i] > max) max = p[i];
		if(p[i] < min) min = p[i];
	}
	
	printf("%d", min*max);
}