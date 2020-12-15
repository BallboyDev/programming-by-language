#include <stdio.h>

int main(){
	int n, i = 0;;
	
	scanf("%d", &n);
	
	while(n != 1){
		if((n-1)%3 == 0) n = n - 1;
		else if(n % 3 == 0) n = n / 3;
		else n = n / 2;
		i++;
	}
	
	printf("%d", i);
}