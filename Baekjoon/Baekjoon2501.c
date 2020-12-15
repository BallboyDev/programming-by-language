#include <stdio.h>

int main(){
	int n, k, i, num = 0;
	
	scanf("%d %d", &n, &k);
	
	for(i = 1; i < n; i++){
		if(n % i == 0) num++;
		if(num == k) break;
		if(i == n-1) {printf("0"); exit(0);}
	}
	
	printf("%d", i);
}