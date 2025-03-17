#include <bits/stdc++.h>

using namespace std;
string dp[51][51][2501];
int dr[4] = {1,0,0,-1};
int dc[4] = {0,-1,1,0};
char cc[4] = {'d','l','r','u'};
int destR, destC, rSize, cSize, kSize;

string solve(int r, int c, int depth) {
    // cout << r << c << depth << '\n';
    string &ret = dp[r][c][depth];
    if(depth == kSize && r == destR && c == destC) {
        return ret = "";
    }
    if(depth == kSize) {
        return ret = "impossible";
    }

    if(ret.compare(".") != 0) return ret;

    ret = "";
    int nr, nc;
    for(int i = 0; i < 4; i++) {
        nr = r + dr[i];
        nc = c + dc[i];
        if(1 <= nr && nr <= rSize && 1 <= nc && nc <= cSize) {
            if(solve(nr,nc,depth+1).compare("impossible") != 0) {
                return ret = cc[i] + solve(nr,nc,depth+1);
            }
        }
    }
    return ret = "impossible";
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    destR = r; destC = c;
    rSize = n; cSize = m;
    kSize = k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int t = 0; t <= k; t++) {
                dp[i][j][t] = ".";
            }
        }
    }
    answer = solve(x, y, 0);
    return answer;
}