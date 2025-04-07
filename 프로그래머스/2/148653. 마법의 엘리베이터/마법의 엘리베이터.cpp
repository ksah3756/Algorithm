#include <string>
#include <vector>
#include <iostream>

// 10:00
// 뒷자리에서부터 0으로 만들어야 하는데 빼기 또는 더하기
// 마지막 제일 큰 자리는 5 이하면 x, 5 초과면 1
using namespace std;

int ans = 1e+8+1;
void solve(int cur, int cnt) {
    if(cur < 10) {
        int tmp = min(cnt+cur, cnt+11-cur);
        ans = min(ans, tmp);
        return;
    }
    int x = cur % 10;
    solve(cur/10, cnt+x);
    solve(cur/10 + 1, cnt+10-x);
}

int solution(int storey) {
    int answer = 0;
    solve(storey, 0);
    answer = ans;
    return answer;
}