#include <bits/stdc++.h>

using namespace std;

vector<int> candidate[9];
unordered_set<int> s;
int banSize, userSize;

bool isCandidate(string& uid, string& bid) {
    if(uid.size() != bid.size()) return false;
    
    for(int i = 0; i < bid.size(); i++) {
        if(bid[i] != '*' && uid[i] != bid[i]) return false;
    }
    return true;
}

void dfs(int idx, int bits) {
    if(idx == banSize) {
        s.insert(bits);
        return;
    }
    
    for(int i : candidate[idx]) {
        if(!(bits & 1 << i)) {
            int prevBits = bits;
            bits |= (1 << i);
            dfs(idx+1, bits);
            bits = prevBits; 
        }
    }
} 

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    banSize = banned_id.size();
    userSize = user_id.size();
    
    for(int i = 0; i < banSize; i++) {
        for(int j = 0; j < userSize; j++) {
            if(isCandidate(user_id[j], banned_id[i]))
                candidate[i].push_back(j);
        }
    }
    
    dfs(0, 0);
    
    answer = s.size();
    return answer;
}