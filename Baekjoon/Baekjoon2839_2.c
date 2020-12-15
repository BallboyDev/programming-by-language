#include <stdio.h>

int main(){
	int a, n = 0;
	scanf("%d", &a);
	
	while(1){
		if(a % 5 == 0){
			printf("%d", (a/5) + n);
			break;
		}
		
		else if(a == 1 || a == 2){
			printf("-1");
			break;
		}
		
		else{
			a = a - 3;
			n = n + 1;
		}
	}
}