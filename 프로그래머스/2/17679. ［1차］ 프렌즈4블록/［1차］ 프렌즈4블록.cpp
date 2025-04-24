#include <bits/stdc++.h>

using namespace std;

// 각 블록에 대해 내 밑에 빈 공간의 개수가 몇개인지 파악하면 그만큼 내리면 됨
// 중복되지 않게 하기 위해선 밑에서부터 위로 순회하면서 밑으로 이동시키기
bool isDeleted[31][31];
int downCount[31][31];

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    vector<int> height(n, m);
    
    while(1) {
        bool isEnd = 1;
        for(int j = 0; j < n-1; j++) {
            int h = height[j];
            for(int i = 0; i < h-1; i++) {
                if(max({board[m-2-i][j], board[m-2-i][j+1], board[m-1-i][j], board[m-1-i][j+1]})
                     == min({board[m-2-i][j], board[m-2-i][j+1], board[m-1-i][j], board[m-1-i][j+1]})) {
                        isEnd = 0;
                         isDeleted[m-2-i][j] = 1; 
                         isDeleted[m-2-i][j+1] = 1;
                         isDeleted[m-1-i][j] = 1;
                         isDeleted[m-1-i][j+1] = 1;
                }
            }
        }
        
        if(isEnd) break;

        for(int j = 0; j < n; j++) {
            int idx = m-1, cnt = 0;
            int h = height[j];

            while(m-h <= idx && !isDeleted[idx--][j]);
            idx++;
            while(m-h <= idx) {
                while(m-h <= idx && isDeleted[idx--][j]) {
                    cnt++;
                    answer++;
                }
                idx++;
                while(m-h <= idx && !isDeleted[idx--][j]) {
                    downCount[idx][j] = cnt;
                }
                idx++;
            }

            for(int i = m-1; i >= m-h; i--) {
                int down = downCount[i][j];
                if(down) {
                    cout << j << ' ' << i << ' ' << down << '\n';
                    board[i+down][j] = board[i][j];
                }
            }
            height[j] -= cnt; 
        }
        
        memset(isDeleted, 0, sizeof(isDeleted));
        memset(downCount, 0, sizeof(downCount));
    }
            
    return answer;
}