#include <stdio.h>
#include <math.h>
//#define f(x) (x*exp(-x*x))
#define f(x) (0.2+(25*x)-(200*x*x)+(675*x*x*x)-(900*x*x*x*x)+(400*x*x*x*x*x))

void main(){
	double a, b, h, xi, T;
	int n, i;
	
	printf("±¸°£ ¼ö n : ");
	scanf("%d", &n);
	printf("\n a = ");
	scanf("%lf", &a);
	printf("\n b = ");
	scanf("%lf", &b);
	
	h = (b-a)/n;
	T = 0.5 * h * (f(a) + f(b));
	xi = a;
	for(i = 1; i <= n; i++){
		xi = xi + h;
		T = T + h * f(xi);
	}
	
	printf("\n T = %lf", T);
}