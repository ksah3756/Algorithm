#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#define INF 200000000
using namespace std;
int graph[16][16];
int dp[(1 << 16) - 1][16];
int n;
int tsp(int, int);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i, j, t;
    cin >> n;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cin >> t;
            graph[i][j] = t;
        }
    }
    cout << tsp(1, 0) << '\n';
    return 0;
}

int tsp(int visited, int curr){
    int i;
    int& ret = dp[visited][curr];
    //cout << bitset<4> (visited) << ' ' << curr << ' ' << dist << '\n';
    if(visited == ((1<<n)-1) && graph[curr][0]){
        return graph[curr][0];
    }
    if(ret) return ret;
    ret = INF;
    for(i = 1; i < n; i++){
        /*int visit = visited & (1 << i);
        cout << "visit : "<< visit << '\n';*/
        if(!(visited & (1 << i)) && graph[curr][i]){
            visited = visited | (1 << i);
            int cand = tsp(visited, i) + graph[curr][i];
            // 이제 i를 마지막으로 visited 했을 때 나올 수 있는 경우는 다 탐색
            // ret : i에서 0까지 순회했을 때 거리, cand : curr에서 0까지 순회했을 때 거리
            ret = min(ret, cand);
            //cout << bitset<4>(visited) << ' ' << i << ' ' << dp[visited][i] << '\n';
            visited = visited & ~(1 << i);
        }
    }
    dp[visited][curr] = ret;
    return ret;
}