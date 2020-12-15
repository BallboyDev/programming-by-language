using System;

class math2
{
	public static int Main()
	{
		string str;
		int i, k, x, n;
		
		Console.Write("범위를 지정하시오 : ");
		str=Console.ReadLine();
		i=Convert.ToInt32(str);
		
		int[] array = new int[i];
		
		for(k=0;k<i;k++){
			array[k]=k+1;
		}
		
		for(n=1;n<k;n++){
			for(x=n+1;x<k;x++){
				if(array[n]==-1){
					break;
				}
				
				if(array[x]%array[n]==0){
					array[x]=-1;
				}
			}
		}
		for(k=0;k<i;k++){
			if(array[k]!=-1){
				Console.Write("{0} ", array[k]);
			}
		}
		Console.ReadLine();
		return 0;
	}
}