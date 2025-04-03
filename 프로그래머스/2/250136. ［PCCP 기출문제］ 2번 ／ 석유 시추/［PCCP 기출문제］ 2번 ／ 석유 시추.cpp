#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;
typedef pair<int,int> pii;
// 6:42
// 영역별로 번호 할당하고 사이즈를 미리 저장해두면?
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int landSize[250001];
int solution(vector<vector<int>> land) {
    int answer = 0;
    int n = land.size();
    int m = land[0].size();
    
    int idx = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(land[i][j] == 1) {
                int cnt = 1;
                queue<pii> q;
                q.push({i,j});
                land[i][j] = -idx;
                while(!q.empty()) {
                    pii cur = q.front(); q.pop();
                    int y = cur.first, x = cur.second;
                    for(int k = 0; k < 4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if(0 <= ny && ny < n && 0 <= nx && nx < m) {
                            if(land[ny][nx] == 1) {
                                q.push({ny,nx});
                                cnt++;
                                land[ny][nx] = -idx;
                            }
                        }
                    }
                }
                landSize[idx++] = cnt;
            }
        }
    }
    
    for(int j = 0; j < m; j++) {
        int i = 0;
        unordered_set<int> s;
        int cnt = 0;
        
        while(i < n) {
            int val = -land[i][j];
            if(val != 0 && s.find(val) == s.end()) {
                cnt += landSize[val];
                s.insert(val);
            }
            i++;
        }
        answer = max(answer, cnt);
    }
    return answer;
}