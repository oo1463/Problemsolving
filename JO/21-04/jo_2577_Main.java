package jo_2577;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		

		int N = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		
		int sushi[] = new int[N+k];
		int ate[] = new int[d+1];
		ate[c]++;
		int cnt = 1;
		int mx = 0;
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			sushi[i] = Integer.parseInt(st.nextToken());
		}
		for(int i=N; i<N+k; i++) {
			sushi[i] = sushi[i-N];
		}
		
		for(int i=0; i<k; i++) {
			if(ate[sushi[i]] == 0) cnt++;
			ate[sushi[i]]++;
			if(mx < cnt) mx = cnt;
		}
		
		for(int i=k; i<N+k; i++) {
			ate[sushi[i-k]]--;
			if(ate[sushi[i-k]] == 0 ) cnt--;
			
			if(ate[sushi[i]] == 0) cnt++;
			ate[sushi[i]]++;
			if(mx < cnt) mx = cnt;
		}
		
		sb.append(mx);
		
		System.out.println(sb.toString());
		br.close();
	}

}