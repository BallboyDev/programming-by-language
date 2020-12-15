import java.util.Scanner;

public class B11880{
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		
		int a, b, c, result;
		int order = s.nextInt();
		
		for(int i = 0; i < order; i++){
			a = s.nextInt();
			b = s.nextInt();
			c = s.nextInt();
			
			if(a > b){
				if(b > c)
					result = (int)(Math.pow(b+c, 2) + Math.pow(a, 2));
					// a
				else if(a < c)
					result = (int)(Math.pow(a+b, 2) + Math.pow(c, 2));
					// c
				else
					result = (int)(Math.pow(b+c, 2) + Math.pow(a, 2));
					// a
			}
			else{
				if(a > c)
					result = (int)(Math.pow(a+c, 2) + Math.pow(b, 2));
					// b
				else if(b < c)
					result = (int)(Math.pow(a+b, 2) + Math.pow(c, 2));
					// c
				else
					result = (int)(Math.pow(a+c, 2) + Math.pow(b, 2));
					// b
			}
			System.out.println(result);
		}
	}
}