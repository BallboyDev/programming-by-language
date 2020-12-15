#include <stdio.h>

int main(){
	int p[9][9];
	int i, j, num = 0, tmpj, tmpi;
	
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			scanf("%d", &p[i][j]);
			if(p[i][j] > num){
				num = p[i][j];
				tmpi = i;
				tmpj = j;
			}
		}
	}
	
	printf("%d\n", num);
	printf("%d %d", tmpi+1, tmpj+1);
}