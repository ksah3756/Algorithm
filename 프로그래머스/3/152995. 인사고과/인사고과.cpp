#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 0;
    
    auto cmp = [](const vector<int>& v1, const vector<int>& v2) -> bool {
      if(v1[0] == v2[0]) return v1[1] < v2[1];
        return v1[0] > v2[0];
    };
    
    // 어짜피 완호 점수보다 높은 사람들이 몇명인지 세는 문제인거니까 
    int targetA = scores[0][0], targetB = scores[0][1];
    int targetScore = targetA + targetB;
    
    sort(scores.begin(), scores.end(), cmp);
    
    int maxB = -1;
    for(int i = 0; i < scores.size(); i++) {
        if(scores[i][1] < maxB) continue; // 인센티브 지급 X
        if(targetA < scores[i][0] && targetB < scores[i][1]) return -1;
        
        if(scores[i][0] + scores[i][1] > targetScore) {
            answer++;
        }
        maxB = scores[i][1];
    }
    
    answer++;
    return answer;
}