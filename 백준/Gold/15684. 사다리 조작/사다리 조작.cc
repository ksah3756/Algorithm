#include <bits/stdc++.h>

using namespace std;
int h, n, m;
bool ladder[11][31][2]; // 왼쪽 or 오른쪽
bool solve(int);
bool checkIfPossible();
int cnt, depth;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        ladder[b][a][1] = 1;
        ladder[b+1][a][0] = 1;
    }
    
    cnt = 0;
    while(cnt <= 3) {
        depth = 0;
        if(solve(1)) {
            cout << cnt << '\n';
            return 0;
        }
        cnt++;
    }
    cout << -1 << '\n';
    return 0;
}

bool solve(int sx) {
    if(depth == cnt) {
        return checkIfPossible();
    }

    for(int i = sx; i < n; i++) { // 1~n-1에 대해 오른쪽으로만 사다리 설치 할 수 있는지 체크 아놔 조합으로 해야하는데 순열로 풀고있었네
        for(int j = 1; j <= h; j++) {
            if(!ladder[i][j][1]) {
                if(i == n-1) {
                    ladder[i][j][1] = 1;
                    ladder[i+1][j][0] = 1;
                    depth++;
                    if(solve(i)) return true;
                    ladder[i][j][1] = 0;
                    ladder[i+1][j][0] = 0;
                    depth--;
                } else {
                    if(!ladder[i+1][j][1]) {
                        ladder[i][j][1] = 1;
                        ladder[i+1][j][0] = 1;
                        depth++;
                        if(solve(i)) return true;
                        ladder[i][j][1] = 0;
                        ladder[i+1][j][0] = 0;
                        depth--;
                    }
                }
            }
        }
    }
    return false;
}

bool checkIfPossible() {
    for(int i = 1; i <= n; i++) {
        int x = i, y = 1;
        while(y <= h) {
            if(ladder[x][y][0]) x--;
            else if(ladder[x][y][1]) x++;
            y++;
        }
        if(x != i) return false;
    }
    return true;
}