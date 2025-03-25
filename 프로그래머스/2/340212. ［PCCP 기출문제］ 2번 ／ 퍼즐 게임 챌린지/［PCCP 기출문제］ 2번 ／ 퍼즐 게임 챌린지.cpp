#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;
// 11:15
// diff > level이면 (diff-level+1) * time_cur + diff-level*time_prev
// diff <= level이면 time_cur
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    int l = 1, r = *max_element(diffs.begin(), diffs.end()), mid;
    
    while(l < r) {
        ll totalTime = 0, time;
        mid = (l+r) / 2;
        for(int i = 0; i < diffs.size(); i++) {
            if(diffs[i] > mid) {
                int timePrev;
                i >= 1 ? timePrev = times[i-1] : timePrev = 0;
                time = (diffs[i]-mid+1) * times[i] + (diffs[i] - mid) * timePrev;
            } else {
                time = times[i];
            }
            totalTime += time;
        }
        
        if(totalTime <= limit) r = mid;
        else l = mid+1;
    }
    
    answer = l;
    
    return answer;
}