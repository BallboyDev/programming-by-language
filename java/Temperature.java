import java.util.Scanner;

public class Temperature{
	public static void main(String[] argc){
		Scanner scanner = new Scanner(System.in);
		double c;
		double f;
		
		System.out.print("화씨 온도를 입력하시오 : ");
		f = scanner.nextDouble();
		
		c = (f - 32) * 5 / 9;
		// why not? ↓↓↓
		// c = (5 / 9 * (f - 32));
		
		System.out.println(f);
		System.out.print("섭씨의 온도는 : " + c);
	}
}