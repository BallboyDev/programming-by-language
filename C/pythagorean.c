#include <stdio.h>

int main(){
	int x, y, z, i;
	
	printf("범위 임력 : ");
	scanf("%d", &i);
	for(x = 1; x <= i; x++){
		for(y = 1; y <= i; y++){
			for(z = 1; z <= i; z++){
				if(x*x + y*y == z*z)
					printf("(%d, %d, %d)\n", x, y, z);
				
			}
		}
	}
}