#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {-1,-1};
    
    int size = sequence.size();
    
    int s = 0, e = 0;
    int sum = sequence[s];
    while(e < size) {
        while(e < size && sum < k) sum += sequence[++e];
        
        if(e == size) break;
        
        if(sum == k) {
            if(answer[0] == -1 || answer[1]-answer[0] > e-s) {
                answer = {s,e};
            }
            if(e+1 < size) sum += sequence[++e];
            else break;
        }
        
        while(s < e && sum > k) sum -= sequence[s++];
        if(s == e && sum > k) break;
    }
    return answer;
}