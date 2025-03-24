#include <string>
#include <vector>

using namespace std;
vector<int> codes;
int ansCnt, N;

//11:48
// 30C5해서 시스템 응답이랑 일치하는지 확인
void solve(const vector<vector<int>> &q, const vector<int>& ans, int cur) {
    if(codes.size() == 5) {
        bool isPossible = 1;
        for(int i = 0; i < q.size(); i++) {
            int i1 = 0, i2 = 0, cnt = 0;
            while(i1 < 5 && i2 < 5) {
                if(q[i][i1] == codes[i2]) {
                    cnt++;
                    i1++; i2++;
                } else if(q[i][i1] > codes[i2]) {
                    i2++;
                } else {
                    i1++;
                }
            }
            if(cnt != ans[i]) {
                isPossible = 0;
                break;
            }
        }
        if(isPossible) ansCnt++;
    }
    
    for(int i = cur; i <= N; i++) {
        codes.push_back(i);
        solve(q, ans, i+1);
        codes.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    N = n;
    solve(q, ans, 1);
    answer = ansCnt;
    return answer;
}


