#include <stdio.h>

int num0 = 0, num1 = 0;

int fibonacci(int n){
	if(n==0){
		//printf("0 ");
		num0++;
		return 0;
	} else if(n==1){
		//printf("1 ");
		num1++;
		return 1;
	} else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int main(){
	int* p;
	int length, num, temp, i;
	
	scanf("%d", &length);
	
	p = (int*)malloc(sizeof(int)*length);
	for(i = 0; i < length; i++){
		scanf("%d", &p[i]);
	}
	
	for(i = 0; i < length; i++){
		temp = fibonacci(p[i]);
		printf("%d %d\n", num0, num1);
		num0 = 0; num1 = 0;
	}
}