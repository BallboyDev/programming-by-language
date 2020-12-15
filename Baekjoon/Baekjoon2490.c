#include <stdio.h>

int main(){
	char word[5] = {'D', 'C', 'B', 'A', 'E'};
	int p[3];
	int i, num, a, b, c, d;
	
	for(i = 0; i < 3; i++){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		p[i] = a+b+c+d;
	}
	
	for(i = 0; i < 3; i++){
		printf("%c\n", word[p[i]]);
	}
}