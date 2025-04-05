#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
bool visited[101][101];
// 10:20
// S->L, L->E 두 경로 최단거리 합
int solution(vector<string> maps) {
    int answer = 0;
    
    pii start, lever, end;
    int n = maps.size();
    int m = maps[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maps[i][j] == 'S') start = {i,j};
            else if(maps[i][j] == 'E') end = {i,j};
            else if(maps[i][j] == 'L') lever = {i,j};
        }
    }
    
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = 1;
    
    int cnt = -1;
    int y, x, ny, nx;
    bool isPossible = 0;
    while(!q.empty()) {
        if(isPossible) break;
        cnt++;
        int loopSize = q.size();
        for(int i = 0; i < loopSize; i++) {
            pii cur = q.front(); q.pop();
            y = cur.first; x = cur.second;
            if(y == lever.first && x == lever.second) {
                isPossible = 1;
                break;
            }
            for(int j = 0; j < 4; j++) {
                ny = y + dy[j];
                nx = x + dx[j];
                if(0 <= ny && ny < n && 0 <= nx && nx < m) {
                    if(maps[ny][nx] != 'X' && !visited[ny][nx]) {
                        visited[ny][nx] = 1;
                        q.push({ny,nx});
                    }
                }
            }
        }
    }
    if(isPossible) answer += cnt;
    else return -1;
    
    q = queue<pii>();
    q.push(lever);
    memset(visited, 0, sizeof(visited));
    visited[lever.first][lever.second] = 1;
    
    cnt = -1;
    isPossible = 0;
    while(!q.empty()) {
        if(isPossible) break;
        cnt++;
        int loopSize = q.size();
        for(int i = 0; i < loopSize; i++) {
            pii cur = q.front(); q.pop();
            y = cur.first; x = cur.second;
            if(y == end.first && x == end.second) {
                isPossible = 1;
                break;
            }
            for(int j = 0; j < 4; j++) {
                ny = y + dy[j];
                nx = x + dx[j];
                if(0 <= ny && ny < n && 0 <= nx && nx < m) {
                    if(maps[ny][nx] != 'X' && !visited[ny][nx]) {
                        visited[ny][nx] = 1;
                        q.push({ny,nx});
                    }
                }
            }
        }
    }
    if(isPossible) answer += cnt;
    else return -1;
    
    return answer;
}