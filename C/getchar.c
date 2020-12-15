#include <stdio.h>

int main(){
	char c;
	int i, count = 0, count1 = 0;
	int array[10] = {0, };
	
	while((c = getchar()) != EOF){
		if(c >= '0' && c <= '9')
			array[c-48]++;
		else if(c == ' ' || c == '\n' || c == '\t')
			count++;
		else
			count1++;
	}
	printf("숫자 = ");
	for(i = 0; i < 10; i++)
		printf("%d", array[i]);
	
	printf("공백문자 = %d, 기타문자 = %d", count, count1);
	
	return 0;
}