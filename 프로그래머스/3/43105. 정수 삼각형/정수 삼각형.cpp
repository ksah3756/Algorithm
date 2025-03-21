#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> dp;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    // dp[i][j] = triange[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
    
    int h = triangle.size();
    dp.resize(h, vector<int>(h));
    dp[0][0] = triangle[0][0];
    
    for(int i = 1; i < h; i++) {
        for(int j = 0; j <= i; j++) {
            int tmp = 0;
            if(j-1 >= 0) tmp = max(tmp, dp[i-1][j-1]);
            tmp = max(tmp, dp[i-1][j]);
            dp[i][j] = triangle[i][j] + tmp;
        }
    }
    
    answer = *max_element(dp[h-1].begin(), dp[h-1].end());
    
    return answer;
}