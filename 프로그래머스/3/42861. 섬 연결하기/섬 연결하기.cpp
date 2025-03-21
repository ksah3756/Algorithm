#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct Edge {
    int src, dest, cost;
    Edge(int src, int dest, int cost) : src(src), dest(dest), cost(cost) {};
} Edge;

typedef struct Cmp {
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.cost > e2.cost;
    }
} Cmp;

int parent[101];

int find(int n) {
    if(n == parent[n]) return n;
    return parent[n] = find(parent[n]);
}

bool union_set(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    
    if(pa == pb) return false;
    
    parent[pb] = pa;
    return true;
}

// MST
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    priority_queue<Edge, vector<Edge>, Cmp> pq;
    
    for(auto v : costs) {
        pq.push(Edge(v[0], v[1], v[2]));
    }
    
    for(int i = 0; i < n; i++) parent[i] = i;
    
    int cnt = 0;
    while(cnt < n-1) {
        Edge e = pq.top(); pq.pop();
        if(union_set(e.src, e.dest)) {
            cnt++;
            answer += e.cost;   
        }
    }
    return answer;
}