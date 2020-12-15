using System;

class star{
    public static int Main(){
        int i, n, m, x;
        
        n=Convert.ToInt32(Console.ReadLine());
        
        for(i=n;i>=0;i--){
            for(m=0;m<n-i;m++){
                Console.Write(" ");
            }
            for(x=1;x<=i;x++){
                Console.Write("*");
            }
            Console.WriteLine();
        }
        return 0;
    }
}