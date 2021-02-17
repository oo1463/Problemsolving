package boj_17135_캐슬디펜스;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static class Point{
		int r,c;		
		public Point(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}
	
	static Point archer[] = new Point[3];
	static int N, M, D;
	static int map[][] = new int[16][15];
	static int mx;	
	
	public static void placeArcher(int si, int cnt) {
		if(cnt == 3) {
			int t = play();
			if(mx < t) mx = t;
			return;
		}
		
		for(int i=si; i<M; i++) {
			archer[cnt].r = N;
			archer[cnt].c = i;
			placeArcher(i+1, cnt+1);
		}
	}
	
	public static int play() {
		int killCount = 0;
		
		int tmpMap[][] = new int[16][15];
		mapInit(tmpMap);
		
		while(true) {
			boolean eleminated[][] = new boolean[15][15];
			for(int k=0; k<3; k++) {
				int mnDist = 210000000;
				int ti = -1,tj = -1;
				for(int i=N-1; i>=0; --i) {
					for(int j=0; j<M; ++j) {
						if(tmpMap[i][j] == 1) {
							Point enemy = new Point(i,j);
							int dist = distPoint(enemy, archer[k]);
							if(dist <= D) {
								
								if(mnDist > dist) {
									ti = i;
									tj = j;
									mnDist = dist;
								}
								else if(mnDist == dist) {
									if(tj > j) {
										ti = i;
										tj = j;
									}
								}															
								
							}
						}
					}
				}
				if(mnDist <= D) eleminated[ti][tj] = true;
			}
			
			for(int i=0; i<N; i++) {
				for(int j=0; j<M; j++) {
					if(tmpMap[i][j] == 1 && eleminated[i][j]) {
						tmpMap[i][j] = 0;
						killCount++;
					}
				}
			}
			moveEnemy(tmpMap);
			if(checkEnd(tmpMap)) break;
		}
		
		return killCount;
	}
	
	public static void moveEnemy(int m[][]) {
		for(int i=N-1; i>=0; i--) {
			for(int j=0; j<M; j++) {
				m[i+1][j] = m[i][j];
			}
		}
		
		for(int j=0; j<M; j++) {
			m[0][j] = 0;
		}
	}
	
	public static boolean checkEnd(int m[][]) {
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(m[i][j] == 1) return false;
			}
		}
		return true;
	}
	
	public static void mapInit(int m[][]) {
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				m[i][j] = map[i][j];
			}
		}
	}
	
	public static int distPoint(Point a, Point b) {
		return Math.abs(a.c-b.c)+Math.abs(a.r-b.r);
	}
	


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i=0; i<3; i++) archer[i] = new Point(0,0);
		
		placeArcher(0,0);
		
		System.out.println(mx);
		br.close();
	}

}