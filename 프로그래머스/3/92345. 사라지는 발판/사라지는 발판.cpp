#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef pair<int,bool> pib;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
const int INF = 1e+8;

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;
    int n = board.size();
    int m = board[0].size();
    
    function<pib(pii, pii, int, bool)> solve;
    
    // bool이 0이면 A, 1이면 B
    solve = [&](pii pa, pii pb, int cnt, bool turn) -> pib {
        int y, x, ny, nx;
        int winCnt = INF, loseCnt = -1;

        if(!turn) {
            y = pa.first;
            x = pa.second;
        } else {
            y = pb.first;
            x = pb.second;
        }

        if(!board[y][x]) return {cnt, !turn};

        bool isPlayable = 0;
        for(int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];

            if(!(0 <= ny && ny < n && 0 <= nx && nx < m)) continue;
            if(!board[ny][nx]) continue;

            isPlayable = 1;
            pib res;
            board[y][x] = 0;
            if(!turn) 
                res = solve({ny,nx}, pb, cnt+1, !turn);
            else
                res = solve(pa, {ny,nx}, cnt+1, !turn);

            board[y][x] = 1;

            if(turn == res.second) // 내가 이긴 경우
                winCnt = min(winCnt, res.first);
            else // 상대방이 이긴 경우
                loseCnt = max(loseCnt, res.first);
        }
        
        if(!isPlayable) return {cnt, !turn};

        if(winCnt == INF) return {loseCnt, !turn};
        else return {winCnt, turn};
    };
    

    answer = solve({aloc[0], aloc[1]}, {bloc[0], bloc[1]}, 0, 0).first;
    return answer;
}