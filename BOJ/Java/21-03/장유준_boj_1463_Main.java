package boj_1463;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int min(int a, int b) {return a>b?b:a;}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		

		int N = Integer.parseInt(st.nextToken());
		int dp[] = new int[1000001];
		for(int i=1; i<=N; i++) dp[i] = Integer.MAX_VALUE;
		
		dp[1] = 0;
		dp[2] = 1;
		dp[3] = 1;
		for(int i=4; i<= N; i++) {
			if(i%3 == 0) dp[i] = min(dp[i/3] + 1, dp[i]);
			if(i%2 == 0) dp[i] = min(dp[i/2] + 1, dp[i]);
			dp[i] = min(dp[i-1] + 1, dp[i]);
		}
		
		sb.append(dp[N]);
		
		System.out.println(sb.toString());
		br.close();
	}

}