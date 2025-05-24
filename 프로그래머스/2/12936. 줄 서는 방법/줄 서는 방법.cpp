#include <bits/stdc++.h>
typedef long long ll;

// 9:33
// 분할정복 느낌인데
// 실제로 다 구할수는 없으니
// 계속해서 n-1!과 그 안에서 인덱스를 갱신
// solve(n-1, k % factorial[n-1])
// answer에 k / factorial[n-1] + 1 을 추가
using namespace std;
ll factorial[21];

vector<int> solution(int n, long long k) {
    vector<int> answer;
    
    factorial[0] = 1;
    factorial[1] = 1;
    for(int i = 2; i <= 20; i++) {
        factorial[i] = i * factorial[i-1];
    }
    
    function<void(int,ll)> solve;
    
    vector<int> candidates;
    for(int i = 1; i <= n; i++) candidates.push_back(i);
    
    solve = [&](int n, ll k) -> void {
        if(n == 0) return;
        
        ll idx = k / factorial[n-1];
        // cout << n << ' ' << k << ' ' << candidates[idx] << '\n';
        answer.push_back(candidates[idx]);
        candidates.erase(candidates.begin() + idx);
        solve(n-1, k % factorial[n-1]);
    };
    solve(n, k-1);
    return answer;
}