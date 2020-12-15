#include <stdio.h>

#define MAX 200000

int array[MAX];

int main(){
	int i, num = 0;
	FILE* stream1;
	FILE* stream2;
	// int input = 0;

	stream1 = fopen("level6.txt", "r");
	stream2 = fopen("data2.txt", "w");
	
	for(i = 0;;i++){
		fscanf(stream1, "%x", &num);
		if(num == 0xFFF) break;
		if(i % 11 == 0) continue;
		printf("%x %d\n", num, i);
		fprintf(stream2, "%02x ", num);
	}
	
	fclose(stream1);
	fclose(stream2);
}