#include <stdio.h>
#include <stdlib.h>

int main(){
	int* p;
	int length, i, tmp, num = 1;
	
	scanf("%d", &length);
	
	p = (int*)malloc(sizeof(int)*length);
	
	for(i = 0; i < length; i++){
		scanf("%d", &p[i]);
	}
	
	tmp = p[0];
	
	for(i = 0; i < length; i++){
		if(p[i] > tmp) {
			num++;
			tmp = p[i];
		}
	}
	
	printf("%d", num);
}