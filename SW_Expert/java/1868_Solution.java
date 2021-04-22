package swea_1868_파핑파핑지뢰찾기;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	
	static int N;
	static char map[][];
	static boolean opened[][];
	static int dr[] = {1,0,-1,0, 1, 1, -1, -1};
	static int dc[] = {0,1,0,-1, 1, -1, 1, -1};
	
	public static boolean is_empty_around(int r, int c) {
		for(int i=0; i<8; i++) {
			int tr = r + dr[i];
			int tc = c + dc[i];
			if(tr >= 0 && tr < N && tc >= 0 && tc < N && !opened[tr][tc] && map[tr][tc] == '*') {
				return false;
			}
		}
		return true;
	}
	
	public static void open(int r, int c) {
		for(int i=0; i<8; i++) {
			int tr = r + dr[i];
			int tc = c + dc[i];
			if(tr >= 0 && tr < N && tc >= 0 && tc < N && map[tr][tc] != '*') {
				opened[tr][tc] = true;
				map[tr][tc] = '0';
			}
		}		
	}
	
	public static void bfs(int sr, int sc) {
		Queue<Integer> q = new LinkedList<>();
		q.offer(sr);
		q.offer(sc);
		
		while(!q.isEmpty()) {
			int qr = q.poll();
			int qc = q.poll();			
			opened[qr][qc] = true;
			map[qr][qc] = '0';
			if(is_empty_around(qr,qc)) {
				for(int i=0; i<8; i++) {
					int tr = qr + dr[i];
					int tc = qc + dc[i];
					if(tr >= 0 && tr < N && tc >= 0 && tc < N && !opened[tr][tc] && map[tr][tc] != '*') {
						q.offer(tr);
						q.offer(tc);
					}
				}
				open(qr,qc);
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
			map = new char[N][N];
			opened = new boolean[N][N];
			
			for(int i=0; i<N; i++) {
				String ts = br.readLine();
				for(int j=0; j<N; j++) {
					map[i][j] = ts.charAt(j);
				}
			}					
			
			ArrayList<Integer> l = new ArrayList<>();
			
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(map[i][j] != '*' && is_empty_around(i, j)) {
						l.add(i);
						l.add(j);
					}
				}
			}
			int cnt = 0;
			
			for(int i=0; i<l.size(); i+=2) {
				int r = l.get(i);
				int c = l.get(i+1);
				if(map[r][c] != '0' && map[r][c] != '*') {
					bfs(r,c);
					cnt++;
				}
			}
			
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(map[i][j] != '0' && map[i][j] != '*') {
						bfs(i,j);
						cnt++;
					}
				}
			}
			sb.append("#" + t + " " + cnt + "\n");
		}
		
		System.out.println(sb.toString());
		br.close();
	}

}