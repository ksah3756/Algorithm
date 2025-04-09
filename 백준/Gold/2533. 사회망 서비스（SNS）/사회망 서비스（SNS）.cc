#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> pii;
int n;
vector<int> graph[1000001];
bool visited[1000001];
pii dfs(int);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int u, v;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    pii ans = dfs(1);
    cout << min(ans.first, ans.second) << '\n';
    return 0;
}

pii dfs(int curr){
    pii ret = {1,0};
    visited[curr] = 1;
    for(int next : graph[curr]){
        if(!visited[next]){
            pii tmp = dfs(next);
            ret.first += min(tmp.first, tmp.second);
            ret.second += tmp.first;
        }
    }
    return ret;
}