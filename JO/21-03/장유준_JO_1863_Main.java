package JO_1863;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N,M;
	static int parents[];
	
	static void make() {
		for(int i=1; i<=N; i++) {
			parents[i] = i;
		}
	}
	
	static int findSet(int a) {
		if(parents[a] == a) return a;
		return parents[a] = findSet(parents[a]);
	}
	
	static boolean union(int a, int b) {
		int aRoot = findSet(a);
		int bRoot = findSet(b);
		if(aRoot == bRoot) return false;
		parents[bRoot] = aRoot;
		
		return true;
	}

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		
		
		N = Integer.parseInt(st.nextToken());
		parents = new int[N+1];
		M = Integer.parseInt(st.nextToken());
		
		make();
		
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int a,b;
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			union(a,b);
		}
		
		int cnt = 0;
		for(int i=1; i<=N; i++) {
			if(i == parents[i]) cnt++;
		}
		
		System.out.println(cnt);
		br.close();

	}
}
