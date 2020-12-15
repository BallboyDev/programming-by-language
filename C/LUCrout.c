#include <stdio.h>
#include <math.h>

#define nd 20

double A[nd][nd], b[nd], L[nd][nd], U[nd][nd], x[nd], A_1[nd][nd];
int n;
void LuCrout();
void LuCrout_Sol();
void InvLU();

void main(){
	int i, j, select;
	
	printf("1. ������������ �� ���ϱ�\n2. ����� ���ϱ�\n");
	printf("����� �������ּ��� : ");
	scanf("%d", &select);
	
	
	printf("\n ������ �� n = ");
	scanf("%d", &n);
	printf("������ A(i, j)�� �Է��Ͻÿ�\n");
	for(i = 1; i <= n; i=i+1){
		printf(" A(%d, j); j = 1,,,,n = ", i);
		for(j = 1; j <= n; j = j + 1) scanf("%lf", &A[i][j]);
	}
	
	if(select == 1){
		printf("�ظ� �Է��Ͻÿ�\n");
		for(i = 1; i <= n; i++) scanf("%lf", &b[i]);
	}
	
	LuCrout();
	printf("\n [L] \n");	// �ϻﰢ ���
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++) printf("%f ", L[i][j]);
		printf("\n");
	}
	
	printf("\n [U] \n");	// ��ﰢ ���
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n ;j++) printf("%f ", U[i][j]);
		printf("\n");
	}
	
	printf("\n [b] \n");
	for(i = 1; i <= n; i++) printf("%f ", b[i]);
	printf("\n");
	
	
	if(select == 1) LuCrout_Sol();
	else if(select == 2) InvLU();
	
	if(select == 1){
		printf("\n [x] \n");
		for(i = 1; i <= n; i++) printf("%f ", x[i]);
		printf("\n");
	}
	
	if(select == 2){
		printf("\n [A'] \n");	// ��ﰢ ���
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n ;j++) printf("%f ", A_1[i][j]);
			printf("\n");
		}
	}
}

void LuCrout(){
	int i, j, k;
	double sum;
	for(i = 1; i <= n; i++) L[i][1] = A[i][1];
	for(j = 1 ; j <= n; j++) U[1][j] = A[1][j]/L[1][1];
	
	for(j = 2; j <= n; j++){
		for(i = j; i<= n; i++){
			sum = 0;
			for(k = 1; k <= j-1; k++) sum = sum +L[i][k]*U[k][j];
			L[i][j] = A[i][j] - sum;
		}
		
		U[j][j] = 1;
		for(i = j+1; i <= n; i++){
			sum = 0.0;
			for(k = 1; k <= j-1; k++) sum = sum + L[j][k]*U[k][i];
			U[j][i] = (A[j][i] - sum)/L[j][j];
		}
	}
}

void LuCrout_Sol(){
	int i, k;
	double temp;
	
	b[1] = b[1] / L[1][1];
	
	for(i = 2; i <= n; i++){
		temp = 0;
		for(k = 1; k <= i-1; k++)
			temp = temp + (L[i][k] * b[k]);
		b[i] = (b[i] - temp) / L[i][i];
	}
	
	x[n] = b[n];
	
	for(i = n-1; i >= 1; i--){
		temp = 0;
		for(k = i+1; k <= n; k++)
			temp = temp + (U[i][k] * x[k]);
		x[i] = b[i] - temp;
	}
}

void InvLU(){
	int i, j;
	for(i = 1; i <= n; i++){
		b[i] = 1;
		LuCrout_Sol();
		for(j = 1; j <= n; j++)
			A_1[j][i] = x[j];
		for(j = 1; j <= n; j++)
			b[j] = 0;
	}
}	