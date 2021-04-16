package boj_17471_게리맨더링;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int people[];
	static ArrayList<Integer> adj[];
	static int N;
	static ArrayList<Integer> area1;
	static ArrayList<Integer> area2;
	static int peopleCnt1;
	static int peopleCnt2;
	static int mn = 999999;
	static boolean visitDivide[] = new boolean[11];
	
	public static void divide(int idx) {
		
		if(idx > N) {
			
			area1.clear();
			makeArea1();
			area2.clear();
			makeArea2();
			visited = new boolean[N+1];
//			System.out.println(area1 + " " + area2);
			if(!area1.isEmpty() && !area2.isEmpty()) {
				peopleCnt1 = bfsCheck(area1.get(0), area1);
				peopleCnt2 = bfsCheck(area2.get(0), area2);
//				System.out.println(peopleCnt1 + " " + peopleCnt2);
				if(peopleCnt1 != -1 && peopleCnt2 != -1) {
					int diff = Math.abs(peopleCnt1-peopleCnt2);
					if(mn > diff) mn = diff;
				}
			}		
			

			peopleCnt1 = 0;
			peopleCnt2 = 0;
			
			return;
		}
		
		visitDivide[idx] = true;
		divide(idx+1);
		visitDivide[idx] = false;
		divide(idx+1);
		
	}
	
	public static void makeArea1() {
		for(int i=1; i<=N; i++) {
			if(visitDivide[i]) area1.add(i);
		}
	}
	
	public static void makeArea2() {
a1:		for(int i=1; i<=N; i++) {
			for(int a : area1) {
				if(i == a) {
					continue a1;
				}
			}
			area2.add(i);
		}
	}
	
	static boolean visited[];
	
	public static int bfsCheck(int start, ArrayList<Integer> area) {
		Queue<Integer> q = new LinkedList<>();
		
		q.offer(start);
		visited[start] = true;
		int cnt = 1;
		int peoplecnt = 0;
		peoplecnt += people[start];
		
		while(!q.isEmpty()) {
			
			int t = q.poll();
			
			for(int i : adj[t]) {
				if(!visited[i] && isInArea(i, area)) {
					visited[i] = true;
					cnt++;
					peoplecnt += people[i];
					q.add(i);
				}
			}
		}
		if(cnt != area.size()) return -1;
		
		return peoplecnt;
	}
	
	public static boolean isInArea(int a, ArrayList<Integer> area) {
		for(int i : area) {
			if(i == a) return true;
		}
		return false;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		

		N = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		people = new int[N+1];
		adj = new ArrayList[N+1];
		area1 = new ArrayList<>();
		area2 = new ArrayList<>();
		for(int i=1; i<=N; i++) people[i] = Integer.parseInt(st.nextToken());
		
		for(int i=1; i<=N; i++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			adj[i] = new ArrayList<>();
			for(int j=0; j<n; j++) {
				adj[i].add(Integer.parseInt(st.nextToken()));
			}
		}
		
		divide(1);
		if(mn != 999999) sb.append(mn);
		else sb.append(-1);
		
		System.out.println(sb.toString());
		br.close();
	}

}