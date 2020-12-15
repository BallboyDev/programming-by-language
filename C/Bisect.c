#include <stdio.h>
#include <math.h>

#define funct(x) (x*x*x - 2 * sin(x))

/*double funct(int x){
	double result;
	result = x*x*x - 2 * sin(x);
	return result;
}*/

void main(){
	double a, b, xc, fa, fb, fc, epsilon;
	int imax, iter;
	
	/* Data 입력 및 출력 */
	epsilon = 0.0001;
	imax = 1000;
	printf("\nleft boundary : a = ");
	scanf("%lf", &a);
	printf("\nright boundary : b = ");
	scanf("%lf", &b);
	printf("\na, b, epsilon, imax : %f %f %f %d", a, b, epsilon, imax);
	
	/* Data 입력 및 출력 완료 */
	printf("\n");
	
	/* 해가 존재하는지 확인 */
	fa = funct(a);
	fb = funct(b);
	
	if(fabs(fa) <= epsilon){
		printf("\na is value");
		goto END;
	}
	
	if(fabs(fb) <= epsilon){
		printf("\nb is value");
		goto END;
	}
	
	if(fa * fb > 0.0){
		printf("\nHere is not value in range");
		goto END;
	}
	
	/* 계산 시작 */
	for(iter = 1; iter < imax; ++iter){
		xc = (a + b) / 2.0;
		fc = funct(xc);
		printf("\n%d xc f(xc) : %f, %f", iter, xc, fc);
		if(fabs(fc) <= epsilon){
			printf("\nvalue xc = %f", xc);
			goto END;
		}
		
		if(fa * fc < 0.0){
			b = xc;
			fb = fc;
		}
		
		else{
			a = xc;
			fa = fc;
		}
	}
	printf("Not converging");
	END:;
}