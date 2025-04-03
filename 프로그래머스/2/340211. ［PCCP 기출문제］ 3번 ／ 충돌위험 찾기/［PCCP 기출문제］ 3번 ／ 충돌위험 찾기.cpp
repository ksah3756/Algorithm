#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
typedef pair<int,int> pii;

// 9:34
vector<pii> curpoint;
vector<vector<pii>> endpoints(101, vector<pii>());
vector<int> round;

bool checkIfFinished(int n) {
    if(curpoint[n].first == -1 && curpoint[n].second == -1) return true;
    else return false;
}

void movePoint(int n) {
    pii end = endpoints[n][round[n]];
    int& y = curpoint[n].first;
    int& x = curpoint[n].second;
    
    if(y == end.first && x == end.second) {
        if(round[n]+1 == endpoints[n].size()) {
            curpoint[n] = {-1,-1};
            return;
        }
        round[n] += 1;
        end = endpoints[n][round[n]];
    }
    
    if(y > end.first) y -= 1;
    else if(y < end.first) y += 1;
    else {
        if(x > end.second) x -= 1;
        else if(x < end.second) x += 1;
    }
}

// 같은 점이 몇개인지 세기
int countCollision() {
    map<pii, int> m;
    int ret = 0;
    for(const pii& p : curpoint) {
        if(p.first == -1 && p.second == -1) continue;
        m[p]++;
    }
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        if(iter->second > 1) ret++;
    }
    return ret;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    int robotCnt = routes.size();
    round.resize(robotCnt, 0);
    
    int idx = 0;
    for(const vector<int>& v : routes) {
        curpoint.push_back({points[v[0]-1][0], points[v[0]-1][1]});
        for(int i = 1; i < v.size(); i++) {
            endpoints[idx].push_back({points[v[i]-1][0], points[v[i]-1][1]});
        }
        idx++;
    }
    
    answer += countCollision(); // 처음에도 충돌 셈
    
    while(1) {
        bool isFinished = 1;
        for(int i = 0; i < robotCnt; i++) {
            if(!checkIfFinished(i)) {
                isFinished = 0;
                movePoint(i);
            }
        }
        
        if(isFinished) break;
        answer += countCollision();
        // for(int i = 0; i < robotCnt; i++) cout << "{" << curpoint[i].first << ", " << curpoint[i].second << "} ";
        cout << '\n';
    }
    return answer;
}

