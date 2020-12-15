#include <stdio.h>

int main(){
	int num, i, max = 0, max_i;
	
	for(i = 1; i <= 9; i++){
		scanf("%d", &num);
		if(num > max) {max = num; max_i = i;}
	}
	
	printf("%d\n%d", max, max_i);
}