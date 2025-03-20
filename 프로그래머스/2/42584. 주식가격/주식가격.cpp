#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;

// 현재 위치에서 뒤의 수 중 본인보다 작은 수가 나타나는 위치를 구해서 전체 길이에서 마이너스?
// 스택으로 top보다 작은 수가 나오면 pop하고 idx 차 기록
// top보다 크거나 같은 수면 그냥 push
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.resize(prices.size());
    stack<pii> stk;
    
    for(int i = 0; i < prices.size(); i++) {
        while(!stk.empty() && stk.top().first > prices[i]) {
            int idx = stk.top().second; 
            answer[idx] = i - idx;
            stk.pop();
        }
        stk.push({prices[i], i});
    }
    
    while(!stk.empty()) {
        int idx = stk.top().second;
        answer[idx] = prices.size() - 1 - idx; 
        stk.pop();
    }

    
    return answer;
}