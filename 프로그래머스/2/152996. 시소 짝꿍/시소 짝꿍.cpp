#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 2:15
// 무게 관계가 1:1, 2:3, 1:2, 3:4 중 하나이면 가능
// 브루트 포스 말고 다른 방법이 있을까?
long long solution(vector<int> weights) {
    long long answer = 0;
    int len = weights.size();
    
    // 정렬하고 1배, 4/3배, 3/2배, 2배에 해당하는 수가 있는지 체크?
    sort(weights.begin(), weights.end());
    int w, cnt, nw;
    for(int i = 0; i < len; i++) {
        w = weights[i];
        cnt = upper_bound(weights.begin()+i+1, weights.end(), w) - lower_bound(weights.begin()+i+1, weights.end(), w);
        answer += cnt;
        w = weights[i];
        if(w % 3 == 0) {
            nw = w/3*4;
            cnt = upper_bound(weights.begin()+i+1, weights.end(), nw) - lower_bound(weights.begin()+i+1, weights.end(), nw);
        answer += cnt;
        } 
        if(w % 2 == 0) {
            nw = w/2*3;
            cnt = upper_bound(weights.begin()+i+1, weights.end(), nw) - lower_bound(weights.begin()+i+1, weights.end(), nw);
        answer += cnt;
        }
        cnt = upper_bound(weights.begin()+i+1, weights.end(), w<<1) - lower_bound(weights.begin()+i+1, weights.end(), w<<1);
        answer += cnt;
    }
        
    return answer;
}