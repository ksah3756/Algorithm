#include <string>
#include <vector>

using namespace std;
typedef pair<int,int> pii;
pii dp[100001];
const int INF = 1e+7;
// 3:30
// dp같긴한데 횟수만 저장하는게 아니라
// dp[n] -> 점수 n일 때 {최소 횟수, 싱글or불 횟수}
// 더블, 트리플 값이 싱글로 나올 수 있으면 무조건 싱글로 처리
// 더블 값은 11*2부터, 트리플 값은 7*3부터
vector<int> solution(int target) {
    vector<int> answer;
     
    for(int i = 1; i <= target; i++) {
        dp[i] = {INF, INF};
    }
    
    for(int i = 1; i <= target; i++) {
        for(int j = 1; j <= 20; j++) { // 싱글
            if(i-j >= 0) {
                if(dp[i-j].first+1 < dp[i].first ||
                   dp[i-j].first+1 == dp[i].first && dp[i-j].second+1 > dp[i].second)
                    dp[i] = {dp[i-j].first+1, dp[i-j].second+1};
            } else break;
        }
        
        if(i-50 >= 0) { // 불
            if(dp[i-50].first+1 < dp[i].first || 
              dp[i-50].first+1 == dp[i].first && dp[i-50].second+1 > dp[i].second)
                dp[i] = {dp[i-50].first+1, dp[i-50].second+1};
        } 
        
        for(int j = 11; j <= 20; j++) { // 더블
            int nj = j << 1;
            if(i - nj >= 0) {
                if(dp[i-nj].first+1 < dp[i].first)
                    dp[i] = {dp[i-nj].first+1, dp[i-nj].second};
            } else break;
        }
        
        for(int j = 3; j <= 20; j++) { // 트리플
            int nj = j*3;
            if(i - nj >= 0) {
                if(dp[i-nj].first+1 < dp[i].first)
                    dp[i] = {dp[i-nj].first+1, dp[i-nj].second};
            } else break;
        }
    }
    
    answer = {dp[target].first, dp[target].second};
    return answer;
}