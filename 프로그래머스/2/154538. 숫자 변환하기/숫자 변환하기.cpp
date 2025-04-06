#include <string>
#include <vector>

using namespace std;
// 2:00
const int INF = 1e+6+1;
int solution(int x, int y, int n) {
    int answer = 0;
    vector<int> dp(y+1, INF);
    // dp[i] = if(i%2) dp[i/2], if(i%3) dp[i/3] if(i>=n+x) dp[i-n]
    
    dp[x] = 0;
    for(int i = x+1; i <= y; i++) {
        if(i%2 == 0) dp[i] = min(dp[i], dp[i/2]+1);
        if(i%3 == 0) dp[i] = min(dp[i], dp[i/3]+1);
        if(i >= x+n) dp[i] = min(dp[i], dp[i-n]+1);
    }
    
    dp[y] == INF? answer = -1 : answer = dp[y];
    return answer;
}