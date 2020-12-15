#include <stdio.h>
int main()
{
	long m=3, n=1;
	long k, i, a, b, c, x;
	scanf("%d", &k);

	while(m<k){
		while(n<m){
			for(i=2;i<n;i++){
				if(m*m%i*i==0)
					break;
			}
			a=m*n;
			b=(m*m-n*n)/2;
			c=(m*m+n*n)/2;
			if(m*m%i*i==0)
				break;
			
			for(x=1;x<k;x++){
				if(x*c>k)
					break;
				printf("(%d %d %d)", x*a, x*b, x*c);
			}
			n=n+2;
		}
		m=m+2;
		n=1;
	}
}