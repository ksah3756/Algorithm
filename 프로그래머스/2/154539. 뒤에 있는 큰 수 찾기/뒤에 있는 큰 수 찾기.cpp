#include <string>
#include <vector>
#include <stack>

using namespace std;
typedef pair<int,int> pii;

// 현재 수가 이전 수보다 작으면 새로 찾아야 함
// 현재 수가 이전 수와 같으면 이전 뒷 큰수 그대로
// 현재 수가 이전 수보다 크면 이전 수의 뒷큰수가 나였으므로 새로 찾아야 함
// 스택으로 되나?
// top보다 작거나 같으면 스택에 넣고 top보다 크면 top이 더 크거나 같아질 때 까지 pop한 후 넣기
// 스택에는 항상 아직 뒷큰수를 찾지 못한 수들이 들어가도록
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    answer.resize(numbers.size());
    
    stack<int> stk;
    for(int i = 0; i < numbers.size(); i++) {
        if(stk.empty() || numbers[stk.top()] >= numbers[i]) stk.push(i);
        else {
            while(!stk.empty() && numbers[stk.top()] < numbers[i]) {
                int x = stk.top(); stk.pop();
                answer[x] = numbers[i];
            }
            stk.push(i);
        }
    }
    
    while(!stk.empty()) {
        int x = stk.top(); stk.pop();
        answer[x] = -1;
    }
    return answer;
}