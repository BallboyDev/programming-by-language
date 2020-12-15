#include <stdio.h>
#include <math.h>

#define nd 5

double xd[nd] = {2, 3, 4, 5, 6};
double yd[nd] = {4.8, 9.4, 19.2, 36.6, 58};
double Lagrange(double x){
	double p, sum;
	int i, j, n;
	n = nd - 1;
	sum = 0;
	for(i = 0; i <= n; i++){
		p = 1;
		for(j = 0; j <= n; j++){
			if(i != j)
				p = p * (x - xd[j])/(xd[i] - xd[j]);
		}
		// printf("%f\n", p * yd[i]);
		sum = sum + p * yd[i];
	}
	return sum;
}

void main(){
	double x = 2.5, y;
	y = Lagrange(x);
	printf("\n x = %f : fx = %f", x, y);
	x = 3.5;
	y = Lagrange(x);
	printf("\n x = %f : fx = %f", x, y);
}