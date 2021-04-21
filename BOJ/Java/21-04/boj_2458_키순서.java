package boj_2458_키순서;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static LinkedList<Integer> up[];
	static LinkedList<Integer> down[];
	static int n,m;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int ans = 0;
		
		up = new LinkedList[n+1];
		down = new LinkedList[n+1];
		for(int i=1; i<=n; i++) {
			up[i] = new LinkedList<>();
			down[i] = new LinkedList<>();
		}
		
		for(int i=0; i<m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			up[a].add(b);
			down[b].add(a);
		}
		
		for(int i=1; i<=n; i++) {
			int a = bfs(i, up);
			a += bfs(i, down);
			if(a == n-1) ans++;
		}
		
		System.out.println(ans);
		br.close();
	}
	
	static public int bfs(int start, LinkedList<Integer> l[]) {
		Queue<Integer> q = new LinkedList<>();
		boolean visited[] = new boolean[n+1];
		q.offer(start);
		visited[start] = true;
		int cnt = 0; 
		
		while(!q.isEmpty()) {
			int t = q.poll();
			for(int a : l[t]) {
				if(!visited[a]) {
					visited[a] = true;
					q.offer(a);
					cnt++;
				}
			}
		}
		return cnt;
	}

}
