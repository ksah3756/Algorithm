#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

typedef struct Task {
    int idx, start, cost;
    Task(int idx, int start, int cost) : idx(idx), start(start), cost(cost) {};
} Task;

typedef struct Cmp {
    bool operator()(const Task &t1, const Task &t2) {
        if(t1.cost == t2.cost) {
            if(t1.start == t2.start) return t1.idx > t2.idx;               return t1.start > t2.start;
        }
        return t1.cost > t2.cost;
    }
} Cmp;

// 시뮬레이션
// 디스크 사용 종료 시간을 저장해두었다가 time이 해당 시간에 되면 pq에서 꺼내서 작업 시작하고 종료 시간 최신화
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    unordered_map<int,vector<pii>> um; 
    vector<int> ended(jobs.size());
    
    int min_start = 1001;
    for(int i = 0; i < jobs.size(); i++) {
        int s = jobs[i][0], l = jobs[i][1];
        um[s].push_back({i,l});
        min_start = min(min_start, s);
    }
    
    // 처음에 제일 먼저 요청된 작업 중 소요시간 제일 빠른거 기준으로 endTime 초기화 필요
    priority_queue<Task, vector<Task>, Cmp> pq;
    int time = -1;
    int endTime = min_start, curIdx, task_cnt = jobs.size();
    
    while(task_cnt) {
        time++;
        // 대기 큐에 시작할 수 있는 작업 추가
        if(um.find(time) != um.end()) {
            for(auto x : um[time]) {
                pq.push(Task(x.first, time, x.second));
            }
        }
        
        // 아직 작업중이면 넘어가기
        // 처음에 이거 초기화가 문제네
        if(time < endTime) continue;
        
        if(!pq.empty()) { // 시작할 수 있는 작업들만 들어가있음
            Task t = pq.top(); pq.pop();
            endTime = time + t.cost;
            curIdx = t.idx;
            ended[curIdx] = endTime;
            task_cnt--;
        }
    }
    int sum = 0;
    for(int i = 0; i < ended.size(); i++) {
        sum += (ended[i] - jobs[i][0]);
    }
    
    answer = sum / ended.size();
    return answer;
}