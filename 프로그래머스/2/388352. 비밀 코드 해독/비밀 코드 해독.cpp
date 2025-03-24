#include <bits/stdc++.h>

using namespace std;
vector<int> codes;
int ansCnt, N;

//11:48
// 30C5해서 시스템 응답이랑 일치하는지 확인
int solution(int n, vector<vector<int>> q, vector<int> ans)  {
    int answer = 0;
    vector<int> codes(n);
    
    for(int i = 0; i < 5; i++) {
        codes[n-1-i] = 1;
    }
    
    bool isPossible;
    do {
        for(int i = 0; i < q.size(); i++) {
            int cnt = 0;
            isPossible = 1;
            for(int j = 0; j < 5; j++) {
                int idx = q[i][j]-1;
                cnt += codes[idx];
            }
            if(cnt != ans[i]) {
                isPossible = 0;
                break;
            }
        }
        if(isPossible) answer++;
    } while(next_permutation(codes.begin(), codes.end()));
    
    return answer;
}



