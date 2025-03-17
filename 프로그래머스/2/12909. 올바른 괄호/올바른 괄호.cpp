#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    stack<char> stk;
    for(char c : s) {
        if(c == ')') {
            if(stk.empty()) return answer = false;
            if(stk.top() == '(') stk.pop();
            else {
                return answer = false;
            }
        } else {
            stk.push(c);
        }
    }
    if(stk.empty()) answer = true;
    else answer = false;
    cout << "Hello Cpp" << endl;

    return answer;
}