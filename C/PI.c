#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	float pi, count = 0;
	int x, y, i, num;
	
	scanf("%d", &num);
	
	srand(time(NULL));
	for(i = 0; i < num; i++){
		x = rand() % 100000;
		y = rand() % 100000;
		if((x*x)+(y*y) < 100000*100000)
			count++;
	}
	
	printf("%f", count/num*4);
	
	//printf("%f", pi);
}