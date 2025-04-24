#include <bits/stdc++.h>

using namespace std;
// 12:05
// 첨에 올바른 문자열인지 따로 체크 필요?
string solution(string p) {
    string answer = "";
    
    auto checkIfValid = [&](string s) -> bool {
        stack<char> stk;
        for(char c : s) {
            if(c == '(') stk.push(c);
            else {
                if(stk.empty()) return false;
                stk.pop();
            }
        }
        if(stk.empty()) return true;
        return false;
    };
    
    if(checkIfValid(p)) return p;
    
    function<string(string)> solve;
    
    solve = [&](string s) -> string {
        if(s.empty()) return s;
        
        int lcnt = 0, rcnt = 0;
        int idx = 0;
        
        while(idx < s.size() && lcnt == 0 || lcnt != rcnt) {
            if(s[idx] == '(') lcnt++;
            else rcnt++;
            idx++;
        }
        
        string u = s.substr(0, idx);
        string v = s.substr(idx);
    
        if(checkIfValid(u)) {
            return u + solve(v);
        } else {
            string ret = "(";
            ret += solve(v);
            ret += ')';
            
            u.erase(0,1);
            u.pop_back();
            
            for(char& c : u) {
                if(c == '(') c = ')';
                else c = '(';
            }

            ret += u;
            return ret;
        }  
    };
    
    answer = solve(p);
    
    return answer;
}