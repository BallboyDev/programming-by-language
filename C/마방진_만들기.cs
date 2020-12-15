using System;

class Mabj
{
	public static int Main()
	{
		int n, k, a, b, x, y;
		int[,] l = new int [100,100];
		
		Console.Write("마방진 크기 입력 (홀수만 입력 가능합니다.) : ");
		n = Convert.ToInt32(Console.ReadLine());
		
		a=n;
		b=(n+1)/2;
		l[a,b]=1;
		
		for(k=2;k<=n*n;k++){
			if(a==n&&b==n)
				a=a-1;
			
			else if(k%n==1)
				a=a-1;
			
			else if(a==n){
				a=1;
				b=b+1;
			}
			
			else if(b==n){
				a=a+1;
				b=1;
			}
			
			else{
				a++;
				b++;
			}
			
			l[a,b]=k;
		}
		
		for(x=1;x<=n;x++){
			Console.WriteLine("");
			for(y=1;y<=n;y++){
				Console.Write("{0:D4} ", l[x,y]);
			}
		}
		
		Console.Read();
		return 0;
	}
}