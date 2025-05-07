#include <bits/stdc++.h>

using namespace std;
// 10:42
// banned_id 별로 가능한 후보 user_id가 어떤건지 파악
// 비트마스크로 후보 표현하고 각 banned_id에 대해 후보 중 하나 선택해서 set에 추가해서 몇개의 개수가 나오는 지 세기
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    auto isCandidate = [&](string& uid, string& bid) -> bool {  
        if(uid.size() != bid.size()) return false;
        
        for(int i = 0; i < uid.size(); i++) {
            if(bid[i] == '*') continue;
            if(uid[i] != bid[i]) return false;
        }
        return true;
    };
    
    vector<int> candidates;
    
    for(string &bid : banned_id) {
        int bitset = 0;
        for(int i = 0; i < user_id.size(); i++) {
            if(isCandidate(user_id[i], bid)) bitset = bitset | (1<<i);
        }
        candidates.push_back(bitset);
    }
    
    unordered_set<int> s;
    
    function<void(int,int)> solve;
    solve = [&](int idx, int pick) -> void {
        if(idx == candidates.size()) {
            s.insert(pick);
            return;
        }
        
        for(int i = 0; i < user_id.size(); i++) {
            if(((1 << i) & candidates[idx])
               && !(pick & (1<<i))) {
                solve(idx+1, pick | (1 <<i));
            }
        }
    };
    
    solve(0, 0);
    answer = s.size();
    return answer;
}