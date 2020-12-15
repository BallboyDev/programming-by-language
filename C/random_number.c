#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 

#define MAX 100000

int main(void) 
{ 
	int index = 0 ;
	FILE *out;
	out = fopen("rand.txt", "w");

	srand(time(NULL)); 
	printf("이 예제는 rand()함수를 이용하여 난수 %d개를 생성하는 예제입니다.\n", MAX) ; 

	for ( index = 0 ; index < MAX ; index++ ) 
		fprintf(out, "%d ", rand()%100000);
	fclose(out);
	return 0 ; 
}