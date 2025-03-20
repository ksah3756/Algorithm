#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    deque<int> dq;
    for(int pri : priorities) dq.push_back(pri);
    
    int cnt = 0, idx = location;
    int currMax = *max_element(dq.begin(), dq.end());

    while(!dq.empty()) {
        int cur = dq.front(); dq.pop_front();
        if(currMax != cur) {
            dq.push_back(cur);
        }
        else {
            cnt++;
            if(idx == 0) break;
            currMax = *max_element(dq.begin(), dq.end());
        }
        
         if(idx == 0) idx = dq.size() - 1;
        else idx--;
    }
    
    answer = cnt;
    return answer;
}
