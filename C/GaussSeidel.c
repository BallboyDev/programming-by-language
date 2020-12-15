#include <stdio.h>
#include <math.h>

#define nd 20

double x[nd], x0[nd], a[nd][nd], b[nd];
int imax = 1000, n, iter;
double epsilon = 0.00001, resavg;

void GaussSeidel(){
	double ahat[nd][nd], bhat[nd], res[nd];
	double sum, ressum;
	int i, j;
	for(i = 1; i <= n; ++i){
		for(j = 1; j <=n; ++j)
			ahat[i][j] = a[i][j] / a[i][i];
		bhat[i] = b[i] / a[i][i];
		ahat[i][i] = 0.;
	}
	
	/* �ݺ� �����Ͽ� ����Ѵ�. */
	for(iter = 1; iter <= imax; ++iter){
		for(i = 1; i <= n; ++i){
			x[i] = bhat[i];
			for(j = 1; j <= n; ++j)
				x[i] = x[i] - ahat[i][j] * x0[j];
			x0[i] = x[i];
		}
		
		/* ���� �Ǵ��� �Ѵ�. */
		ressum = 0;
		for(i = 1; i <= n; ++i){
			sum = x[i] - bhat[i];
			for(j = 1; j <= n; ++j)
				sum = sum + ahat[i][j] * x[j];
			res[i] = fabs(sum);
			ressum = ressum + res[i];
		}
		
		resavg = ressum / n;
		if(resavg < epsilon) goto END;
		
		//for(i = 1; i <= n; ++i)
		//	x0[i] = x[i];
	}
	printf("\n �������� �ʴ´�. ");
	END:;
}

/* main program */
void main(){
	int i, j;
	
	/*data �Է� - ȭ�鿡�� */
	printf(" \n ������ �� n = ");
	scanf("%d", &n);
	printf("������ a(i, j)�� �Է��Ͻÿ� \n");
	for(i = 1; i <= n; i = i+1){
		printf("a(%d, j) j = 1,,,n = ", i);
		for(j = 1; j <= n; j = j+1) scanf("%lf", &a[i][j]);
	}
	
	printf("������ b[i]�� �Է��Ͻÿ�\n");
	printf("b[i] i = 1,,,n = ");
	for(i = 1; i <= n; i=i+1) scanf("%lf", &b[i]);
	
	printf("������ x0[i]�� �Է��Ͻÿ�\n");
	printf("x0[i] i = 1,,,n = ");
	for(i = 1; i <= n; i=i+1) scanf("%lf", &x0[i]);
	
	/* data ��� */
	printf("\n Input data��� ");
	for(i = 1; i <= n; i = i+1){
		printf("\n");
		for(j = 1; j <= n; j=j+1)
			printf("%10.5f", a[i][j]);
		printf("%10.5f", b[i]);
	}
	
	/* data �Է� �� ��� �Ϸ� */
	printf("\n");
	GaussSeidel();
	
	/*��� ��� - n �� Ŭ ���� ��� ����� �����Ͽ��� �� */
	printf("\n ��� ��� ��� ");
	printf("\n iter = %d, ��� residual = %f", iter, resavg);
	for(i = 1; i <= n; i = i + 1)
		printf("\n x(%d) = %10.6f", i, x[i]);
}