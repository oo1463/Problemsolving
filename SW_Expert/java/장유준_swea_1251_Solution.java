package swea_1251;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Solution {
	
	static int parent[] = new int[1001];
	
	static int find(int start) {
		if(parent[start] == start) {
			return start;
		}
		return parent[start] = find(parent[start]);
	}
	
	static void union(int a, int b) {
		int a1 = find(a);
		int b1 = find(b);
		
		parent[b1] = a1;
	}
	
	static class DistFromTo implements Comparable<DistFromTo>{
		long dist;
		int from;
		int to;
		public DistFromTo(long dist, int from, int to) {
			this.dist = dist;
			this.from = from;
			this.to = to;
		}
		@Override
		public int compareTo(DistFromTo o) {
			return Long.compare(this.dist, o.dist);
		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		

		int T = Integer.parseInt(st.nextToken());
		
		for(int t=1; t<=T; ++t) {
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			
			int map[][] = new int[N][2];
			
			for(int i=0; i<N; i++) {
				parent[i] = i;
			}
			
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<N; i++) {
				map[i][0] = Integer.parseInt(st.nextToken());
			}
			
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<N; i++) {
				map[i][1] = Integer.parseInt(st.nextToken());
			}
			
			st = new StringTokenizer(br.readLine());
			double E = Double.parseDouble(st.nextToken());
			
			ArrayList<DistFromTo> l = new ArrayList<>();
			
			for(int i=0; i<N; i++) {
				for(int j=i+1; j<N; j++) {
					long dist = ((long)map[i][0]-map[j][0])*(map[i][0]-map[j][0]) + ((long)map[i][1]-map[j][1])*(map[i][1]-map[j][1]);
//					System.out.println(dist);
					l.add(new DistFromTo(dist, i, j));
				}
			}
//			System.out.println();
			Collections.sort(l);
			
			double cnt = 0;
			
			for(DistFromTo d : l) {
				if(find(d.from) != find(d.to)) {
//					System.out.println(d.from + " " + d.to + " " + d.dist);
					union(d.from, d.to);
					cnt += (double)d.dist * E;
				}				
			}
			
			sb.append("#"+t+" "+Math.round(cnt) + "\n");
		}
		
		System.out.println(sb.toString());
		br.close();
	}

}