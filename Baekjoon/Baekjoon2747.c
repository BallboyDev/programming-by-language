#include <stdio.h>

int fibonacci(int n);

int main(){
	int n, temp;
	scanf("%d", &n);
	
	temp = fibonacci(n);
	
	printf("%d", temp);
}

int fibonacci(int n) {
    if (n==0) {
        //printf("0 ");
        return 0;
    } else if (n==1) {
        //printf("1 ");
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}