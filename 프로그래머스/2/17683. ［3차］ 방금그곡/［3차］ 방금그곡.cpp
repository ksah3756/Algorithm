#include <bits/stdc++.h>

using namespace std;
// 10:34
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int answerTime = 0;
    
    auto changeSharp = [&](string s) -> string {
        int i = 0;
        string ret;
        while(i < s.size()) {
            if(i+1 < s.size() && s[i+1] == '#') {
                ret += (s[i] - 'A' + 'a');
                i += 2;
            } else {
                ret += s[i];
                i++;
            }
        }
        return ret;
    };
    
    auto toInt = [&](string s) -> int {
        int h = stoi(s.substr(0,2));
        int m = stoi(s.substr(3,2));
        return h * 60 + m;
    };
    
    m = changeSharp(m);
    
    for(string& info : musicinfos) {
        istringstream iss(info);
        string token;
        
        vector<string> v;
        while(getline(iss, token, ',')) {
            v.push_back(token);
        }

        string name = v[2], pattern = changeSharp(v[3]);
        int time1 = toInt(v[0]), time2 = toInt(v[1]);
        int playtime = time2-time1;
        int len = pattern.size();
        string music = "";
        
        for(int i = 0; i < playtime / len; i++)
            music += pattern;
        for(int i = 0; i < playtime % len; i++) {
            music += pattern[i];
        }
        
        int idx = music.find(m);
        if(idx != string::npos) {
            if(answerTime < playtime) {
                answer = name;
                answerTime = playtime;
            } 
        }
    } 
    if(answer.empty()) answer = "(None)";
    return answer;
}