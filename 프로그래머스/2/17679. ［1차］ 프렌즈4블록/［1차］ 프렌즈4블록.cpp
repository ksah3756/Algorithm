#include <bits/stdc++.h>

using namespace std;
bool isDeleted[31][31];

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(1) {
        bool isEnd = 1;
        for(int i = 0; i < m-1; i++) {
            for(int j = 0; j < n-1; j++) {
                if(board[i][j] != ' ' &&
                   board[i][j] == board[i+1][j] && 
                   board[i][j] == board[i][j+1] &&
                   board[i][j] == board[i+1][j+1]) {
                    isEnd = 0;
                    isDeleted[i][j] = 1;
                    isDeleted[i+1][j] = 1;
                    isDeleted[i][j+1] = 1;
                    isDeleted[i+1][j+1] = 1;
                }
            }
        }
        
        if(isEnd) break;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isDeleted[i][j]) {
                    board[i][j] = ' ';
                    answer++;
                }
            }
        }
        
        for(int j = 0; j < n; j++) {
            int h = m-1; // 블록이 없는 시작위치
            for(int i = m-1; i >= 0; i--) {
                if(board[i][j] == ' ') continue;
                swap(board[h--][j], board[i][j]);
            }
        }
        
        memset(isDeleted, 0, sizeof(isDeleted));
    }
    
    return answer;
}