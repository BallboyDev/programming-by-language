#include <stdio.h>

int main(){
	int i, j, num;
	
	scanf("%d", &num);
	
	for(i = 0; i < num; i++){
		for(j = 0; j <= i; j++){
			printf("*");
		}
		for(j = (num - i - 1); j > 0; j = j - 1){
			printf("  ");
		}
		for(j = 0; j <= i; j++){
			printf("*");
		}
		printf("\n");
	}
	
	for(i = 0; i < num - 1; i ++){
		for(j = num - i - 1; j > 0; j--){
			printf("*");
		}
		for(j = 0; j <= i; j++){
			printf("  ");
		}
		for(j = num - i - 1; j > 0; j--){
			printf("*");
		}
		printf("\n");
	}
}