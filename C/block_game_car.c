#include <stdio.h>

int mycar[4][3] = {{'��','��','��'},
					{'��','��','��'},
					{'��','��','��'},
					{'��','��','��'}};

void map_print(){
	int i, j;
	
	for(i = 0; i < 4; i++){
		for(j = 0; j < 3; j++){
			printf("%c", mycar[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int i, j;
	printf("�����");
	
	while(1)
		map_print();
}