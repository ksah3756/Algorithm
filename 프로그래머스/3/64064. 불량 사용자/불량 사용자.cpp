#include <bits/stdc++.h>

using namespace std;

// 10:00
// *은 그냥 넘어가면 되고 가능한 경우의 수를 구했을 때 순서 상관없으니 중복을 어떻게 처리할 지가 문제인데
// 그냥 가능한 user_id 쭉 놓고 방문처리해서 중복 못하게 하고
// 후보 케이스들 정렬해서 set에 넣기?
// user_id는 서로 다 다르니까 문자열 합쳐서 set에 넣으면 될거같은데
// 일치하는 패턴이 없을 수도 있는건가?
vector<vector<int>> candidates;
vector<vector<int>> possibles;
bool visited[9];
void dfs(int idx, vector<int>& v);

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    candidates.resize(banned_id.size(), vector<int>());
    
    for(int i = 0; i < banned_id.size(); i++) {
        string banId = banned_id[i];
        for(int j = 0; j < user_id.size(); j++) {
            string userId = user_id[j];
            if(banId.size() != userId.size()) continue;
            
            bool isPossible = 1;
            for(int k = 0; k < banId.size(); k++) {
                if(banId[k] == '*') continue;
                if(userId[k] != banId[k]) {
                    isPossible = 0;
                    break;
                }
            }
            if(isPossible) candidates[i].push_back(j);
        }
    }
    
    vector<int> v;
    dfs(0, v);
    
    unordered_set<int> set;
    // 모든 possible 배열에 대해 정렬하고 문자열 하나로 합쳐서 set에 넣어 사이즈 구하기
    for(vector<int>& v : possibles) {
        sort(v.begin(), v.end());
        int id = 0;
        for(int i : v) {
            id *= 10;
            id += i;
        }
        set.insert(id);
    }

    answer = set.size();    
    
    return answer;
}

void dfs(int idx, vector<int>& v) {
    if(idx == candidates.size()) {
        possibles.push_back(v);
        return;
    }
    for(int i : candidates[idx]) {
        if(!visited[i]) {
            v.push_back(i);
            visited[i] = 1;
            dfs(idx+1, v);
            v.pop_back();
            visited[i] = 0;
        }
    }
}