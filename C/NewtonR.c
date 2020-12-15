#include <stdio.h>
#include <math.h>

#define e 2.718281//82846;


double f(double x, double n){
	if(n == 1)
		return (exp(-x)-4*x);				// 원래의 함수
	else
		return (-exp(-x)-4);	// 원래 함수의 미분함수
}
	
int main(){
	double x, fx, epsilon;
	int i, imax;
	
	epsilon = 0.0001; imax = 4;
	
	printf("input value : ");	// 초깃 값 입력
	scanf("%lf", &x);
	
	for(i = 0; i < imax; i++){
		fx = f(x, 1);
		
		
		if(fabs(fx) <= epsilon){		// 수렴하였을 경우 근을
			printf("x = %f\n", x);		// 출력하고 프로그램 종료
			return 0;
		}
		x = x - fx/f(x, 0);
		printf("x, f(x) : %lf, %lf\n", x, fx);
	}
	printf("Not Converging");	// imax 동안 수렴하지 않음
}