#include <stdio.h>

// int chk(){}

int main(){
	char p[101];
	int n, i, j;
	
	scanf("%d ", &n);
	
	for(i = 0; i < n; i++){
		gets(p);
		
		for(j = 0; p[j] != '\0'; j++){
			printf("%c ", p[j]);
		}
		printf("\n");
	}
}