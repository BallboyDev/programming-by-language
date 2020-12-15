import java.util.Scanner;

class Date{
	int year;
	int month;
	int day;
	void print1(){
		System.out.printf("%d.%d.%d\n", year, month, day);
	}
	void print2(){
		System.out.println(monthChange() + day + "," + year);
	}
		
	String monthChange(){
		String[] Mon = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		
		return Mon[month];
	}
}

public class Main{
	public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
		Date date = new Date();
		
		System.out.print("Year : ");
		date.year = scanner.nextInt();
		System.out.print("Month : ");
		date.month = scanner.nextInt();
		System.out.print("day : ");
		date.day = scanner.nextInt();
		
		date.print1();
		date.print2();
	}
}
		
		