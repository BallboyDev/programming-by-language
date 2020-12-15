#include <stdio.h>

int main(){
	int i, num = 1;
	char word[1000000];
	
	gets(word);
	
	for(i = 0; word[i] != NULL; i++){
		if(word[i] == ' ') num++;
	}
	
	printf("%d", num);
}