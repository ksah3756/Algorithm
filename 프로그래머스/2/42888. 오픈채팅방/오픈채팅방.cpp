#include <bits/stdc++.h>

using namespace std;
// 7:08
// uid - 닉네임 매핑해서 최종 uid->닉네임으로 전부 변경
// enter or change로 닉 변경 가능
vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> log(record.size(), vector<string>());
    string cmd, id, name;
    unordered_map<string, string> map;
    
    int i = 0;
    for(string& s : record) {
        istringstream iss(s);
        iss >> cmd; iss >> id; iss >> name;
        if(cmd.compare("Enter") == 0 
           || cmd.compare("Change") == 0) {
            map[id] = name;
        }
        log[i].push_back(cmd);
        log[i].push_back(id);
        log[i].push_back(name);
        i++;
    }
    
    for(int j = 0; j < i; j++) {
        if(log[j][0].compare("Change") == 0) continue;
        
        string s = "";
        s += map[log[j][1]];
        
        if(log[j][0].compare("Enter") == 0) {
            s += "님이 들어왔습니다.";
        } else if(log[j][0].compare("Leave") == 0) {
            s += "님이 나갔습니다.";
        }
        answer.push_back(s);
    }
    
    return answer;
}