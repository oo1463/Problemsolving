import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class 장유준_boj_17472_다리만들기2 {
	
	static int map[][] = new int[11][11];
	static ArrayList<ArrayList<Pair>> land = new ArrayList<>();
	static int N,M;
	static boolean visited[][] = new boolean[11][11];
	
	static int dx[] = {1,0,-1,0};
	static int dy[] = {0,1,0,-1}; 
	
	static class Pair{
		int a,b;
		public Pair(int a,int b) {
			this.a = a;
			this.b = b;
		}
	}
	
	static class FromToDist implements Comparable<FromToDist>{
		int from,to,dist;

		public FromToDist(int from, int to, int dist) {
			this.from = from;
			this.to = to;
			this.dist = dist;
		}

		@Override
		public int compareTo(FromToDist o) {
			return this.dist >= o.dist ? 1 : -1;
		}
		
		
	}
	
	static void bfs(Pair start) {
		land.add(new ArrayList<Pair>());
		int sz = land.size()-1;
		
		Queue<Pair> q = new LinkedList<>();
		
		visited[start.a][start.b] = true;
		q.offer(start);
		
		while(!q.isEmpty()) {
			Pair tp = q.poll();
			land.get(sz).add(tp);
			
			for(int i=0; i<4; i++) {
				int tx = tp.a + dx[i];
				int ty = tp.b + dy[i];
				if(tx>= 0 && ty >=0 && tx < N && ty < M && map[tx][ty] == 1 && !visited[tx][ty]) {
					visited[tx][ty] = true;
					q.offer(new Pair(tx,ty));
				}
			}
		}
		
	}	
	
	static boolean checkBlocked(Pair a, Pair b, int direction) { // 1일 때 가로로 연결
		int min,max;
		if(direction == 1) {
			min = Math.min(a.b, b.b);
			max = Math.max(a.b, b.b);
			
			for(int i=min+1; i<max; i++) {
				if(map[a.a][i] == 1) return true;
			}
		}
		else {
			min = Math.min(a.a, b.a);
			max = Math.max(a.a, b.a);
			
			for(int i=min+1; i<max; i++) {
				if(map[i][a.b] == 1) return true;
			}
		}
		return false;
	}
	
	static int parents[] = new int[20];
	
	static int find(int a) {
		if(parents[a] == a) return a;
		return parents[a] = find(parents[a]);
	}
	
	static void union(int a, int b) {
		
		a = find(a);
		b = find(b);		
		if(a == b) return;
		parents[a] = b;
		
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(map[i][j] == 1 && !visited[i][j]) bfs(new Pair(i,j));
			}
		}
		int sz = land.size();
		
		int adjDist[][] = new int[7][7];
		for(int i=0; i<sz; i++) {  // 인접행렬 초기화
			for(int j=0; j<sz; j++) {
				adjDist[i][j] = 1000;
				if(i==j) adjDist[i][j] = 0;
			}
		}
		
		for(int i=0; i<sz; i++) {
			for(int j=i+1; j<sz; j++) {
				for(Pair p1 : land.get(i)) {
					for(Pair p2 : land.get(j)) {
						int dist = 1000;
						if(p1.a == p2.a && !checkBlocked(p1, p2, 1)) dist = Math.abs(p1.b - p2.b) - 1;
						
						if(p1.b == p2.b && !checkBlocked(p1, p2, 2)) dist = Math.abs(p1.a - p2.a) - 1;
						if(dist >= 2) {
							adjDist[i][j] = Math.min(dist, adjDist[i][j]);
							adjDist[j][i] = Math.min(dist, adjDist[i][j]);
						}
					}
				}
			}
		}
		
		PriorityQueue<FromToDist> pq = new PriorityQueue<>();
		
		for(int i=0; i<sz; i++) {
			for(int j=i+1; j<sz; j++) {
				if(adjDist[i][j] == 1000) adjDist[i][j] = 0;
				int dist = adjDist[i][j];
				if(dist != 0) pq.offer(new FromToDist(i,j,dist));
			}
		}
		
		for(int i=0; i<20; i++) parents[i] = i;
		
		int ans = 0;
		int sum = 0;
		int pqsz = pq.size();
		for(int i=0; i<pqsz; i++) {
			FromToDist iter = pq.poll();
			int pf = find(iter.from);
			int pt = find(iter.to);
			if(pf != pt) {
				sum++;
				ans += iter.dist;
				union(pf, pt);
			}
		}
		
		if(sum != sz-1) ans = -1;
		
		System.out.println(ans);
		
		br.close();
	}
}
