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
	printf("�� ������ rand()�Լ��� �̿��Ͽ� ���� %d���� �����ϴ� �����Դϴ�.\n", MAX) ; 

	for ( index = 0 ; index < MAX ; index++ ) 
		fprintf(out, "%d ", rand()%100000);
	fclose(out);
	return 0 ; 
}