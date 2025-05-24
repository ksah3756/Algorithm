#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
// 10:10
ll getNum(ll n) {
    if(n == 1) return 0;
    ll ret = 1;
    ll a1, a2;
    for(ll i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            a1 = i; a2 = n/i;
            if(a2 <= 10000000) return a2;
            ret = max(ret, a1);
        }
    }
    return ret;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for(ll i = begin; i <= end; i++) {
        answer.push_back(getNum(i));
    }
    
    return answer;
}