
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.StringTokenizer;

public class SWEA_5644 {
	
	static int dirX[] = {0,0,1,0,-1};
	static int dirY[] = {0,-1,0,1,0};
	static ArrayList<AP> ap;
	
	static class Pos{
		int x,y;
		public Pos(int x, int y) {
			this.x=x;
			this.y=y;
		}
	}
	
	
	static class AP implements Comparable<AP>{
		Pos pos;
		int charge;
		int power;
		boolean visited = false;
		
		public AP(int x, int y, int charge, int power) {
			this.pos = new Pos(x,y);
			this.charge = charge;
			this.power = power;
		}

		@Override
		public int compareTo(AP o) {
			return this.power < o.power ? 1:-1; 
		}

	}
	
	public static int dist(Pos A, Pos B) {
		return Math.abs(A.x-B.x) + Math.abs(A.y-B.y);
	}
	
	public static int findAP(Pos A, Pos B) {  // 해당 위치에서 접근할 수 있는 AP들을 find 후 각각 연결의 총량을 return
		ArrayList<AP> possibleA = new ArrayList<>();
		ArrayList<AP> possibleB = new ArrayList<>();
		
		for(AP tmpAP : ap) {
			if(dist(A,tmpAP.pos) <= tmpAP.charge) {
				possibleA.add(tmpAP);
			}
		}
		
		for(AP tmpAP : ap) {
			if(dist(B,tmpAP.pos) <= tmpAP.charge) {
				possibleB.add(tmpAP);
			}
		}
		
		Collections.sort(possibleA);
		Collections.sort(possibleB);
		
		int power1 = 0;			
		int power2 = 0;			
		
		for(AP a : possibleA) {
			if(!a.visited) {
				a.visited = true;
				power1 += a.power;
				break;
			}
		}
		
		for(AP a : possibleB) {
			if(!a.visited) {
				a.visited = true;
				power1 += a.power;
				break;
			}
		}
		
		for(AP a : ap) a.visited = false;
		
		for(AP a : possibleB) {
			if(!a.visited) {
				a.visited = true;
				power2 += a.power;
				break;
			}
		}
		
		for(AP a : possibleA) {
			if(!a.visited) {
				a.visited = true;
				power2 += a.power;
				break;
			}
		}
		
		for(AP a : ap) a.visited = false;
		
		return power1 > power2 ? power1:power2;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(st.nextToken());
		
		for(int t=1; t<=T; ++t) {
			int M, A;
			
			st = new StringTokenizer(br.readLine());
			M = Integer.parseInt(st.nextToken());
			A = Integer.parseInt(st.nextToken());
			ap = new ArrayList<>();			
			
			int moveA[] = new int[M];
			int moveB[] = new int[M];
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<M; i++) moveA[i] = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<M; i++) moveB[i] = Integer.parseInt(st.nextToken());
			
			
			for(int i=0; i<A; i++) {  // input
				st = new StringTokenizer(br.readLine());
				int tmp[] = new int[4];
				for(int j=0; j<4; j++) {
					tmp[j] = Integer.parseInt(st.nextToken());
				}
				AP tap = new AP(tmp[0], tmp[1], tmp[2], tmp[3]);
				ap.add(tap);
			}
			
			int ans = 0;
			
			Pos posA = new Pos(1,1);
			Pos posB = new Pos(10,10);
			
			ans += findAP(posA, posB);
			
			for(int i=0; i<M; i++) {
				int directionA = moveA[i];
				int directionB = moveB[i];
				posA.x = posA.x + dirX[directionA];
				posA.y = posA.y + dirY[directionA];
				
				posB.x = posB.x + dirX[directionB];
				posB.y = posB.y + dirY[directionB];
				ans += findAP(posA, posB);
				
			}
			sb.append("#" + t + " " + ans + "\n");
		}
		
		System.out.println(sb.toString());
		br.close();
	}

}