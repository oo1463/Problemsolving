package boj_15683_감시;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
	static int map[][];
	static ArrayList<Pos> camera = new ArrayList<>(); 	
	static LinkedList<Pos> list5 = new LinkedList<>();
	static int dx[] = {1,0,-1,0};
	static int dy[] = {0,1,0,-1};
	static int N,M;
	static int mn = 9999;
	static int sum;
	
	static class Pos{
		int r,c;
		int camera;
		public Pos(int r, int c, int camera) {
			this.r = r;
			this.c = c;
			this.camera = camera;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		map = new int[N][M];
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] == 0) sum++;
				else if(map[i][j] != 0 && map[i][j] != 5 && map[i][j] != 6) {
					camera.add(new Pos(i,j,map[i][j]));
				}
				else if(map[i][j] == 5) list5.add(new Pos(i,j,5));				
			}
		}
		
		list5Fill();
		recur(0);
		sb.append(mn);
		
		System.out.println(sb.toString());
		br.close();
	}
	
	public static void recur(int cnt) {
		
		if(cnt >= camera.size()) {			
			
			if(sum < mn) mn = sum;
		}
		
		for(int i=cnt; i<camera.size(); i++) {
			for(int j=0; j<4; j++) {
				cameraLineFillWithDirection(camera.get(i), j);
				recur(i+1);
				cameraLineEmptyWithDirection(camera.get(i), j);
			}
		}
	}	
	
	public static void cameraLineFillWithDirection(Pos p, int direction) {
		switch(p.camera) {
		case 1:
			lineFill(p, direction);
			break;
			
		case 2:
			lineFill(p, direction);
			lineFill(p, (direction+2)%4);
			break;
		case 3:
			lineFill(p, direction);
			lineFill(p, (direction+1)%4);
			break;
		case 4:
			lineFill(p, direction);
			lineFill(p, (direction+1)%4);
			lineFill(p, (direction+2)%4);
			break;	
		}
	}
	
	public static void cameraLineEmptyWithDirection(Pos p, int direction) {
		switch(p.camera) {
		case 1:
			lineEmpty(p, direction);
			break;
			
		case 2:
			lineEmpty(p, direction);
			lineEmpty(p, (direction+2)%4);
			break;
		case 3:
			lineEmpty(p, direction);
			lineEmpty(p, (direction+1)%4);
			break;
		case 4:
			lineEmpty(p, direction);
			lineEmpty(p, (direction+1)%4);
			lineEmpty(p, (direction+2)%4);
			break;	
		}
	}	
	
	public static void printMap() {
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}
	}
	
	public static void list5Fill() {
		for(Pos p : list5) {
			for(int i=0; i<4; i++) {
				lineFill(p, i);
			}
		}
	}
	
	public static void lineFill(Pos p, int direction) {
			
		int tr = p.r;
		int tc = p.c;
		
		while(true) {
			tr = tr + dx[direction];
			tc = tc + dy[direction];
			if(tr >= 0 && tr < N && tc >= 0 && tc < M && map[tr][tc] != 6) {
				if(map[tr][tc] <= 0) {
					if(map[tr][tc] == 0) sum--;
					map[tr][tc]--;
				}
				
			}
			else break;
		}
	}
	
	public static void lineEmpty(Pos p, int direction) {
		int tr = p.r;
		int tc = p.c;
		
		while(true) {
			tr = tr + dx[direction];
			tc = tc + dy[direction];
			if(tr >= 0 && tr < N && tc >= 0 && tc < M && map[tr][tc] != 6) {
				if(map[tr][tc] < 0) {
					if(map[tr][tc] == -1) sum++;
					map[tr][tc]++;
				}
			}
			else break;
		}
	}
	
}