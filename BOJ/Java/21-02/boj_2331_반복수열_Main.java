package boj_2331_반복수열;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	
	static int P;
	
	public static int next(int a) {
		int sum = 0;
		while(a > 0) {
			sum += (int) Math.pow(a % 10 , P);
			a /= 10;
		}
		return sum;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		boolean visited[] = new boolean[300000];
		
		ArrayList<Integer> l = new ArrayList<>();
		
		int A = Integer.parseInt(st.nextToken());
		P = Integer.parseInt(st.nextToken());
		
		l.add(A);
		visited[A] = true;
		int next = next(A);
		
		while(true){
			if(visited[next]) {
				int cnt = 0;
				for(int a : l) {
					if(a != next) cnt++;
					else break;
				}
				sb.append(cnt);
				break;
			}
			l.add(next);
			visited[next] = true;
			next = next(next);
		}
		
		System.out.println(sb.toString());
		br.close();
	}

}