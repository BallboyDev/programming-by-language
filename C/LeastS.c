#include <stdio.h>
#include <math.h>
#define nd 20

void main(){
	double x[nd], Y[nd];
	double a0, a1;
	double sumx = 0, sumY = 0, sumx2 = 0, sumxY = 0;
	int n, i;
	printf("������ �� n : ");
	scanf("%d", &n);
	printf("x(i)�� �Է��Ͻÿ�\n");
	printf("x(i)  i=1, ...n");
	for(i = 1; i <= n; i++) scanf("%lf", &x[i]);
	printf("Y(i)�� �Է��Ͻÿ�\n");
	printf("Y(i)  i=1, ...n");
	for(i = 1; i <= n; i++) scanf("%lf", &Y[i]);
	
	for(i = 1; i <= n; i++){
		sumxY = x[i] * Y[i] + sumxY;
		sumx = x[i] + sumx;
		sumY = Y[i] + sumY;
		sumx2 = pow(x[i], 2) + sumx2;
		a1 = ((n*sumxY) - (sumx*sumY)) / ((n*sumx2) - pow(sumx, 2));
		a0 = (sumY/n) - (a1 * sumx/n);
	}
	
	printf("\n y = %lf X+%lf \n", a1, a0);
}