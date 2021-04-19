package swea_5607_조합;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	
	static final long divisor = 1234567891l;
	
	public static long power(long n, long pNum) {
		n %= divisor;
		if(pNum == 1) return n % divisor;
		
		if(pNum % 2 == 0) {
			long mult = power(n, pNum/2) % divisor;
			return (mult*mult) % divisor;
		}
		else {
			long mult = power(n, pNum/2) % divisor;
			long multSqaure = (mult * mult) % divisor; 
			return (multSqaure * n) % divisor;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		
		long factorial[] = new long[1000001];
		factorial[0] = 1;
		factorial[1] = 1;
		for(int i=2; i<=1000000; i++) factorial[i] = (factorial[i-1] * i) % divisor;
		
		int T = Integer.parseInt(st.nextToken());
		
		for(int t=1; t<=T; ++t) {
			long ans = 0;
			st = new StringTokenizer(br.readLine());
			int n, r;
			n = Integer.parseInt(st.nextToken());
			r = Integer.parseInt(st.nextToken());			
			
			ans = (factorial[n] * power((factorial[n-r] * factorial[r]) % divisor, divisor-2) % divisor) % divisor;
			sb.append("#" + t + " " + ans + "\n");
		}
		
		System.out.println(sb.toString());
		br.close();
	}

}