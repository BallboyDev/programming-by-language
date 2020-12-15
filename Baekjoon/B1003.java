import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		
		int order = s.nextInt();
		int num, temp, res = 1, mid = 1;
		
		for(int i = 0; i < order; i++){
			num = s.nextInt();
			for(int j = 2; j < num; j++){
				temp = res + mid;
				mid = res;
				res = temp;
			}
			
			if(num == 0)
				System.out.println("1 0");
			else if(num == 1)
				System.out.println("0 1");
			else
				System.out.println(mid + " " + res);
			res = 1;
			mid = 1;
		}
	}
}