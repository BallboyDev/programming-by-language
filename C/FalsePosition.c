#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (x*x*x - x - 1.344)

int main(){
	double a, b, xc, fa, fb, fc, epsilon;
	int imax, iter;
	/****** define ******
	a, b : 구간값
	imax : 최대 반복 횟수
	epsilon : 수렴 판단기준
	******* define ******/
	
	epsilon = 0.0001;
	imax = 1000;
	printf("left boundary : a = ");
	scanf("%lf", &a);
	printf("right boundary : b = ");
	scanf("%lf", &b);
	printf("a, b, epsilon, imax : %f %f %f %d\n", a, b, epsilon, imax);
	
	fa = F(a);	fb = F(b);
	
	if(fabs(fa) <= epsilon){
		printf("\na is value");
		exit(1);
	}
	
	if(fabs(fb) <= epsilon){
		printf("\nb is value");
		exit(1);
	}
	
	if(fa * fb > 0.0){
		printf("\nHere is not value in range");
		exit(1);
	}
	
	for(iter = 1; iter < imax; ++iter){
		xc = b - (F(b)*(a-b)/(F(a)-F(b)));
		fc = F(xc);
		printf("%d xc f(xc) : %f, %f\n", iter, xc, fc);
		
		if(fabs(fc) <= epsilon){
			printf("\nvalue xc = %f", xc);
			exit(0);
		}
		
		if(fa*fc < 0){
			b = xc;
			fb = fc;
		}
		
		else{
			a = xc;
			fa = fc;
		}
	}
	printf("Not converging");
}