package boj_6359_만취한상범;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		

		int T = Integer.parseInt(st.nextToken());
		
		for(int t = 0; t<T; t++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			
			boolean arr[] = new boolean[n+1];
			for(int i=1; i<=n; i++) arr[i] = false; 
			
			for(int i=1; i<=n; i++) {
				for(int j=i; j<=n; j += i) arr[j] = !arr[j];					
			}
			
			int cnt = 0;
			for(int i=1; i<=n; i++) {
				if(arr[i]) cnt++;
			}
			sb.append(cnt + "\n");
		}
		
		System.out.println(sb.toString());
		br.close();
	}

}