#include <string>
#include <vector>
#include <iostream>

// 10:00
// 뒷자리에서부터 0으로 만들어야 하는데 빼기 또는 더하기
using namespace std;

int ans = 1e+8+1;
void solve(int cur, int cnt) {
    if(cur == 0) {
        ans = min(ans, cnt);
        return;
    }
    int x = cur % 10;
    solve(cur/10, cnt+x);
    if(cur / 10 != 0) {
        solve(cur/10 + 1, cnt+10-x);
    } else {
        if(x >= 6)
            solve(cur / 10 + 1, cnt+10-x);
    }
        
}

int solution(int storey) {
    int answer = 0;
    solve(storey, 0);
    answer = ans;
    return answer;
}