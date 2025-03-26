#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
int A, B;

bool check(ll totalTime, const vector<int> &t, const vector<int> &w, const vector<int> &g, const vector<int> &s) {
    ll total_g = 0, total_s = 0, total_gs = 0;
    
    for(int i = 0; i < t.size(); i++) {
        ll cnt = totalTime / (t[i]<<1);
        if(totalTime % (t[i]<<1) >= t[i]) cnt++;
        ll amount = w[i] * cnt; // 이론적으로 옮길 수 있는 양
        
        // 실제 옮길 수 있는 양
        total_g += min((ll)g[i], amount); 
        total_s += min((ll)s[i], amount);
        total_gs += min((ll)g[i] + s[i], amount);
    }
    
    // 이 부분이 잘 이해가...
    if(total_g >= A && total_s >= B && total_gs >= A + B) return true;
    return false;
}

// 예를 들어 전체 시간이 13이면 편도 4걸리는 경우 2번 운반 가능
// 운반 가능 횟수: totalTime / (t*2) + (totalTime % (t*2) 이 t 이상인 경우 +1)
// 3 -> 2번, 4 -> 2번, 5 -> 3번
// 근데 문제는 한번 운반할때 금만, 은만, 아니면 둘 다(둘 다라면 각긱 얼마를) 운반할건지
// 일단 금,은 상관 없이 운반할 수 있는 광물의 양은 w * 운반가능횟수인데
// 정확히 어떻게 운반할건지를 미리 결정하는게 아니라 전체 운반 가능한 광물의 양이 a+b 이상이면 가능?
long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    A = a; B = b;
    
    // 최대로 걸리는 시간은 모든 w = 1, t = 1e+5, a+b = 2e+9이면 
    ll l = 0, r = 4e+14, mid;
    while(l < r) {
        mid = (l+r) / 2;
        if(check(mid, t, w, g, s)) r = mid;
        else l = mid+1;
    }
    
    answer = l;
    
    return answer;
}

