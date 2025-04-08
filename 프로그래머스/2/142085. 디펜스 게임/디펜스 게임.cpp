#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
// 10:36
// 몇 개의 라운드를 해결할 수 있을지 이분 탐색으로 정하고 가능한지 확인해서 가능하면 오른쪽, 불가능하면 왼쪽
// 가능한지 확인하는건 내림차순으로 정렬 후 앞에서부터 k개 없애서 합이 n보다 작거나 같은지 확인
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    auto checkIfPossible = [&](int lastIdx) -> bool {
        vector<int> v(lastIdx+1);
        ll sum = 0;
        for(int i = 0; i <= lastIdx; i++) {
            v[i] = enemy[i];
            sum += enemy[i];
        }

        if(sum <= n) return true;
        
        sort(v.begin(), v.end(), greater<int>());
        for(int i = 0; i < k && i <= lastIdx; i++) sum -= v[i];
        if(sum <= n) return true;
        return false;
    };
    
    int l = 0, r = enemy.size()-1, mid;
    
    while(l < r) {
        mid = (l+r+1) / 2;
        if(checkIfPossible(mid)) l = mid;
        else r = mid-1;
    }
    
    answer = l+1;
    return answer;     
}