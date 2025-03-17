#include <string>
#include <vector>
#include <deque>
#include <stack>

using namespace std;
deque<char> dq;
bool checkIfValid();

int solution(string s) {
    int answer = 0;
    
    for(char c : s) dq.push_back(c);
    
    for(int i = 0; i < dq.size(); i++) {
        if(checkIfValid()) answer++;
        int x = dq.front();
        dq.pop_front();
        dq.push_back(x);
    }
    return answer;
}

bool checkIfValid() {
    stack<char> stk;
    
    for(int i = 0; i < dq.size(); i++) {
        char c = dq[i];
        if(c == ']') {
            if(!stk.empty() && stk.top() == '[') stk.pop();
            else return false;
        } else if(c == '}') {
            if(!stk.empty() && stk.top() == '{') stk.pop();
            else return false;
        } else if(c == ')') {
            if(!stk.empty() && stk.top() == '(') stk.pop();
            else return false;
        } else {
            stk.push(c);
        }
    }
    if(stk.empty()) return true;
    else return false;
}