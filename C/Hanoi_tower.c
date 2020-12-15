#include <stdio.h>

int c = 0;
void hanoi_tower(int n, char from, char tmp, char to){
	c++;
	if(n == 1) printf("%d : circle 1 : %c -> %c\n",c, from, to);
	else{
		hanoi_tower(n-1, from, to, tmp);
		printf("%d : circle %d : %c -> %c\n",c, n, from, to);
		hanoi_tower(n-1, tmp, from, to);
	}
}

int main(){
	int num;
	scanf("%d", &num);
	hanoi_tower(num, 'A', 'B', 'C');
}