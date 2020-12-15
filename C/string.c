#include <stdio.h>
#define MAX 100

int main(){
	int i;
	char array[MAX];
	
	printf("input string  : ");
	gets(array);
	
	/* 입력된 문자열을(대문자 -> 소문자, 소문자 -> 대문자)변환하는 부분 */
	for(i = 0; array[i] != '\0'; i++){
		if(array[i] >= 'A' && array[i] <= 'Z')	// 대문자를 소문자로 변환
			array[i] = array[i] + 32;
		
		else if(array[i] >= 'a' && array[i] <= 'z')	// 소문자를 대문자로 변환
			array[i] = array[i] - 32;
	}
	
	printf("output string : %s", array);
}