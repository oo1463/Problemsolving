package boj_1244;

import java.util.Scanner;

public class Main {
	
	static int N;
	static int arr[];
	
	public static void maleSwitchChange(int stuNum) {
		for(int i=0; i<N; i++) {
			if((i+1) % stuNum == 0) {
				if(arr[i] == 0) arr[i] = 1;
				else arr[i] = 0;				
			}
		}
	}
	
	public static void femaleSwitchChange(int stuNum, int cnt) {
		
		if(stuNum-1-cnt >= 0 && stuNum-1+cnt < N) {
			if(arr[stuNum-1 - cnt] == arr[stuNum-1 + cnt]) {
				if(arr[stuNum-1 - cnt] == 0) arr[stuNum-1 - cnt] = 1;
				else arr[stuNum-1 - cnt] = 0;
				
				if(arr[stuNum-1 + cnt] == 0) arr[stuNum-1 + cnt] = 1;
				else arr[stuNum-1 + cnt] = 0;
				femaleSwitchChange(stuNum, cnt+1);
			}
		}
		
		return;
			
	}
	

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		arr = new int[N];
		
		for(int i=0; i<N; i++) {
			arr[i] = sc.nextInt();
		}
		
		int stu = sc.nextInt();
		
		while(stu-- > 0) {
			int gender = sc.nextInt();
			int stuNum = sc.nextInt();
			if(gender == 1) maleSwitchChange(stuNum);
			else {
				if(arr[stuNum-1 ] == 0) arr[stuNum-1] = 1;
				else arr[stuNum-1 ] = 0;
				femaleSwitchChange(stuNum, 1);
			}
			
		}
		
		for(int i=0; i<N; i++) {
			if(i != 0 && i%20 == 0) System.out.println();
			System.out.print(arr[i] + " ");
		}
		
	}

}
