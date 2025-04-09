#include <string>
#include <vector>

using namespace std;
typedef pair<int,int> pii;

// 자기 자신을 밝혔을 때, 자기 자신을 밝히지 않고 넘어갔을 때 두 경우에 대해
// dp를 사용할 수 있는지 없는지는 부분 최적 구조가 있느냐 없느냐인데
// dp[i] i 번째 노드를 루트로 했을 때 근데 이게 visited가 어떻게 되느냐에 따라 다른 경우 아닌가? 아 근데 루트 노드에서부터 계층적으로 계속 파고 들어가는거기 때문에 visited이 달라질 경우는 없겠다
vector<vector<int>> graph;
bool visited[100001];

pii dfs(int cur) {
    pii ret = {1,0};
    visited[cur] = 1;
    
    for(int nxt : graph[cur]) {
        if(!visited[nxt]) {
            pii res = dfs(nxt);
            // 자신이 불을 켰으르모 자식은 불을 키던 말던 상관 없음
            ret.first += min(res.first, res.second);
            // 자신이 불을 안켰으므로 자식이 반드시 켜야함
            ret.second += res.first;
        }
    }
    return ret;
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    
    graph.resize(n+1, vector<int>());
    
    for(const vector<int> v : lighthouse) {
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
    }
    
    pii res = dfs(1);
    answer = min(res.first, res.second);
    return answer;
}