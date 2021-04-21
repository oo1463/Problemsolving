package boj_1194_달이차오른다;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int N,M;
	static char map[][];
	static int dr[] = {1,0,-1,0};
	static int dc[] = {0,1,0,-1};
	static int mn = 999999;
	static Boolean visited[][][];
	
	static class Pos{
		int r,c;
		int cnt;
		int key;
		
		public Pos(int r, int c, int cnt, int key) {
			this.r = r;
			this.c = c;
			this.cnt = cnt;
			this.key = key;
		}
	}
	
	static void bfs(int sr, int sc, int cnt, int key) {
				
		Queue<Pos> q = new LinkedList<>();
		ArrayList<Pos> l = new ArrayList<>();
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				for(int k=0; k<64; k++)
				visited[i][j][k] = false;
			}
		}
		
		q.offer(new Pos(sr,sc,cnt,key));

		visited[sr][sc][key] = true;
		
		while(!q.isEmpty()) {
			Pos tp = q.poll();
			
			for(int i=0; i<4; i++) {
				int r = tp.r + dr[i];
				int c = tp.c + dc[i];
				if(r >= 0 && r < N && c >= 0 && c < M && !visited[r][c][tp.key] && map[r][c] != '#'){
					if(map[r][c] >= 'a' && map[r][c] <='f') {
						int tKeyBit = tp.key;
						visited[r][c][tp.key] = true;
						if(( tKeyBit & (int)Math.pow(2, map[r][c]-'a') ) == 0) {
							tKeyBit += (int)Math.pow(2, map[r][c]-'a');
							l.add(new Pos(r,c,tp.cnt+1, tKeyBit));
						}
						q.offer(new Pos(r,c,tp.cnt+1, tKeyBit));	
						
					}
					else if(map[r][c] >='A' && map[r][c] <='F') {
						if(havingKey((char)(map[r][c] + 'a' - 'A'), tp.key)){
							visited[r][c][tp.key] = true;		
							q.offer(new Pos(r,c,tp.cnt+1, tp.key));			
						}
					}
					else if(map[r][c] == '1') {
						if(mn > tp.cnt+1) mn = tp.cnt+1;						
					}
					else {
						visited[r][c][tp.key] = true;
						map[r][c] = '.';
						q.offer(new Pos(r,c,tp.cnt+1, tp.key));
					}
				}
			}
		}
		
	}
	
	public static boolean havingKey(char key, int keyBit) {
		if((keyBit & ((int)Math.pow(2, key - 'a'))) > 0) return true;
		return false;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new char[N][M];
		visited = new Boolean[N][M][64];
		
		int sr = 0,sc = 0;
		
		for(int i=0; i<N; i++) {
			String s = br.readLine();
			for(int j=0; j<M; j++) {
				map[i][j] = s.charAt(j);
				if(map[i][j] == '0') {
					sr = i;
					sc = j;
				}
			}
		}
		
		bfs(sr,sc,0,0);
		
		if(mn == 999999) System.out.println(-1);
		else System.out.println(mn);
		
		br.close();
	}

}