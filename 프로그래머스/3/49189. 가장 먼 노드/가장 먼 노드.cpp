#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int dist[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(n+1, vector<int>());
    fill(dist, dist + 20001, -1);
    
    for(const auto &v : edge) {
        int src = v[0];
        int dest = v[1];
        
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    int cnt = 0;
    
    while(!q.empty()) {
        cnt++;
        int loopSize = q.size();
        for(int i = 0; i < loopSize; i++) {
            int cur = q.front(); q.pop();
            for(int nxt : graph[cur]) {
                if(dist[nxt] == -1) {
                    dist[nxt] = cnt;
                    q.push(nxt);
                }
            }
        } 
    }
    
    for(int i = 1; i <= n; i++) {
        if(dist[i] == cnt-1) answer++;
    }
    
    return answer;
}