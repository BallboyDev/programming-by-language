#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
	char order[128];
	char temp[20] = "..\\bin\\gcc -o ";
	if(argc == 1){
		printf("###--- make by S.W Yang ---###\n");
		system("..\\bin\\gcc");
	}
	
	else if(!(strcmp(argv[1], "-v")))
		system("..\\bin\\gcc -v");
	
	else{
		sprintf(order, "..\\bin\\gcc -o %s %s.c", strtok(argv[1], "."), argv[1]);
		system(order);
	}
}

// gcc -o test test.c
// qwer test.c