#include <stdio.h>

int main(){
	int n, num, i, total = 1;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%d", &num);
		total = total - 1 + num;
	}
	
	printf("%d", total);
}