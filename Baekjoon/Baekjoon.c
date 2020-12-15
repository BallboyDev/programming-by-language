#include <stdio.h>

int main(){
	char word[100][100];
	int i;
	
	for(i = 0; i < 5; i++){
		gets(word[i]);
		if(word[i][1] == NULL) break;
	}
	
	for(i = 0; i < 5; i++){
		puts(word[i]);
	}
}	