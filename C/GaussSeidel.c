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
	
	/* 반복 대입하여 계산한다. */
	for(iter = 1; iter <= imax; ++iter){
		for(i = 1; i <= n; ++i){
			x[i] = bhat[i];
			for(j = 1; j <= n; ++j)
				x[i] = x[i] - ahat[i][j] * x0[j];
			x0[i] = x[i];
		}
		
		/* 수렴 판단을 한다. */
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
	printf("\n 수렴하지 않는다. ");
	END:;
}

/* main program */
void main(){
	int i, j;
	
	/*data 입력 - 화면에서 */
	printf(" \n 방정식 수 n = ");
	scanf("%d", &n);
	printf("계수행렬 a(i, j)을 입력하시오 \n");
	for(i = 1; i <= n; i = i+1){
		printf("a(%d, j) j = 1,,,n = ", i);
		for(j = 1; j <= n; j = j+1) scanf("%lf", &a[i][j]);
	}
	
	printf("상수행렬 b[i]를 입력하시오\n");
	printf("b[i] i = 1,,,n = ");
	for(i = 1; i <= n; i=i+1) scanf("%lf", &b[i]);
	
	printf("가정값 x0[i]을 입력하시오\n");
	printf("x0[i] i = 1,,,n = ");
	for(i = 1; i <= n; i=i+1) scanf("%lf", &x0[i]);
	
	/* data 출력 */
	printf("\n Input data출력 ");
	for(i = 1; i <= n; i = i+1){
		printf("\n");
		for(j = 1; j <= n; j=j+1)
			printf("%10.5f", a[i][j]);
		printf("%10.5f", b[i]);
	}
	
	/* data 입력 및 출력 완료 */
	printf("\n");
	GaussSeidel();
	
	/*결과 출력 - n 이 클 때는 출력 양식을 변경하여야 함 */
	printf("\n 계산 결과 출력 ");
	printf("\n iter = %d, 평균 residual = %f", iter, resavg);
	for(i = 1; i <= n; i = i + 1)
		printf("\n x(%d) = %10.6f", i, x[i]);
}