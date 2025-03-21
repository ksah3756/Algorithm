#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 일단 각 자리에서 위, 아래 중 방향 선택하고
// 자리 당 A가 아니면 어쨌던 한번은 무조건 도착해야 하는데 
// 예를 들어 AJAAAABNA 이러면 오른쪽으로 갔다가 왼쪽으로 백하는게 나은데, 원형으로 생각하기
// 최대 20번이니까 완전탐색? 아니면 dp + 비트마스킹?
int min_cnt;
int sze;
void solve(vector<bool>& to_visit, int idx, int cnt, int to_visit_cnt) {
    if(cnt >= min_cnt) return;
    if(to_visit_cnt == 0) {
        min_cnt = min(min_cnt, cnt);
        return;
    }
    
    int l_cnt = 1, r_cnt = 1;
    int cur = (sze + idx - 1) % sze;
    while(cur != idx && !to_visit[cur]) {
        cur = (sze + cur - 1) % sze; 
        l_cnt++;
    }
    
    to_visit[cur] = 0;
    solve(to_visit, cur, cnt+l_cnt, to_visit_cnt-1);
    to_visit[cur] = 1;
    
    cur = (idx + 1) % sze;
    while(cur != idx && !to_visit[cur]) {
        cur = (cur + 1) % sze;
        r_cnt++;
    }
    
    to_visit[cur] = 0;
    solve(to_visit, cur, cnt+r_cnt, to_visit_cnt-1);
    to_visit[cur] = 1;
}

int solution(string name) {
    int answer = 0;
    
    vector<bool> to_visit(name.size(), 1);
    to_visit[0] = 0;
    
    sze = name.size();
    int to_visit_cnt = sze-1;
    for(int i = 0; i < sze; i++) {
        int diff = name[i] - 'A';
        answer += min(26 - diff, diff);
        if(i !=0 && diff == 0) {
            to_visit[i] = 0;
            to_visit_cnt--;
        }
    }
    
    cout << answer << '\n';
    min_cnt = sze-1;
    
    solve(to_visit, 0, 0, to_visit_cnt);
    answer += min_cnt;
    
    return answer;
}