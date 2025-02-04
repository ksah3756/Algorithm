import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n, m, k;
    static boolean[] visited = new boolean[51];
    static int[] parent = new int[51];
    static int[] arr = new int[51];
    static int[] party = new int[51];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for(int i = 1; i <= n; i++) parent[i] = i;

        st = new StringTokenizer(br.readLine());
        k = Integer.parseInt(st.nextToken());
        
        int x;
        for(int i = 0; i < k; i++) {
            x = Integer.parseInt(st.nextToken());
            visited[x] = true;
        }

        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
    
            for(int j = 0; j < x; j++) {
                arr[j] = Integer.parseInt(st.nextToken());
            }
            int idx = 0;
            party[i] = arr[0];
            while(idx < x-1) {
                unionSet(arr[idx], arr[idx+1]);
                idx++;
            }
        }
        int cnt = m;
        for(int j = 1; j <= n; j++) {
            if(visited[j]) visited[find(j)] = true;
        }
        for(int j = 0; j < m; j++) {
            if(visited[find(party[j])]) cnt--;
        }
        System.out.println(cnt);
    }

    public static int find(int n) {
        if(n == parent[n]) return n;
        return parent[n] = find(parent[n]);
    }

    public static void unionSet(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return;
        parent[pb] = pa;
    }
}
