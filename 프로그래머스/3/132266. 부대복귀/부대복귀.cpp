#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int INF = 5e+6+1;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<vector<int>> adj(n+1, vector<int>());
    vector<int> dist(n+1, INF);
    
    for(const vector<int>& v : roads) {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    
    priority_queue<pii> pq;
    pq.push({0, destination});
    
    while(!pq.empty()) {
        pii p = pq.top(); pq.pop();
        int cur = p.second;
        int cost = -p.first;
        if(dist[cur] <= cost) continue;
        dist[cur] = cost;
        
        for(int nxt : adj[cur]) {
            if(dist[nxt] > cost + 1) {
                pq.push({-(cost+1), nxt});
            }
        }
    }
    
    for(int s : sources) {
        dist[s] == INF ? answer.push_back(-1) : answer.push_back(dist[s]);
    }
    
    return answer;
}