#include <stdio.h>

int main(){
	static int p = 10;
	
	printf("value of p = %d\n", p);
	printf("address of p = %x\n", &p);
	
	system("pause");
}