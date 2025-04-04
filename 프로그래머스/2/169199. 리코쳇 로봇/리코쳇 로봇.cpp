#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
// 11:20
// 방문 처리를 어캐해야하지..?
// y,x 위치와 방향을 함께 저장하면 될려나..?
// 아니다 그냥 어짜피 갈 수 있는 건 한정되어 있으니 그냥 방문처리
bool visited[101][101];
int graph[101][101];
pii start, dest;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int n, m;

pii move(const pii& p, int i) {
    int y = p.first;
    int x = p.second;
    
    while(0 <= y && y < n && 0 <= x && x < m && graph[y][x] == 0) {
        y += dy[i];
        x += dx[i];
    }
    y -= dy[i];
    x -= dx[i];
    
    return {y,x};
}

int solution(vector<string> board) {
    int answer = 0;
    n = board.size();
    m = board[0].size();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'D') graph[i][j] = 1;
            else if(board[i][j] == 'R') start = {i,j};
            else if(board[i][j] == 'G') dest = {i,j};
        }
    }
    
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = 1;
    
    int cnt = -1;
    bool isPossible = 0;
    while(!q.empty()) {
        if(isPossible) break;
        cnt++;
        int loopSize = q.size();
        for(int i = 0; i < loopSize; i++) {
            pii cur = q.front(); q.pop();
            // cout << cur.first << ' ' << cur.second << ' ' << cnt << '\n';
            if(cur == dest) {
                // cout << cur.first << ' ' << cur.second << ' ' << cnt << '\n';
                isPossible = 1;
                break;
            }
            for(int j = 0; j < 4; j++) {
                pii nxt = move(cur, j);
                if(!visited[nxt.first][nxt.second]) {
                    visited[nxt.first][nxt.second] = 1;
                    q.push(nxt);
                }
            }
        }
    }
    
    isPossible ? answer = cnt : answer = -1;
    return answer;
}

