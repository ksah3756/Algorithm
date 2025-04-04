#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<vector<int>> graph(n+1, vector<int>());
    vector<bool> visited(n+1, 0);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(computers[i][j]) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            answer++;
            visited[i] = 1;
            queue<int> q;
            q.push(i);
            
            while(!q.empty()) {
                int cur = q.front(); q.pop();
                for(int nxt : graph[cur]) {
                    if(!visited[nxt]) {
                        visited[nxt] = 1;
                        q.push(nxt);
                    }
                }
            }
        }
    }
    
    
    return answer;
}