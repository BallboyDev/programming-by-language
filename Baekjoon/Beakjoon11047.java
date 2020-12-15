package Baekjoon;

import java.util.Scanner;

public class Beakjoon11047 {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int result = 0;
		int n = scanner.nextInt();
		int k = scanner.nextInt();
		int[] a = new int[n];
		
		for(int i = 0; i < n; i++) {
			a[i] = scanner.nextInt();
		}
		
		for(int i = n-1; i >= 0; i--) {
			result = result +  k / a[i];
			k = k % a[i];
		}
		
		System.out.println(result);
		
		scanner.close();
	}
}
