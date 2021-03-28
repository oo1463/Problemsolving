import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_9205_맥주마시면서 {
	
	static class Pair{
		int a,b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
	}
	
	static String ans;
	static boolean visited[];
	
	static void dfs(int n, int node, boolean adj[][]) {
		if(node == n+1) {
			ans = "happy";
			return;
		}
		
		for(int i=0; i<=n+1; i++) {
			if(adj[node][i] && !visited[i]) {
				visited[i] = true;
				dfs(n, i, adj);
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		

		int T = Integer.parseInt(st.nextToken());
		
		while(T-->0) {
			ans = "sad";
			visited = new boolean[102];
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			
			Pair store[] = new Pair[n+2];
			
			st = new StringTokenizer(br.readLine());
			store[0] = new Pair(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
			
			for(int i=1; i<=n; i++) {
				st = new StringTokenizer(br.readLine());
				store[i] = new Pair(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
			}
			
			st = new StringTokenizer(br.readLine());
			store[n+1] = new Pair(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
			
			boolean adj[][] = new boolean[n+2][n+2];
			
			for(int i=0; i<=n+1; i++) {
				for(int j=i+1; j<=n+1; j++) {
					int dist = Math.abs(store[i].a - store[j].a) + Math.abs(store[i].b - store[j].b);
					if(dist <= 1000) {
						adj[i][j] = true;
						adj[j][i] = true;
					}
				}
			}
						
			visited[0] = true;
			dfs(n, 0, adj);
			
			sb.append(ans+"\n");
			
		}

		
		System.out.println(sb.toString());
		br.close();
	}
}
