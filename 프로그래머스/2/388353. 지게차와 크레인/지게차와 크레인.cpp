#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

// 12:18
int arr[52][52];
bool visited[52][52];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

// 내 생각엔 0으로 감싸고 거기서 bfs를 해서 닿는지 확인해야 할거 같은데
int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    int n = storage.size(), m = storage[0].size();
    answer = n * m;
    
    for(int i = 0; i <= n+1; i++) {
        for(int j = 0; j <= m+1; j++) {
            if(i == 0 || j == 0 || i == n+1 || j == m+1) arr[i][j] = -1;
            else arr[i][j] = storage[i-1][j-1] - 'A';
        }
    }
    
    for(int i = 0; i < requests.size(); i++) {
        int target = requests[i][0] - 'A';
        if(requests[i].size() == 2) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    if(arr[i][j] == target) {
                        arr[i][j] = -1;
                        answer--;
                    }
                }
            }
        } else {
            memset(visited, 0, sizeof(visited));
            queue<pii> q;
            q.push({0,0});
            visited[0][0] = 1;
            while(!q.empty()) {
                pii cur = q.front(); q.pop();
                int y = cur.first, x = cur.second;

                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if(0 <= ny && ny <= n+1 && 0 <= nx && nx <= m+1) {
                        if(arr[ny][nx] == -1 && !visited[ny][nx]) {
                            visited[ny][nx] = 1;
                            q.push({ny,nx});
                        } else if(arr[ny][nx] == target) {
                            arr[ny][nx] = -1;
                            visited[ny][nx] = 1;
                            answer--;
                        }
                    }
                }
            }
        }   
    }
    return answer;
}