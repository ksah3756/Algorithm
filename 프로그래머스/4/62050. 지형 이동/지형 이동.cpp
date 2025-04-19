#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

// 9:42
// 사다리 없이 갈 수 있는 구역은 bfs로 구할 수 있는데
// 최소 설치비용은 mst
// 구간이 인접하면 그 중 최소값이 간선
int color[301][301];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int parent[90001];

int find(int n) {
    if(n == parent[n]) return n;
    return parent[n] = find(parent[n]);
}

bool unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    
    if(pa == pb) return false;
    
    parent[pb] = pa;
    return true;
}

typedef struct Edge {
    int dist, n1, n2;
    Edge(int n1, int n2, int dist) : n1(n1), n2(n2), dist(dist) {}
} Edge;

struct cmp {
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.dist > e2.dist;
    }
};

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    
    int n = land.size();
    
    auto checkBoundary = [&](int y, int x) -> bool {
        if(0 <= y && y < n && 0 <= x && x < n) return true;
        return false;
    };
    
    auto calculateDiff = [&](int y1, int x1, int y2, int x2) -> int {
        return abs(land[y1][x1] - land[y2][x2]);
    };
    
    int c = 1;
    int x, y, nx, ny;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!color[i][j]) {
                color[i][j] = c;
                queue<pii> q;
                q.push({i,j});
                
                while(!q.empty()) {
                    pii cur = q.front(); q.pop();
                    y = cur.first;
                    x = cur.second;
                    
                    for(int k = 0; k < 4; k++) {
                        ny = y + dy[k];
                        nx = x + dx[k];
                        
                        if(checkBoundary(ny,nx)) {
                            if(!color[ny][nx] && calculateDiff(y, x, ny, nx) <= height) {
                                color[ny][nx] = c;
                                q.push({ny,nx});
                            }
                        }
                    }
                }
                c++;
            }
        }
    }
    
    c--;
    for(int i = 1; i <= c; i++) parent[i] = i;
    
    map<pii, int> map;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            y = i; x = j;
            
            for(int k = 0; k < 4; k++) {
                ny = y + dy[k];
                nx = x + dx[k];
                
                if(checkBoundary(ny,nx)) {
                    int c1 = color[ny][nx];
                    int c2 = color[y][x];
                    if(c1 != c2) {
                        int diff = calculateDiff(ny,nx,y,x);
                        if(c1 > c2) swap(c1,c2);
                        if(map.find({c1,c2}) == map.end()) map[{c1,c2}] = diff;
                        else {
                            if(map[{c1,c2}] > diff) map[{c1,c2}] = diff;
                        }
                    }
                }
            } 
        }
    }
    
    int edgeSize = 0;
    priority_queue<Edge, vector<Edge>, cmp> pq;
    
    for(auto iter = map.begin(); iter != map.end(); iter++) {
        int n1 = iter->first.first;
        int n2 = iter->first.second;
        int dist = iter->second;
        
        pq.push(Edge(n1, n2, dist));
    }
    
    while(!pq.empty()) {
        Edge e = pq.top(); pq.pop();
        // cout << e.n1 << ' ' << e.n2 << ' ' << e.dist << '\n';
        
        if(unionSet(e.n1, e.n2)) {
            edgeSize++;
            answer += e.dist;
        }
        
        if(edgeSize == c-1) break;
    }
    
    return answer;
}