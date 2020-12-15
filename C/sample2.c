#include <stdio.h>

int main(){
	int q = 15;
	int* adrs;
	adrs = 0x9fd000;
	
	printf("value of q %d\n", q);
	printf("address of q %x\n", &q);
	
	printf("value of p %d\n", &adrs);
}