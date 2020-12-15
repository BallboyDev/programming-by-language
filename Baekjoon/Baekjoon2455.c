#include <stdio.h>

int main(){
	int in, out, total = 0, max = 0;
	int i;
	
	for(i = 0; i < 4; i++){
		scanf("%d %d", &out, &in);
		total = total + in - out;
		if(total > max) max = total;
	}
	
	printf("%d", max);
}