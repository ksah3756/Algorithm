import java.io.*;
import java.util.*;

public class Main {
    static class Node {
        int idx, cost;
        Node(int idx, int cost) {
            this.idx = idx;
            this.cost = cost;
        }
    }
    static ArrayList<Integer>[] graph1 = new ArrayList[1001];
    static ArrayList<Integer>[] graph2 = new ArrayList[1001];
    static int[][] cost1 = new int[1001][1001];
    static int[][] cost2 = new int[1001][1001];
    static int[] dist1 = new int[1001];
    static int[] dist2 = new int[1001];
    static final int INF = (int)1e+8;
    static int n, x, m;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
    
        Arrays.fill(dist1, INF);
        Arrays.fill(dist2, INF);

        for(int i = 1; i <= n; i++) {
            graph1[i] = new ArrayList<>();
            graph2[i] = new ArrayList<>();
        }

        int a, b, t;
        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            t = Integer.parseInt(st.nextToken());
            graph1[a].add(b);
            graph2[b].add(a);
            cost1[a][b] = t;
            cost2[b][a] = t;
        }

        dijkstra1();
        dijkstra2();

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = Integer.max(ans, dist1[i] + dist2[i]);
        }
        System.out.println(ans);
    }

    public static void dijkstra1() {
        dist1[x] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>((n1, n2) -> Integer.compare(n1.cost, n2.cost));
        pq.offer(new Node(x, 0));
        while(!pq.isEmpty()) {
            Node node = pq.poll();
            int cur = node.idx;
            int ccost = node.cost;
            if(ccost > dist1[cur]) continue;
            
            for(int nxt : graph1[cur]) {
                int newCost = ccost + cost1[cur][nxt];
                if(dist1[nxt] > newCost) {
                    dist1[nxt] = newCost;
                    pq.offer(new Node(nxt, newCost));
                }
            }
        }
    }

    public static void dijkstra2() {
        dist2[x] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>((n1, n2) -> Integer.compare(n1.cost, n2.cost));
        pq.offer(new Node(x, 0));
        while(!pq.isEmpty()) {
            Node node = pq.poll();
            int cur = node.idx;
            int ccost = node.cost;
            if(ccost > dist2[cur]) continue;
            
            for(int nxt : graph2[cur]) {
                int newCost = ccost + cost2[cur][nxt];
                if(dist2[nxt] > newCost) {
                    dist2[nxt] = newCost;
                    pq.offer(new Node(nxt, newCost));
                }
            }
        }
    }


}
