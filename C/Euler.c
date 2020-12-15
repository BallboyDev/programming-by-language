#include <stdio.h>
#include <math.h>
#define f(x, y) ((4*exp(0.8*x))-(0.5*y))
#define nd 1000

void main(){
	double x0, y0, h;
	double x[nd], y[nd];
	int n, i;
	
	printf("\n x0, y0, h = ");
	scanf("%lf %lf %lf", &x0, &y0, &h);
	printf("\n n = ");
	scanf("%d", &n);
	printf("\n i	 x(i)	 y(i)");
	x[0] = x0; y[0] = y0;
	
	for(i = 1; i <= n; i++){
		x[i] = x[i-1] + h;
		y[i] = y[i-1] + h * f(x[i-1], y[i-1]);
	}
	
	for(i = 1; i <= n; i++)
		printf("\n %d \t%f \t%f", i, x[i], y[i]);
}