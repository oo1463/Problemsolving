package boj_3085_사탕게임;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	public static int[][] map;
	public static int[] dx = {1,0,-1,0};
	public static int[] dy = {0,1,0,-1};
	public static int N;
		
	
	public static int maxEatable() {
		int mx = 1;
		for(int i=0; i<N; i++) {
			int cnt1 = 1;
			int cnt2 = 1;
			for(int j=0; j<N-1; j++) {
				if(map[i][j] == map[i][j+1]) cnt1++;
				else cnt1 = 1;
				if(map[j][i] == map[j+1][i])cnt2++;
				else cnt2 = 1;
				if(mx < cnt1) mx = cnt1;
				if(mx < cnt2) mx = cnt2;
			}
			
		}
		return mx;
	}
	
	public static void swap(int x1, int y1, int x2, int y2) {
		int tmp = map[x1][y1];
		map[x1][y1] = map[x2][y2];
		map[x2][y2] = tmp;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		

		N = Integer.parseInt(st.nextToken());
		map = new int[51][51];
		int ans = 1;
		
		for(int i=0; i<N; i++) {
			String s = br.readLine();
			for(int j=0; j<N; j++) {
				map[i][j] = s.charAt(j);
			}
		}
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				for(int k=0; k<4; k++) {
					int tx = i + dx[k];
					int ty = j + dy[k];
					if(tx >= 0 && ty >= 0 && tx < N && ty < N) {
						swap(i,j,tx,ty);
						int t = maxEatable();
						if(ans < t) ans = t;
						swap(i,j,tx,ty);
					}
				}
			}
		}
		
		System.out.println(ans);
		br.close();
	}

}