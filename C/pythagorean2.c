#include <stdio.h>

int main(){
	int x, y, z, i;
	
	printf("범위 입력 : ");
	scanf("%d", &i);
	
	for(x = 2; x <= i; x++){
		for(y = x; y <= i; y++){
			for(z = 2; z <= i; z++){
				if(x*x + y*y == z*z)
					printf("(%d, %d, %d)\n", x, y, z);
			}
		}
	}
}