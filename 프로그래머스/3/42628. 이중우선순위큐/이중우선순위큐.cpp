#include <bits/stdc++.h>

using namespace std;
const int INF = 1e+7;

// 우선순위 반대인 큐 두개 두고 개수를 따로 세기?
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    map<int,int> m;
    int size = 0;
    
    for(string cmd : operations) {
        int i = stoi(cmd.substr(2));
        if(cmd[0] == 'I') {
            size++;
            m[i]++;
        } else {
            if(size == 0) continue;
            
            if(i == 1) {
                auto iter = m.end(); iter--;
                if(iter->second > 1) iter->second -= 1;
                else m.erase(iter);
            } else {
                auto iter = m.begin();
                if(iter->second > 1) iter->second -= 1;
                else m.erase(iter);
            } 
            size--;
        }
    }
    
    int maxVal = INF, minVal = INF;
    if(size) {
        auto iter = m.end(); iter--;
        maxVal = iter->first;
        iter = m.begin();
        minVal = iter->first;
       answer = {maxVal, minVal};
    } else {
        answer = {0,0};
    }
    
    return answer;
}