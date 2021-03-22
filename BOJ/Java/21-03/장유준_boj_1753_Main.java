package boj_1753;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	
	static class Edge implements Comparable<Edge>{
		int to;
		int cost;
		
		public Edge(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}

		@Override
		public int compareTo(Edge o) {
			return this.cost - o.cost;
		}
	}
	
	static ArrayList<Edge>[] l;
	static PriorityQueue<Edge> pq = new PriorityQueue<>();
	static boolean visited[] = new boolean[20001];
	static int costs[] = new int[20001];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		int V = Integer.parseInt(st.nextToken());
		int E = Integer.parseInt(st.nextToken());
		
		l = new ArrayList[V+1];
		for(int i=1; i<=V; i++) {
		   l[i] = new ArrayList<>();
		}
		
		st = new StringTokenizer(br.readLine());
		int start = Integer.parseInt(st.nextToken());
		
		for(int i=0; i<E; i++) {
			st = new StringTokenizer(br.readLine());
			int u, v, w;
			u = Integer.parseInt(st.nextToken());
			v = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			Edge te = new Edge(v,w);
			l[u].add(te);
		}
		
		for(int i=1; i<=V; i++) costs[i] = 210000001;
		
		costs[start] = 0;		
		pq.offer(new Edge(start, 0));

		while(!pq.isEmpty()) {
			Edge node = pq.poll();
			if(visited[node.to]) continue;
			visited[node.to] = true;
			
			for(Edge e : l[node.to]) {
				if(!visited[e.to] && costs[e.to] > costs[node.to] + e.cost) {
					costs[e.to] = costs[node.to] + e.cost;
					pq.offer(new Edge(e.to, costs[e.to]));
				}
			}
		}
		
		for(int i=1; i<=V; i++) {
			if(costs[i] != 210000001) sb.append(costs[i] + "\n");
			else sb.append("INF\n");
		}

		
		System.out.println(sb.toString());
		br.close();
	}

}