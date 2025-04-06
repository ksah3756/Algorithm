#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> map(n, vector<int>(m, 0));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maps[i][j] != 'X') {
                map[i][j] = maps[i][j] - '0';
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] > 0) {
                int cnt = map[i][j];
                queue<pii> q;
                q.push({i,j});
                map[i][j] = -1;
                
                while(!q.empty()) {
                    pii cur = q.front(); q.pop();
                    int y = cur.first;
                    int x = cur.second;
                    for(int k = 0; k < 4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if(0<= ny && ny < n && 0 <= nx && nx < m) {
                            if(map[ny][nx] > 0) {
                                cnt += map[ny][nx];
                                map[ny][nx] = -1;
                                q.push({ny,nx});
                            }
                        }
                    }
                }
                answer.push_back(cnt);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    if(answer.empty()) answer.push_back(-1);
    return answer;
}