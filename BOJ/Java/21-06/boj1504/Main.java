package boj1504;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	
	static int N;
	static int edge[][];
	static int dist[][];
	static final int mx = 1000000;
	
	static class NodeAndDist implements Comparable<NodeAndDist>{
		int num;
		int dist;
		
		public NodeAndDist(int num, int dist) {
			this.num = num;
			this.dist = dist;
		}
		
		@Override
		public int compareTo(NodeAndDist o) {
			return this.dist - o.dist;
		}
	}
	
	public static int dijk(int start, int end) {
		
		PriorityQueue<NodeAndDist> pq = new PriorityQueue<>();
		
		pq.offer(new NodeAndDist(start, 0));
		
		while(!pq.isEmpty()) {
			NodeAndDist nd = pq.poll();
//			System.out.println(nd.num + " " + nd.dist);
			for(int i=1; i<=N; i++) {
				if(edge[nd.num][i] != mx && i != nd.num) {
					if(dist[start][i] > dist[start][nd.num] + edge[nd.num][i]) {
						dist[start][i] = dist[start][nd.num] + edge[nd.num][i];
						pq.offer(new NodeAndDist(i, dist[start][i]));
					}
				}
			}
		}
		
		return dist[start][end];
	}

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int E;
		int v1,v2;
		st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		
		dist = new int[N+1][N+1];
		edge = new int[N+1][N+1];
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				dist[i][j] = mx;
				edge[i][j] = mx;
			}
			dist[i][i] = 0;
			edge[i][i] = 0;
		}
		
		for(int i=0; i<E; i++) {
			st = new StringTokenizer(br.readLine());
			int a,b,c;
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			edge[a][b] = c;
			edge[b][a] = c;
		}
		
		st = new StringTokenizer(br.readLine());
		v1 = Integer.parseInt(st.nextToken());
		v2 = Integer.parseInt(st.nextToken());
		
//		System.out.println(dijk(1,N));
		int d1 = dijk(1,v1) + dijk(v1,v2) + dijk(v2,N);
		int d2 = dijk(1,v2) + dijk(v2,v1) + dijk(v1,N);
		int mn = d1>d2?d2:d1;
		
		if(d1 >= mx || d2 >= mx) mn = -1;
		
		System.out.println(mn);
		
	}

}
