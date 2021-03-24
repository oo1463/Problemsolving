package boj_1600;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair{
	int x,y;
	int jumpCnt;
	int fullCnt;
	public Pair(int x, int y, int jumpCnt,int fullCnt) {
		this.x = x;
		this.y = y;
		this.jumpCnt = jumpCnt;
		this.fullCnt = fullCnt;
	}
}

public class Main {
	
	static int dx[] = {1,0,-1,0};
	static int dy[] = {0,1,0,-1};
	static int jumpX[] = {-1, -2, -2, -1, 1, 2, 2, 1};
	static int jumpY[] = {-2, -1, 1, 2, 2, 1, -1, -2};
	static Queue<Pair> q = new LinkedList<>();
	static int map[][] = new int[201][201];
	static boolean visited[][][] = new boolean[201][201][31];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		

		int K = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		int W = Integer.parseInt(st.nextToken());
		int H = Integer.parseInt(st.nextToken());
		
		for(int i=0; i<H; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<W; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		q.offer(new Pair(0,0,0,0));
		visited[0][0][0] = true;
		while(!q.isEmpty()) {
			Pair tp = q.poll();
//			System.out.println(tp.x + " " + tp.y + " " + tp.jumpCnt  + " " + " " + tp.fullCnt);
			if(tp.x == H-1 && tp.y == W-1) {
				System.out.println(tp.fullCnt);
				return;
			}
			
			for(int i=0; i<4; i++) {
				int ti = tp.x + dx[i];
				int tj = tp.y + dy[i];
				int jcnt = tp.jumpCnt;
				int fcnt = tp.fullCnt+1;
				if(ti >= 0 && tj >= 0 && ti < H && tj < W && map[ti][tj] == 0 && !visited[ti][tj][jcnt]) {
					q.offer(new Pair(ti,tj,jcnt,fcnt));
					visited[ti][tj][jcnt] = true;
				}
			}
			if(tp.jumpCnt < K) {
				for(int i=0; i<8; i++) {
					int ti = tp.x + jumpX[i];
					int tj = tp.y + jumpY[i];
					int jcnt = tp.jumpCnt+1;
					int fcnt = tp.fullCnt+1;
					if(ti >= 0 && tj >= 0 && ti < H && tj < W && map[ti][tj] == 0 && !visited[ti][tj][jcnt]) {
						q.offer(new Pair(ti,tj,jcnt, fcnt));
						visited[ti][tj][jcnt] = true;
					}
				}
			}
			
		}
		
		System.out.println(-1);

		br.close();
	}

}