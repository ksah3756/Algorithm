#include <bits/stdc++.h>

using namespace std;

// 10:37
// 퇴실 후 10분간 청소를 해야 함
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    map<int, int> m;
    int minute, hour;
    for(const vector<string>& times : book_time) {
        minute = stoi(&times[0][3]);
        hour = stoi(times[0].substr(0, 2));
        m[60*hour+minute]++;
        minute = stoi(&times[1][3]) + 10;
        hour = stoi(times[1].substr(0, 2));
        m[60*hour+minute]--;
    }
    
    int cur = 0;
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        cur += (iter->second);
        answer = max(answer, cur);
        // cout << iter->first << ' ' << cur << '\n';
    }
    return answer;
}