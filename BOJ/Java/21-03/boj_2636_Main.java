package boj_2636;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static class Pair{
		int a,b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
	}	
	
	static int dx[] = {1,0,-1,0};
	static int dy[] = {0,1,0,-1};

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		int map[][] = new int[N][M];
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		int prevCnt = 0;
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(map[i][j] == 1) prevCnt++;
			}
		}
		
		for(int k = 1; k<=N; k++) {
			
			boolean visited[][] = new boolean[N][M];
			Queue<Pair> q = new LinkedList<>();
			q.offer(new Pair(0,0));
			visited[0][0] = false;
			ArrayList<Pair> l = new ArrayList<>();
			int nowCnt = prevCnt;
			
			while(!q.isEmpty()) {
				Pair tp = q.poll();
				
				for(int i=0; i<4; i++) {
					int ti = tp.a + dx[i];
					int tj = tp.b + dy[i];
					
					if(ti >= 0 && tj >= 0 && ti < N && tj < M && !visited[ti][tj] && map[ti][tj] == 0) {
						visited[ti][tj] = true;
						q.offer(new Pair(ti,tj));
					}
					else if(ti >= 0 && tj >= 0 && ti < N && tj < M && !visited[ti][tj] && map[ti][tj] == 1) {
						visited[ti][tj] = true;
						l.add(new Pair(ti,tj));
						nowCnt--;
					}
				}
			}
			for(Pair p : l) map[p.a][p.b] = 0; 
			
			if(nowCnt == 0) {
				sb.append(k + "\n");
				sb.append(prevCnt + "\n");
				break;
			}
			prevCnt = nowCnt;
			
		}
		
		System.out.println(sb.toString());
		br.close();
	}

}