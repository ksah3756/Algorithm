#include <bits/stdc++.h>

using namespace std;

// 정렬하면 본인 앞 뒤 중 하나가 본인과 prefix가 가장 많이 일치하는 문자열이고 이 prefix 길이+1 필요
int solution(vector<string> words) {
    int answer = 0;
    
    sort(words.begin(), words.end());
    
    auto getPrefixLen = [&](const string& s1, const string& s2) -> int {
        int idx = 0;
        while(idx < s1.size() && idx < s2.size() && s1[idx] == s2[idx]) idx++;
        if(idx == s1.size()) return idx;
        else return idx+1;
    };
    
    answer += getPrefixLen(words[0], words[1]);
    
    for(int i = 1; i < words.size()-1; i++) {
        answer += max(getPrefixLen(words[i], words[i-1]), getPrefixLen(words[i], words[i+1])); 
    }
    
    answer += getPrefixLen(words[words.size()-1], words[words.size()-2]);
    
    return answer;
}