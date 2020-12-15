#include <stdio.h>

int main(){
	int a, b;
	long long result;
	
	// printf("%d", sizeof(result));
	
	scanf("%d %d", &a, &b);
	
	result = (a + b) * (b - a + 1) / 2;
	
	printf("%d", result);
}