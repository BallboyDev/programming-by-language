#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

int main(){
	int i, j, x, temp;
	char c;
	int length[MAX];
	clock_t start, finish;
	double duration;
	FILE* in;
	
	in = fopen("rand.txt", "r");
	for(i = 0; i < MAX; i++){
		fscanf(in, "%d", &length[i]);
		printf("%d ", length[i]);
	}
	
	printf("\nstart sort(y/n)? ");
	scanf("%c", &c);
	if(c == "n" || c == "N"){
		exit(1);
		printf("finish");
	}
	
	start = clock();
	
	for(i = 0; i < MAX-1; i++){
		for(j = 1; j < MAX-i; j++){
			//printf("%d ", j);
			if(length[j-1] > length[j]){
				temp = length[j-1];
				length[j-1] = length[j];
				length[j] = temp;
			}
		}
	}
	
	for(i = 0; i < MAX; i++)
		printf("(%d, %d)\n", i+1, length[i]);
	

	finish = clock();
	
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\n time = %f", duration);
	
	fclose(in);
}