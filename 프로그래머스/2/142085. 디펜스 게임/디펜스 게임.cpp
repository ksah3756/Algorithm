#include <bits/stdc++.h>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = -1;
    
    priority_queue<int> pq;
    for(int i = 0; i < enemy.size(); i++) {
        n -= enemy[i];
        pq.push(enemy[i]);
        
        if(n < 0) {
            if(k) {
                int x = pq.top(); pq.pop();
                n += x;
                k--;
            }
            else {
                answer = i;
                break;
            }
        }
    }
    
    if(answer == -1) answer = enemy.size();
    return answer;
}