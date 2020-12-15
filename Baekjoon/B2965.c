#include <stdio.h>

int main(){
	int a, b, c;
	int result;
	
	while(scanf("%d %d %d", &a, &b, &c) != EOF){
		if((b - a) > (c - b))
			result = b - a;
		else
			result = c - b;
		
		printf("%d\n", result - 1);
	}
}