#include <stdio.h>

int main(){
	int* p;
	int length, i, j, num, sum;
	
	char word[80];
	
	scanf("%d", &length);
	
	p = (int*)malloc(sizeof(int)*length);
	
	for(i = 0; i < length; i++){
		num = 0; sum = 0;
		gets(word);
		for(j = 0; ;j++){
			if(word[j] == NULL) break;
			if(word[j] == 'X') continue;
			if(word[j] == 'O'){ 
				num++;
				sum = sum + num;
			}
		}
		p[i] = sum;
	}
	
	for(i = 0; i < length; i++){
		printf("%d\n", p[i]);
	}
}