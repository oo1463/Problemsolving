package boj_3040_일곱난쟁이;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int arr[];
	static int save[];
	static int sum;
	static StringBuilder sb;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		sb = new StringBuilder();
		
		arr = new int[9];
		save = new int[7];
		
		for(int t=0; t<9; ++t) {
			st = new StringTokenizer(br.readLine());
			arr[t] = Integer.parseInt(st.nextToken());
		}
		
		find(0,0);
		
		System.out.println(sb.toString());
		br.close();
	}
	
	public static void find(int si, int cnt) {
		if(cnt >= 7) {
			int sum = 0;
			for(int i=0; i<7; i++) {
				sum += save[i];				
			}
			if(sum == 100) {
				for(int i=0; i<7; i++) {
					sb.append(save[i] + "\n");
				}
			}
			return;
		}
		
		for(int i=si; i<9; i++) {
			save[cnt] = arr[i];
			find(i+1, cnt+1);
		}
	}

}