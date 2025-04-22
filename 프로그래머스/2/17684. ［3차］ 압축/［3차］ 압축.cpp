#include <bits/stdc++.h>

using namespace std;

// 6:04
vector<int> solution(string msg) {
    vector<int> answer;
    
    unordered_map<string,int> map;
    
    for(int i = 0; i < 26; i++) {
        // A ~ Z 추가
        map[string(1, 'A'+i)] = i+1;
    }
    
    int idx = 0, num = 27;
    while(idx < msg.size()) {
        int len = 1;
        while(idx+len-1 < msg.size() && map.find(msg.substr(idx, len)) != map.end()) len++;
        answer.push_back(map[msg.substr(idx,len-1)]);
        if(idx+len-1 == msg.size()) break;
        string s = msg.substr(idx, len);
        map[s] = num++;
        idx += (len-1);
    }
    
    return answer;
}