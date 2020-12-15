package Baekjoon;

import java.util.Arrays;
import java.util.Scanner;

public class Baekjoon11399 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int result = 0;
		
		int[] p = new int[n];
		
		for(int i = 0; i < n; i++) {
			p[i] = scanner.nextInt();
		}
		
		Arrays.sort(p);
		
		for(int i = 0; i < n; i++)
			result = result + p[i] * (n - i);
		System.out.println(result);
		
		scanner.close();

	}

}
