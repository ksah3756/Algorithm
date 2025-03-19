#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    ll l = 0, r = (ll)times[0] * n, mid;
    while(l < r) {
        mid = (l+r) / 2;
        ll sum = 0;
        for(int time : times) {
            sum += ((ll) mid / time);
        }
        if(sum >= n) r = mid;
        else l = mid + 1;
    }
    
    answer = l;
    
    return answer;
}