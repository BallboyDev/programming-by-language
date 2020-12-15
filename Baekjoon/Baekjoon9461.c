#include <stdio.h>

int Padovan(int n){
	//if(n <= 5)
	//	printf("%d ", n);
	if(n == 1 || n == 2 || n == 3) {printf("1 "); return 1;}
	else if(n == 4 || n == 5) {printf("2 "); return 2;}
	else if(n < 1) return 0;
	else return Padovan(n-1) + Padovan(n-5);
}

int main(){
	int num, i, n;
	
	scanf("%d", &num);
	// num =1;
	for(i = 0; i < num; i++){
		scanf("%d", &n);
		printf("\n%d\n\n", Padovan(n));
	}
}