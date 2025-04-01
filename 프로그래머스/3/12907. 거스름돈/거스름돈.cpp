#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1e+9+7;
// 12:00
// dp[i]: 금액 i를 만들 수 있는 경우의 수
ll dp[100001];

// 인덱스(사용한 돈의 개수)와 금액이 같다면 앞으로의 관점에선 같은 경우
// dp[i][j] = dp[i-1][j]
int solution(int n, vector<int> money) {
    int answer = 0;
    
    // 근데 중복 제거 필요?
    sort(money.begin(), money.end());
    money.erase(unique(money.begin(), money.end()), money.end());
    
    dp[0] = 1;
    
    for(int coin : money) {
        for(int i = coin; i <= n; i++) {
            dp[i] += dp[i-coin];
            dp[i] %= MOD;
        }
    }
    
    answer = dp[n];
    
    return answer;
}

