import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class SWEA1249 {
	
	static int N;
	static int minDist[][];
	static int dx[] = {1,0,-1,0};
	static int dy[] = {0,1,0,-1};
	static Pos p[][];
	static int map[][];
	static boolean visited[][];
	
	static class Pos implements Comparable<Pos>{
		int x,y;
		int dent;
		public Pos(int x, int y) {
			this.x=x;
			this.y=y;
		}
		
		public int compareTo(Pos o) {
			return this.dent - o.dent;
		}
		
	}
	
	public static int bfs() {
		PriorityQueue<Pos> q = new PriorityQueue<>();
		q.offer(p[0][0]);
		
		while(!q.isEmpty()) {
			Pos tp = q.poll();			
			
			for(int i=0; i<4; i++) {
				int tx = tp.x + dx[i];
				int ty = tp.y + dy[i];
				int tDent = tp.dent;
				if(tx >= 0 && tx < N && ty >= 0 && ty < N && !visited[tx][ty]) {
					visited[tx][ty] = true;
					Pos pos = p[tx][ty];
					pos.dent = tDent + map[tx][ty];
					q.offer(pos);
				}
				else if (tx >= 0 && tx < N && ty >= 0 && ty < N && visited[tx][ty] && p[tx][ty].dent > tDent + map[tx][ty]) {
					Pos pos = p[tx][ty];
					pos.dent = tDent + map[tx][ty];
					q.offer(pos);
				}
			}
			
		}
		
		return p[N-1][N-1].dent;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		

		int T = Integer.parseInt(st.nextToken());
		
		for(int t=1; t<=T; ++t) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			minDist = new int[N][N];
			p = new Pos[N][N];
			visited = new boolean[N][N];
			
			for(int i=0; i<N; i++) for(int j=0; j<N; j++) p[i][j] = new Pos(i,j);
			
			map = new int[N][N];
			for(int i=0; i<N; i++) {
				String ts = br.readLine();
				for(int j=0; j<N; j++) {
					p[i][j].dent = ts.charAt(j)-'0';
					map[i][j] = p[i][j].dent;
				}
			}
			
			int ans = bfs();

			sb.append("#"+t+" "+ans+"\n");
		}
		
		System.out.println(sb.toString());
		br.close();
	}

}