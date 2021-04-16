package boj_2239_스도쿠;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int map[][];
	
	public static boolean checkRow(int si, int num) {
		for(int j=0; j<9; j++) {
			if(map[si][j] == num) return false;
		}
		return true;
	}
	
	public static boolean checkCol(int sj, int num) {
		for(int i=0; i<9; i++) {
			if(map[i][sj] == num) return false;
		}
		return true;
	}
	
	public static boolean checkBox(int si, int sj, int num) {
		for(int i=si-si%3; i<si-si%3+3; i++) {
			for(int j=sj-sj%3; j<sj-sj%3+3; j++) {
				if(map[i][j] == num) return false;
			}
		}
		return true;
	}
	
	public static boolean isAllInserted() {
		for(int i=0; i<9; i++) {
			for(int j=0; j<9; j++) {
				if(map[i][j] == 0) return false;
			}
		}
		return true;
	}
	
	public static void backtrack() {
		if(isAllInserted()) {
			for(int i=0; i<9; i++) {
				for(int j=0; j<9; j++) {
					System.out.print(map[i][j]);
				}
				System.out.println();
			}
			System.exit(0);
			return;
		}
		
		for(int i=0; i<9; i++) {
			for(int j=0; j<9; j++) {
				if(map[i][j] == 0) {
					for(int num=1; num<=9; num++) {
						if(checkRow(i, num) && checkCol(j, num) && checkBox(i,j,num)) {
							map[i][j] = num;
							backtrack();
							map[i][j] = 0;
						}
					}
					if(map[i][j] == 0) return;
				}
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		map = new int[9][9];
		
		for(int i=0; i<9; i++) {
			String ts = br.readLine();
			for(int j=0; j<9; j++) {
				map[i][j] = ts.charAt(j)-'0';  
			}
		}
		
		backtrack();
		
		System.out.println(sb.toString());
		br.close();
	}

}