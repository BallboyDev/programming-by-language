import java.util.Scanner;

public class Add2{
	public static void main(String[] args){
		
		Scanner scanner = new Scanner(System.in);
		
		int x, y, sum;
		
		System.out.print("ù ��° ���ڸ� �Է��Ͻÿ� : ");
		x = scanner.nextInt();
		
		System.out.print("�� ��° ���ڸ� �Է��Ͻÿ� : ");
		y = scanner.nextInt();
		
		sum = x + y;
		
		System.out.println(sum);
	}
}