#include <stdio.h>

int main(){
	int i, count = 0;
	char p[101];
	
	gets(p);
	for(i = 0; p[i] != NULL;i++){
		if(p[i] == 'a' || p[i] == 'e' || p[i] == 'i' || p[i] == 'o' || p[i] == 'u')
			count++;
	}
	
	printf("%d", count);
}