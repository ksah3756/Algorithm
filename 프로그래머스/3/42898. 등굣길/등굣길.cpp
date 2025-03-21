#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e+9+7;

ll dp[101][101];

bool checkIfPossible(const vector<vector<int>>& puddles, int x, int y) {
    bool flag = 1;
    for(const auto &v : puddles) {
        if(v[0]-1 == x && v[1]-1 == y) {
            flag = 0;
            break;
        }
    }
    return flag;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    // dp[i][j] = dp[i-1][j] + dp[i][j-1]
    
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0) continue;
            if(!checkIfPossible(puddles, j, i)) continue;
            dp[i][j] = 0;
            if(i-1 >= 0 && checkIfPossible(puddles, j, i-1)) 
                dp[i][j] += dp[i-1][j];
            if(j-1 >= 0 && checkIfPossible(puddles, j-1, i)) 
                dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }
    
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    answer = dp[n-1][m-1];
    return answer;
}