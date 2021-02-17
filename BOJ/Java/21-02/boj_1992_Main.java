package boj_1992_쿼드트리;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N;
	static int map[][] = new int[64][64];
	static StringBuilder sb = new StringBuilder();
	
	public static String quad_tree(int sr, int sc, int fr, int fc) {
		
		if(sr >= fr || sc >= fc) {
			return Integer.toString(map[sr][sc]);
		}
		int nr = (fr+sr)/2;
		int nc = (fc+sc)/2;
		
		String one = quad_tree(sr,sc,nr,nc);  // 1사분면
		String two = quad_tree(sr,nc+1,nr,fc); // 2사분면
		String three = quad_tree(nr+1, sc, fr, nc);  // 4사분면
		String four = quad_tree(nr+1, nc+1, fr, fc);  // 3사분면
		
		if(one.equals(two) && two.equals(three) && three.equals(four) && (one.equals("1") || one.equals("0"))) {
			return one;
		}
		else {
			return ("("+one+two+three+four+")");
		}
		
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		

		N = Integer.parseInt(st.nextToken());
		
		for(int i=0; i<N; i++) {
			String s = br.readLine();
			for(int j=0; j<N; j++) {
				map[i][j] = s.charAt(j) - '0';
			}
		}
		
		String s = quad_tree(0,0,N-1,N-1);
		
		System.out.println(s);
		br.close();
	}

}