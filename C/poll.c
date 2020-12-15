#include <stdio.h>
#include <time.h>
#include <windows.h>
int main(){
	int count = 1, value;
	
	scanf("%d", &value);
	
	while(1){
		if(value == 1){
			count = count +1;
			printf("%d\n", count);
		}
		sleep(1);
	}
}