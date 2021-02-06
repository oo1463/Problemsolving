package swea_1223;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		for(int t=1; t<=10; ++t) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			
			String s = br.readLine();
			Stack<Integer> stack1 = new Stack<Integer>();
			
			for(int i=0; i<n; i++) {
				char c = s.charAt(i);
				if(c >= '0' && c <= '9') stack1.add(c-'0');
				else if(c == '*'){
					int p1 = stack1.pop();
					int p2 = s.charAt(++i)-'0';
					stack1.add(p1*p2);
				}
			}
			
			int sum = 0;
			while(!stack1.isEmpty()) sum+=stack1.pop();

			sb.append("#"+t+" ").append(sum).append("\n");
		}
		
		System.out.println(sb.toString());
		br.close();
	}
	

}