#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// 9:25
// 5 3 3
// 1 4 9 16 25 36 49
// 큰 수 일수록 -1의 가치가 큼 
long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    for(int w : works) {
        pq.push(w);
    }
    
    while(n && !pq.empty()) {
        int top = pq.top(); pq.pop();
        if(top != 1) {
            pq.push(top-1);
        } 
        n--;
    }
    
    while(!pq.empty()) {
        ll cur = pq.top(); pq.pop();
        answer += cur * cur;
    }
    return answer;
}