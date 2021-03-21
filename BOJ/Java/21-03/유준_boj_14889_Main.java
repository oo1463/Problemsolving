package boj_14889;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int[][] s;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        s = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                s[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        System.out.println(solver(0, new ArrayList<>(), new ArrayList<>()));
        br.close();
    }

    static int solver(int currentPlayerIndex, List<Integer> teamA, List<Integer> teamB) {
        if (teamA.size() > n / 2 || teamB.size() > n / 2) {
            return Integer.MAX_VALUE;
        }
        if (currentPlayerIndex == n) {
            int scoreA = 0, scoreB = 0;
            for (int i = 0; i < n / 2; i++) {
                for (int j = 0; j < n / 2; j++) {
                    scoreA += s[teamA.get(i)][teamA.get(j)];
                    scoreB += s[teamB.get(i)][teamB.get(j)];
                }
            }
            return Math.abs(scoreA - scoreB);
        }

        teamA.add(currentPlayerIndex);
        int diff = solver(currentPlayerIndex + 1, teamA, teamB);
        teamA.remove(teamA.size() - 1);

        teamB.add(currentPlayerIndex);
        int temp = solver(currentPlayerIndex + 1, teamA, teamB);
        teamB.remove(teamB.size() - 1);
        if (temp < diff) {
            diff = temp;
        }

        return diff;
    }
}