#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;
// 5:30
// 12! -> 까지는 아니겠네 대각선 체크를 하니
bool visited[12];
vector<pii> coords;
int ans, N;

// {x,y}로 한다면 n개의 pair에 대해 x,y 가 다 달라야 하고
// 대각선은 절대값 x1-x2 와 y1-y2가 같은게 있으면 안됨
void solve(int y) {
    if(y == N+1) {
        // 중복 제거를 하려면 정렬했을 때 y 순서가 일치하는지 확인
        ans++;
        return;
    }
    
    int x = -1;
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) x = i;
        else continue;
    
        bool isPossible = 1;
        for(const pii& p : coords) {
            if(abs(p.first-x) == abs(p.second-y)) {
                isPossible = 0;
                break;
            }
        }
        
        if(isPossible) {
            visited[x] = 1;
            coords.push_back({x,y});
            solve(y+1);
            visited[x] = 0;
            coords.pop_back();
        }
    }
}

int solution(int n) {
    int answer = 0;
    N = n;
    solve(1);
    answer = ans;
    return answer;
}

