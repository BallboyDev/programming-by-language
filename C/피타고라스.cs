using System;

class Math
{
	public static int Main()
	{
		string str;
		long m=3, n=1;
		long k, i, a, b, c, x;
		Console.Write("범위를 지정하세오 : ");
		str=Console.ReadLine();
		k=Convert.ToInt32(str);
		
		Console.WriteLine("a b c");
		while(m<k){
			while(n<m){
				for(i=2;i<n;i++){
					if(m*m%n*n==0)
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
					Console.WriteLine("{0} {1} {2}", x*a, x*b, x*c);
				}
				n=n+2;
			}
			m=m+2;
			n=1;
		}
		
		Console.ReadLine();
		return 0;
	}
}