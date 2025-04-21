#include <bits/stdc++.h>

using namespace std;

// 9:45
// 각 단계마다 내가 갈 수 있는 후보지를 저장?
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    int n = info.size();
    vector<vector<int>> child(n, vector<int>());
    
    for(const vector<int>& e : edges) {
        child[e[0]].push_back(e[1]);
    }
    
    function<int(int,int,int,int)> solve;
    
    solve = [&](int cur, int lambCnt, int wolfCnt, int candidates) -> int {
        int ret = -1;
        
        for(int c : child[cur]) {
          candidates = candidates | (1 << c);
        }  
    
        for(int i = 0; i < n; i++) {
            int isPossible = candidates & (1 << i);
            if(!isPossible) continue;
            if(info[i] + wolfCnt >= lambCnt) continue;
            ret = max(ret, solve(i, 1-info[i]+lambCnt, info[i]+wolfCnt, candidates & ~(1<<i)));
        }
        
        if(ret == -1) return lambCnt;
        return ret;
    };
    
    answer = solve(0,1,0,0);
    return answer;
}