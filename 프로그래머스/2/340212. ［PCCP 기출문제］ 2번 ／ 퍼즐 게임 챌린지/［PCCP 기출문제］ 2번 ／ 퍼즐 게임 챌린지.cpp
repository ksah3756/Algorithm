#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
// 6:07
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    auto calculateTime = [&](int level) -> ll {
        ll prevTime = 0, ans = 0, time;
        for(int i = 0; i < diffs.size(); i++) {
            if(diffs[i] > level) {
                time = (diffs[i] - level) * (times[i] + prevTime) + times[i];
            } else {
                time = times[i];
            }
            ans += time;
            prevTime = times[i];
        }
        return ans;
    };
    
    int l = 1, r = *max_element(diffs.begin(), diffs.end());
    int mid;
    while(l < r) {
        mid = (l+r) / 2;
        ll time = calculateTime(mid);
        if(time <= limit) r = mid;
        else l = mid+1;
    }
    
    answer = l;
    return answer;
}