#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, j, x, temp, staticSize;
	int *length;
	scanf("%d", &staticSize);
	
	length = (int*)malloc(sizeof(int)*staticSize);
	
	for(i = 0; i < staticSize; i++){
		scanf("%d", &length[i]);
	}
	
	for(i = 0; i < staticSize-1; i++){
		for(j = 1; j < staticSize-i; j++){
			if(length[j-1] > length[j]){
				temp = length[j-1];
				length[j-1] = length[j];
				length[j] = temp;
			}
		}
	}
	
	for(i = 0; i < staticSize; i++)
		printf("%d ", length[i]);
}