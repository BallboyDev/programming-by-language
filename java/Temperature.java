import java.util.Scanner;

public class Temperature{
	public static void main(String[] argc){
		Scanner scanner = new Scanner(System.in);
		double c;
		double f;
		
		System.out.print("ȭ�� �µ��� �Է��Ͻÿ� : ");
		f = scanner.nextDouble();
		
		c = (f - 32) * 5 / 9;
		// why not? ����
		// c = (5 / 9 * (f - 32));
		
		System.out.println(f);
		System.out.print("������ �µ��� : " + c);
	}
}