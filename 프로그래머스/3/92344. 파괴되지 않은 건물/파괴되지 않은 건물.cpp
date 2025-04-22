#include <bits/stdc++.h>

using namespace std;

// 10:40
// 스킬 위치에 + , -기록해놓고 각 위치는 왼쪽, 위, 자신에서 더하는
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<int>> record(n+1, vector<int>(m+1, 0));
    
    int type, r1, c1, r2, c2, degree;
    for(const vector<int>& s : skill) {
        type = s[0];
        r1 = s[1];
        c1 = s[2];
        r2 = s[3];
        c2 = s[4];
        type == 1 ? degree = -s[5] : degree = s[5];
        record[r1][c1] += degree;
        record[r1][c2+1] -= degree;
        record[r2+1][c1] -= degree;
        record[r2+1][c2+1] += degree;
    }
    
    for(int i = 0; i < n; i++) {
        int prev = 0;
        for(int j = 0; j < m; j++) {
            record[i][j] += prev;
            prev = record[i][j];
        }
    }
    
    for(int j = 0; j < m; j++) {
        int prev = 0;
        for(int i = 0; i < n; i++) {
            record[i][j] += prev;
            prev = record[i][j];
            if(board[i][j] + prev > 0) answer++;
        }
    }
    return answer;
}