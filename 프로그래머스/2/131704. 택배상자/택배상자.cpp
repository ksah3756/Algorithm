#include <bits/stdc++.h>

using namespace std;

// 2:05
int solution(vector<int> order) {
    int answer = 0;
    
    int frontVal = 1, lastVal = order.size();
    stack<int> stk;
    
    for(int i : order) {
        if(!stk.empty() && stk.top() == i) {
            stk.pop();
            answer++;
            continue;
        }
        while(frontVal != i && frontVal <= lastVal) {
            stk.push(frontVal++);
        }
        if(frontVal == i) {
            answer++;
            frontVal++;
        } else {
            break;
        }
    }
    
    return answer;
}