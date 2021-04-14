package swea_5656;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Solution {
	
	static int N,W,H;
	static int map[][];
	static int tmpMap[][];
	static int fallArea[] = new int[4];
	static int dx[] = {1,0,-1,0};
	static int dy[] = {0,1,0,-1};
	static boolean visited[][];
	static int mn;
	
	public static int remain() {
		int cnt = 0;
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				if(tmpMap[i][j] != 0) cnt++;
			}
		}
		return cnt;
	}
	
	public static void findFallArea(int cnt) {
		if(cnt >= N) {
			for(int i=0; i<H; i++) {
				for(int j=0; j<W; j++) tmpMap[i][j] = map[i][j];
			}
			
			fall();
			
			int cntBlock = remain();
			if(mn > cntBlock) {
				mn = cntBlock;
			}
			return;
		}
		
		for(int i=0; i<W; i++) {
			fallArea[cnt] = i;
			findFallArea(cnt+1);
		}
	}
	
	public static void fall() {
		for(int i=0; i<N; i++) {
			for(int j=0; j<H; j++) {
				if(tmpMap[j][fallArea[i]] != 0) {
					visited = new boolean[H][W];
					boom(j, fallArea[i]);
					break;
				}
			}
			down();
		}
	}
	
	public static void boom(int r, int c) {
		
		int num = tmpMap[r][c];
		tmpMap[r][c] = 0;
		visited[r][c] = true;
		
		for(int i=0; i<4; i++) {
			for(int j=1; j<num; j++) {
				int tr = r + dx[i]*j;
				int tc = c + dy[i]*j;
				
				if(tr >= 0 && tr < H && tc >= 0 && tc < W && !visited[tr][tc] && tmpMap[tr][tc] != 0) {
					boom(tr,tc);										
				}
			}
		}
	}
	
	public static void down() {
		for(int j=0; j<W; j++) {
			Stack<Integer> s = new Stack<>();
			for(int i=0; i<H; i++) {
				if(tmpMap[i][j] != 0 ) {
					s.push(tmpMap[i][j]);
					tmpMap[i][j] = 0;
				}
			}
			
			for(int i=H-1; i>=0; i--) {
				if(!s.isEmpty()) {
					tmpMap[i][j] = s.pop();
				}
				else break;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		

		int T = Integer.parseInt(st.nextToken());
		
		for(int t=1; t<=T; ++t) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			H = Integer.parseInt(st.nextToken());
			map = new int[H][W];
			tmpMap = new int[H][W];
			for(int i=0; i<H; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0; j<W; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			mn = 999999;
			findFallArea(0);
			
			sb.append("#" + t + " " + mn + "\n");
			
		}
		
		System.out.println(sb.toString());
		br.close();
	}

}