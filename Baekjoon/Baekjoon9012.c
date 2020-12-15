#include <stdio.h>
 
int main(){
    int* p;
    int n, i, j;
    int in, out;
    char word[51];
     
    scanf("%d ", &n);
     
    p = (int*)malloc(sizeof(int)*n);
     
    for(i = 0; i < n; i++){
        in = 0; out = 0;
        gets(word);
        for(j = 0; word[j] != NULL; j++){
            if(word[j] == '(') in++;
            else out++;
        }
        if(in == out) p[i] = 0;
        else p[i] = 1;
		
		if(word[0] == ')' && word[j] == '(') p[i] = 1;
				
        //puts(word);
    }
	
	/*for(i = 0; i < n; i++)
		printf("%d", p[i]);
	printf("\n");*/
     
    for(i = 0; i < n; i++){
        if(p[i] == 0) printf("YES\n");
        else printf("NO\n");
    }
}