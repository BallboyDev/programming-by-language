#include <stdio.h>

int main(){
	int i, j, num;
	int array[10][6] = {0, };
	
	while(1){
		for(i = 0; i < 10; i++){
			scanf("%d", &num);
			if(num > 10){
				if(num > 100)
					array[i][(num/100) - 1]++;
				array[i][((num%100)/10)-1]++;
				array[i][(num%10)-1]++;
			}
			else if(num < 0) break;
			else array[i][num-1]++;
		}
		
		for(i = 0; i < 10; i++){
			for(j = 0; j < 6; j++){
				printf("%2d ", array[i][j]);
			}
			printf("\n");
		}
		if(num < 0) break;
	}
	
	for(i = 0; i < 10; i++){
		for(j = 0; j < 6; j++){
			printf("%2d ", array[i][j]);
		}
		printf("\n");
	}
}