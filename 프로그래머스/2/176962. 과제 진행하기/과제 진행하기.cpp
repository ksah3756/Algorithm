#include <bits/stdc++.h>

using namespace std;
typedef struct Plan {
    string name;
    int start, playtime;
    Plan (string name, int start, int playtime) : name(name), start(start), playtime(playtime) {}
} Plan;

struct compare {
    bool operator()(const Plan& p1, const Plan& p2) {
        return p1.start > p2.start;
    }
};

// 4:00
// start 시간 기준으로 pq
// 현재 작업으로 pq의 top을 체크해서 종료 시간 체크 후 다음 top보다 크면 시간 차만큼 playtime 줄이고 wait 스택에 넣기
// 크지 않다면 종료 시간이 top과 같으면 top 꺼내기, 다르다면 잠시 멈춤 스택에서 꺼내기
// time을 관리하는데 종료 시간이 다음 top보다 크면 
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    priority_queue<Plan, vector<Plan>, compare> pq;
    
    for(vector<string> v : plans) {
        istringstream iss(v[1]);
        string token;
        string min[2];
        int i = 0;
        while(getline(iss, token, ':')) {
            min[i++] = token;
        } 
        int time = stoi(min[0]) * 60 + stoi(min[1]);
        pq.push(Plan(v[0], time, stoi(v[2])));
    }
    stack<Plan> waitList;
    int time = -1;
    Plan cur = Plan("",0,0);
    
    while(!pq.empty()) {
        if(time == -1 || time == pq.top().start) {
            cur = pq.top(); pq.pop();
            time = cur.start;
        } else {
            if(!waitList.empty()) {
                cur = waitList.top(); waitList.pop();
            } else { // 대기 중인게 없으면 그냥 pq에서 가져와야지
                cur = pq.top(); pq.pop();
                time = cur.start;
            }       
        }
        // cout << cur.name << ' ' << time << ' ' << cur.playtime << '\n';
        
        if(pq.empty()) {
            answer.push_back(cur.name);
            break;
        }
        
        int endTime = time + cur.playtime;
        if(endTime > pq.top().start) {
            int nxtTime = pq.top().start;
            cur.playtime -= (nxtTime - time);
            // cout << cur.name << ' ' << cur.playtime << '\n';
            waitList.push(cur);
            time = nxtTime;
        } else {
            answer.push_back(cur.name);
            // cout << cur.name << ' ' << endTime << '\n';
            time = endTime;
        }
        
    }
    
    while(!waitList.empty()) {
        Plan cur = waitList.top(); waitList.pop();
        answer.push_back(cur.name);
    }
    
    
    return answer;
}