#include <bits/stdc++.h>
#define MAX_SIZE (int)15e+5+2

using namespace std;
int t[MAX_SIZE], p[MAX_SIZE];
int dp[MAX_SIZE]; // dp[i] -> i번째 날이 되었을 때 최대 수익
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[i-1]); // 일하기 전이므로 그냥 전날 일을 안하고 넘어갈 수 있음
        int day = i+t[i];
        if(day <= n+1) {
            dp[day] = max(dp[day], dp[i] + p[i]); 
            ans = max(ans, dp[day]);
        }
    }
    // for(int i = 1; i <= n+1; i++) cout << dp[i] << ' ';
    // cout << '\n';
    cout << ans << '\n';
    return 0;
}

