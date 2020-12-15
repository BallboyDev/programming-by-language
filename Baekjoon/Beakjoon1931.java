package Baekjoon;

import java.util.Arrays;
import java.util.Scanner;

class Meeting implements Comparable<Meeting>{
	private int start;
	private int end;
	
	public void setStart(int start){
		this.start = start;
	}
	
	public void setEnd(int end){
		this.end = end;
	}
	
	public int getStart(){
		return this.start;
	}
	
	public int getEnd(){
		return this.end;
	}
	
	//public int toString() {return 0;}
	
	
	@Override
	public int compareTo(Meeting m) {
		if(end < m.end)
			return -1;
		else if(end > m.end)
			return 1;
		else {
			if(start < m.start) return -1;
			else if(start > m.start) return 1;
			else return 0;
		}
	}
}

public class Beakjoon1931{
	public static void main(String []args){
		Scanner scanner = new Scanner(System.in);
		
		int k = scanner.nextInt();
		
		Meeting[] m = new Meeting[k];
		
		for(int i = 0; i < m.length; i++){
			m[i] = new Meeting();
			m[i].setStart(scanner.nextInt());
			m[i].setEnd(scanner.nextInt());
		}
		
		//for(int i = 0; i < k; i++)
		//	System.out.println(m[i].getStart() + ", " + m[i].getEnd());
		
		Arrays.sort(m);
		
		//for(int i = 0; i < k; i++)
		//	System.out.println(m[i].getStart() + ", " + m[i].getEnd());
		
		int count = 0, end = 0;
		
		for(int i = 0; i < m.length; i++) {
			if(m[i].getStart() >= end) {
				// System.out.println(count + " " + m[i].getEnd() + " " + end);
				end = m[i].getEnd();
				
				count++;
			}
		}
		System.out.println(count);

	}
}