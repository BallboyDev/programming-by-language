#include <stdio.h>

int main(){
	int num, i, v, e;
		
	scanf("%d", &num);
	
	for(i = 0; i < num; i++){
		scanf("%d %d", &v, &e);
		printf("%d\n", 2-v+e);
	}
}