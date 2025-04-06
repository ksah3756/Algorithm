#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
// 3:37
// {a,b}를 정렬해서 a 오름차순 순으로 하나씩 확인해서 스택에 넣는데, top보다 큰 수가 나타난다면 top이 크거나 같아질때 까지 pop하고 해당 수를 push 
// 이 스택에 남은 score에 대해서만 합을 구해서 map에 기록
int solution(vector<vector<int>> scores) {
    int answer = 0;
    
    vector<pii> score;
    for(const vector<int>& v : scores) {
        score.push_back({v[0],v[1]});
    }
    
    auto cmp = [](const pii& p1, const pii& p2) -> bool {
        if(p1.first == p2.first) return p1.second > p2.second;
        return p1.first < p2.first;
    };
    
    sort(score.begin(), score.end(), cmp);
    
    stack<pii> stk;
    
    // 이렇게 하면 2,2 2,3 들어왔을 때 2,2 아웃되네
    // 근데 2,5 2,1 이렇게 있는데 3,2 들어오면 2,1은 아웃되지만 2,5는 아웃되면 안됨
    for(int i = 0; i < score.size(); i++) {
        while(!stk.empty() && stk.top().first < score[i].first && stk.top().second < score[i].second) stk.pop();
        stk.push(score[i]);
    }
    
    bool isPossible = 0;
    map<int,int> mp;
    while(!stk.empty()) {
        int a = stk.top().first;
        int b = stk.top().second;
        // cout << a << ' ' << b << '\n';
        if(a == scores[0][0] && b == scores[0][1]) isPossible = 1;
        mp[a+b]++;
        stk.pop();
    }
    
    if(!isPossible) return -1;
    
    int ansSum = scores[0][0] + scores[0][1];
    int rank = 1;
    for(auto iter = --mp.end(); ; iter--) {
        if(iter->first == ansSum) {
            break;
        }
        int cnt = iter->second;
        rank += cnt;
        if(iter == mp.begin()) break;
    }
    
    isPossible ? answer = rank : answer = -1;
    
    return answer;
}