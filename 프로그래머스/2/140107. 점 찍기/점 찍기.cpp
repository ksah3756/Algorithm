#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// 일단 x, y 좌표는 k의 배수여야 하고
// x^2 + y^2 <= d^2이면 되는데
// x던 y던 그냥 대칭이니까 한쪽 구하고 두배하면되고
// x가 0이면 y는 d에 가장 가까운 k의 배수까지 y = d / k * k
// d^2 - (a*k)^2
long long solution(int k, int d) {
    long long answer = 0;
    
    for(ll x = 0; x <= d; x += k) {
        ll y2 = (ll)d*d-x*x;
        ll tmp = (ll) sqrt(y2);

        answer += (tmp / k + 1);
        // cout << x << ' ' << tmp << ' ' << tmp / k + 1 << '\n';
    }
    
    return answer;
}