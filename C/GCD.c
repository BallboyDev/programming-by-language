#include <stdio.h>

int euclid(int a, int b){
	if(b == 0) return a;
	else return euclid(b, a%b);
}

int main(){
	int a, b;
	
	printf("a = ");
	scanf("%d", &a);
	
	printf("b = ");
	scanf("%d", &b);
	
	printf("result = %d", euclid(a, b));
}