package boj_1260;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int N,M;
	static boolean visited[] = new boolean[1001];
	static boolean adjMat[][] = new boolean[1001][1001];
	static StringBuilder sb = new StringBuilder();	
	
	public static void dfs(int start) {
		
		sb.append(start + " ");
		
//		System.out.println(start);
		
		for(int i=1; i<=N; i++) {
			if(adjMat[start][i] && !visited[i]) {
				visited[i] = true;
				dfs(i);
			}
		}
	}
	
	public static void bfs(int start) {
		Queue<Integer> q = new LinkedList<>();
		
		q.add(start);
		visited[start] = true;
		
		
		while(!q.isEmpty()) {
			int t = q.poll();
			sb.append(t + " ");
			
			for(int i=1; i<=N; i++) {
				if(adjMat[t][i] && !visited[i]) {
					visited[i] = true;
					q.add(i);
				}
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		int start = Integer.parseInt(st.nextToken());
		
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int a,b;
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			adjMat[a][b] = true;
			adjMat[b][a] = true;
		}
		
		visited[start] = true;
		dfs(start);
		sb.append("\n");
		for(int i=0; i<=1000; i++) visited[i] = false;
		bfs(start);
		
		System.out.println(sb.toString());
		br.close();
	}

}