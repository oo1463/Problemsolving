package swea_1954;

import java.util.Scanner;

public class Solution {
	
	static int N;
	static int[][] arr;
	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, 1, 0, -1};

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		
		for(int i=1; i<=T; ++i) {
			
			N = sc.nextInt();
			arr = new int[N][N];
			
			int direction = 1;
			int cnt = 1;
			int nowX = 0;
			int nowY = 0;
			
			arr[nowX][nowY] = cnt;
			while(cnt < N*N) {
				System.out.println("fuck");
				int tx = nowX + dx[direction];
				int ty = nowY + dy[direction];
				
				if(tx >= 0 && tx <N && ty >= 0 && ty < N && arr[tx][ty] == 0) {
					arr[tx][ty] = ++cnt;
					nowX = tx;
					nowY = ty;
				}
				else {
					direction = (direction+1)%4;
				}
				
			}
			
			System.out.println("#"+i);
			for(int j=0; j<N; j++) {
				for(int k=0; k<N; k++) {
					System.out.print(arr[j][k] + " ");
				}
				System.out.println();
			}

		}
		
		
	}

}
