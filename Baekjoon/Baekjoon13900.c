#include <stdio.h>

int main(){
	int i, j, num, temp;
	long int sum = 0;
	int* p;
	int length;
	
	scanf("%d", &length);
	p = (int*)malloc(sizeof(int)*length);
	
	for(i = 0; i < length; i++){
		scanf("%d", &num);
		p[i] = num;
	}
	for(i = 0; i < length-1; i++){
		for(j = i+1; j < length; j++){
			// if(p[i] != p[j]){  //Ȥ�� ������ �ߺ��� �����ϴ°� �ؼ� �־� �ý��ϴ�.
				temp = p[i]*p[j];
				// printf("%d\n", temp);	// ��°���� ��� �Ǵ��� Ȯ���� �־����ϴ�.
				sum = sum + temp;
			// }
		}
	}
	
	printf("%d", sum);
}