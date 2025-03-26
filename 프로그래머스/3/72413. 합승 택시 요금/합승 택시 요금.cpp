#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
// 11:00
// 합승을 한다는건 특정 지점까지는 돈을 한번만 내는거고
// S, A, B 각 지점에서 나머지 노드까지 최단 거리를 구하고 모든 중간 지점에 대해 값을 더해봐서 최소값을 구하기

const int INF = INT_MAX;
vector<vector<pii>> cost(201, vector<pii>());
int dist[3][201];

void dijkstra(int start, int idx) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    
    while(!pq.empty()) {
        pii p = pq.top(); pq.pop();
        int ccost = p.first;
        int cur = p.second;
        if(ccost >= dist[idx][cur]) continue;
        dist[idx][cur] = ccost;
        
        for(const pii& p : cost[cur]) {
            int nxt = p.first;
            int ccost = p.second;
            if(dist[idx][nxt] > dist[idx][cur] + ccost) {
                pq.push({dist[idx][cur] + ccost, nxt});
            }
        }
    } 
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    for(const vector<int>& v: fares) {
        cost[v[0]].push_back({v[1], v[2]});
        cost[v[1]].push_back({v[0], v[2]});
    }
    
    fill_n(&dist[0][0], 3 * 201, INF);
    
    dijkstra(s, 0);
    dijkstra(a, 1);
    dijkstra(b, 2);
    
    answer = dist[0][a] + dist[0][b];
    
    for(int i = 1; i <= n; i++) {
        if(dist[0][i] == INF || dist[1][i] == INF || dist[2][i] == INF) continue;
        answer = min(answer, dist[0][i] + dist[1][i] + dist[2][i]);
    }
    
    return answer;
}

