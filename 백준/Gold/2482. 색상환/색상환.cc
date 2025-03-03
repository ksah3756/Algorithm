#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, k;
ll dp[1001][1001]; // i번째 인덱스까지 중 j개를 선택했으면 같은 경우
const ll MOD = 1e+9+3;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    // 일단 i번째 인덱스 까지면 최대 i/2개 만큼 선택할 수 있음
    // 문제는 원형이기 때문에 1과 n이 둘다 선택된 경우는 제외해야 하는데...
    for(int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    
    for(int i = 3; i <= n; i++) {
        for(int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % MOD;
        }
    }
    // n을 선택할거면 1번과 n-1 은 무조건 제외이므로 2~n-2 까지 중 k-1개 선택하면 됨
    ll ans = (dp[n-1][k] + dp[n-3][k-1]) % MOD;
    cout << ans << '\n';
    return 0;
}

