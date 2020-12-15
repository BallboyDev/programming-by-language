#include <stdio.h>

int main(){
	int a, b, c, num, result, i;
	int temp[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	scanf("%d %d %d", &a, &b, &c);
	
	num = a*b*c;
	
	while(1){
		if(num == 0) break;
		temp[num%10]++;
		num = num / 10;
	}
	
	for(i = 0; i < 10; i++){
		printf("%d\n", temp[i]);
	}
}