#include <bits/stdc++.h>

using namespace std;
// 2:30
// 어떤 특정 행, 열에 대하여 짝수번(0,2,..) flip / 홀수번 flip 에 따라 달라짐
// 똑같은 행, 열을 두번 flip 할 필요는 없음
// 그러면 최대 20번만 flip 해보면 되는건가?
// 이분 탐색으로 flip 횟수를 미리 정해서 가능하면 왼쪽, 불가능하면 오른쪽으로?
// 근데 이건 20번 내의 문제가 아니라 depth의 문제인데
// 걍 브루트포스?
int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = -1;
    
    int n = target.size();
    int m = target[0].size();
    
    auto flipCoins = [&](const vector<int>& flips) -> bool {
        vector<vector<int>> board = beginning;
        
        for(int i = 0; i < n+m; i++) {
            if(!flips[i]) continue;
            
            if(i < n) { // 행
                for(int j = 0; j < m; j++) {
                    board[i][j] = 1 - board[i][j];
                }

            } else { // 열
                for(int j = 0; j < n; j++) {
                    board[j][i-n] = 1 - board[j][i-n];
                }
            }
        }
        
        bool ret = 1;
        for(int i = 0; i < n; i++) {
            if(!ret) break;
            for(int j = 0; j < m; j++) {
                if(target[i][j] != board[i][j]) {
                    ret = 0;
                    break;
                }
            }
        }
        return ret;
    };
    
    for(int i = 0; i <= n+m; i++) {
        vector<int> flips;
        for(int j = 0; j < n+m-i; j++) flips.push_back(0);
        for(int j = 0; j < i; j++) flips.push_back(1);
        
        do { 
            if(flipCoins(flips)) {
                return i;
            }
        } while(next_permutation(flips.begin(), flips.end()));
    }
      
    return answer;
}