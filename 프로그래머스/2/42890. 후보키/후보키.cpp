#include <bits/stdc++.h>

using namespace std;
// 각 칼럼별로 겹치는게 있으면 다른 칼럼들을 쭉 비교해서 서로 다른 칼럼이 있으면 그걸 포함하면 후보키
// 아니면 8C1~8C8 까지 쭉 키를 만들고 이게 유일성을 가지면 일단 저장하고, 나중에 최소성을 만족하지 않으면 제외
// 이걸 후보키가 되는 칼럼을 비트마스크로 표현하고 or 연산했을 때 자기 자신이 나오면 자신보다 더 작은 크기의 후보키가 있는 것이므로 제외?
int cSize, rSize;
vector<int> candidates;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    cSize = relation[0].size();
    rSize = relation.size();
    
    function<bool(int)> checkIfKey;
    
    checkIfKey = [&](int state) -> bool {
        unordered_set<string> set;
        for(int i = 0; i < rSize; i++) {
            string s = "";
            for(int j = 0; j < cSize; j++) {
                if(state & (1<<j)) {
                    s += relation[i][j];
                }
            }
            set.insert(s);
        }
    
        if(set.size() == rSize) return true;
        return false;
    };
    
    function<void(int,int)> dfs;
    dfs = [&](int state, int idx) -> void {
        if(idx == cSize) {
            if(checkIfKey(state))
                candidates.push_back(state);
            return;
        }

        dfs(state | (1 << idx), idx+1);
        dfs(state, idx+1);
    };
    
    dfs(0,0);
    
    for(int i = 0; i < candidates.size(); i++) {
        int c1 = candidates[i];
        bool isPossible = 1;
        for(int j = 0; j < candidates.size(); j++) {
            if(i == j) continue;
            int c2 = candidates[j];
            if((c1 | c2) == c1) {
                isPossible = 0;
                break;
            }
        }
        if(isPossible) answer++;
    }
    
    return answer;
}

