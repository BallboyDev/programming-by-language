#include <stdio.h>

int main(){
	int e = 1, s = 1, m = 1;
	int et, st, mt, result = 1;
	
	scanf("%d %d %d", &et, &st, &mt);
	
	while(1){
		if(e == 16) e = 1;
		if(s == 29) s = 1;
		if(m == 20) m = 1;
		
		if(e == et && s == st && m == mt){
			printf("%d", result);
			break;
		}
		
		e++;
		s++;
		m++;
		
		result++;
	}
}