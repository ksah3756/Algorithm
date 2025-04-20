#include <string>
#include <vector>

using namespace std;

// 0~4
// 5는 +든 -든 똑같이 5회필요한데
// +랑 - 두 경우에 대해 계속 확인?
// 근데 마지막 자리는 올릴경우 무조건 1회 추가
int ans = 1e+9;
void solve(int floor, int cnt) {
    if(floor/10 == 0) {
        ans = min(ans, cnt + min(11-floor, floor));
        return;
    }
    
    int cur = floor % 10;
    int nxt = floor / 10;
    solve(nxt+1, cnt+10-cur);
    solve(nxt, cnt+cur);
}

int solution(int storey) {
    int answer = 0;
    solve(storey, 0);
    answer = ans;
    return answer;
}