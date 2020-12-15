#include <stdio.h>
#include <string.h>

int main(){
	char word[81], find[81], ch[81], result[81], word2[81];
	int length, length2, length3;
	char *p;
	char *q;
	char *ptr;
	
	printf("문자열을 입력하세요 : "); // 문자열
	gets(word);
	
	printf("찾을 문자열 : "); // 찾을 문자열
	gets(find);
	
	p = strstr(word, find); // 시작 위치
	length = strlen(find); // 바꿀 문자열 길이
	q = p + length; // 끝나는 위치
	printf("%d %d %d\n", p, q, length);
	
	printf("바꿀 문자열 : "); // 바꿀 문자열
	gets(ch);
	
	length2 = p - word;
	strncpy(result, word, length2);
	result[length2] = '\0';
	strcat(result, ch);
	
	printf("결과 : "); // 결과 문자열
	printf("%s", result);
}