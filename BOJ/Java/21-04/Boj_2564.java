import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Boj_2564 {

	static class Point{
		int x,y, dir;
		
		public Point(int x, int y, int dir) {
			this.x = x;
			this.y = y;
			this.dir = dir;
		}
	}
	
	static int c;
	static int r;
	public static int distToPoint(Point x, Point b) {
		int dist = 0;

		if(x.dir == b.dir) {
			dist += Math.abs(x.x-b.x) + Math.abs(x.y-b.y);
		}

		else {
			if(x.x + b.x < r) dist += x.x+b.x;
			else dist += 2*r - x.x - b.x;
			
			if(x.y + b.y < c) dist += x.y + b.y;
			else dist += 2*c - x.y - b.y;
			
		}
			
		if(dist > r+c) dist = r+c-dist;
		return dist;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		

		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		ArrayList<Point> l = new ArrayList<>();
		
		Point xp = null;
		
		for(int i=0; i<=n; i++) {
			st = new StringTokenizer(br.readLine());
			int direction = Integer.parseInt(st.nextToken());
			int dist = Integer.parseInt(st.nextToken());
			Point tp = null;
			switch(direction) {
			case 1:
				tp = new Point(dist,c, direction);
				break;
			case 2:
				tp = new Point(dist,0, direction);
				break;
			case 3:
				tp = new Point(0,c-dist, direction);
				break;
			case 4:
				tp = new Point(r,c-dist, direction);
				break;
			}
			
			if(i < n) l.add(tp);
			else xp = tp;
		}
		int cnt = 0;
		for(Point p : l) {
			cnt += distToPoint(p, xp);
		}
		sb.append(cnt);
		System.out.println(sb.toString());
		br.close();
	}

}