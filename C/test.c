#include <stdio.h>

int t(int n){
	if(n == 1)
		return 1;
	else
		return (3 * t(n/4) + 3 * n);
}

int main(){
	int num, result;
	
	printf("n = ");
	scanf("%d", &num);
	result = t(num);
	printf("result = %d", result);
}