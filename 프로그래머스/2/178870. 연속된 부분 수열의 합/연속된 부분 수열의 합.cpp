#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;
// 3:20
// 가장 짧은 부분수열, 여러개면 맨 앞에
// 투포인터같은데
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.resize(2, -1);
    
    vector<int> sum(sequence.size()+1, 0);
    for(int i = 1; i <= sequence.size(); i++) {
        sum[i] = sequence[i-1] + sum[i-1];
    }
    
    int s, e;
    s = e = 1;
    while(s <= e && e <= sequence.size()) {
        int tmp = sum[e] - sum[s-1];
        if(tmp < k) e++;
        else if(tmp > k) s++;
        else {
            if((answer[0] == -1 && answer[1] == -1) || (answer[1]-answer[0] > e-s)) {
                answer[0] = s-1;
                answer[1] = e-1;
            }
            e++;
        }
    }
    return answer;
}