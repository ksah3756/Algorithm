#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int check(const vector<int>& answers, const vector<int>& pat, int start) {
    int cnt = 0;
    for(int i = 0; i < pat.size(); i++) {
        if(start + i >= answers.size()) break;
        if(answers[start+i] == pat[i]) cnt++;
    }
    return cnt;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> pat1 = {1,2,3,4,5};
    vector<int> pat2 = {2,1,2,3,2,4,2,5};
    vector<int> pat3 = {3,3,1,1,2,2,4,4,5,5};
    
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    int idx1 = 0, idx2 = 0, idx3 = 0;
    while(idx1 < answers.size()) {
        cnt1 += check(answers, pat1, idx1);
        idx1 += pat1.size();
    }
    while(idx2 < answers.size()) {
        cnt2 += check(answers, pat2, idx2);
        idx2 += pat2.size();
    }
    while(idx3 < answers.size()) {
        cnt3 += check(answers, pat3, idx3);
        idx3 += pat3.size();
    }
    
    // cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << '\n';
    vector<pair<int,int>> tmp = {{cnt1, 1}, {cnt2, 2}, {cnt3, 3}};
    sort(tmp.begin(), tmp.end(), greater<>());
    if(tmp[0].first == tmp[1].first && tmp[1].first == tmp[2].first) {
        answer = {1,2,3};
    } else if(tmp[0].first == tmp[1].first) {
        answer = {tmp[1].second, tmp[0].second};
    } else {
        answer = {tmp[0].second};
    }
    return answer;
}

