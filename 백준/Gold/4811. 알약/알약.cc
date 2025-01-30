#include <iostream>

using namespace std;
typedef long long ll;
ll dp[31][31];
ll solve(int, int);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(1){
        cin >> n;
        if(!n) break;
        cout << solve(n, 0) << '\n';
    }
    return 0;
}

ll solve(int w, int h){
    ll& ret = dp[w][h];
    if(ret) return ret;
    if(w + h == 1) return ret = 1;
    if(w > 0) ret += solve(w-1, h+1); //문자열에 w를 넣음
    if(h > 0) ret += solve(w, h-1); //문자열에 h를 넣음
    return ret;
}
