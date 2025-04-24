#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int rSize = relation.size();
    int cSize = relation[0].size();
    
    vector<int> candidates;
    
    auto checkIfMinimum = [&](int comb) -> bool {
        // 나보다 작은 수들만 candidates에 포함되므로 이전 키와 내가 and 연산했을 때 해당 키면 나는 최소성 만족 X
        for(int i : candidates) {
            if((i & comb) == i) return false;
        }
        return true;
    };
    
    int all = (1 << cSize) - 1;
    for(int comb = 1; comb <= all; comb++) {
        unordered_set<string> set;
        for(int i = 0; i < rSize; i++) {
            string s = "";
            for(int j = 0; j < cSize; j++) {
                if(comb & (1<<j)) {
                    s += relation[i][j];
                }
            }
            set.insert(s);
        }
        if(set.size() == rSize && checkIfMinimum(comb)) {
            candidates.push_back(comb);
            answer++;
        }
    }
    return answer;
}