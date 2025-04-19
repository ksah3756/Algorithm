#include <bits/stdc++.h>

using namespace std;
// 4:42
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> map;
    for(int i = 0; i < 10; i++) {
        map[discount[i]]++;
    }
    
    int wantSize = want.size();
    int startIdx = 0;
    while(1) {
        bool flag = 1;
        for(int j = 0; j < wantSize; j++) {
            if(map[want[j]] < number[j]) {
                flag = 0;
                break;
            }
        }
        if(flag) answer++;
        if(startIdx+10 == discount.size()) break;
        map[discount[startIdx]]--;
        map[discount[startIdx+10]]++;
        startIdx++;
    }
    return answer;
}