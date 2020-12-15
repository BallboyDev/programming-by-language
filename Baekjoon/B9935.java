import java.util.Scanner;

public class B9935{
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		
		String a = s.next();
		String b = s.next();
		
		while(true){
			if(!a.contains(b)){
				//System.out.println("test1");
				break;
			}
			else{
				//System.out.println("test2");
				a = a.replace(b, "");
			}
		}
		
		if(a.length() == 0)
			System.out.println("FRULA");
		else
			System.out.println(a);
	}
}