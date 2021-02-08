package swea_9229한빈이와spot_mart;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		

		int T = Integer.parseInt(st.nextToken());
		
		for(int t=1; t<=T; ++t) {
			
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int arr[] = new int[N];
			
			int M = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<N; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			
			int mx = -1;
			for(int i=0; i<N; i++) {
				for(int j=i+1; j<N; j++) {
					int sum = arr[i] + arr[j];
					if(sum <= M && mx < sum) {
						mx = sum;
					}
				}
			}
			
			sb.append("#" + t + " ");
			sb.append(mx + "\n");
			
		}
		
		System.out.println(sb.toString());
		br.close();
	}

}
