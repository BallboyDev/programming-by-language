#include <stdio.h>

int main(){
	int i, n, temp;
	char name[30];
	int alpha[26] = {0,};
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%s", name);
		alpha[name[0]-'a']++;
	}
	
	n = 0;
	
	for(i = 0; i < 26; i++){
		if(alpha[i] >= 5){
			printf("%c", i+'a');
			n++;
		}
	}
	if(n == 0) printf("PREDAJA");
}