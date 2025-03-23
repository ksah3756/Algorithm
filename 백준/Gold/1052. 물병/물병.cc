#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
 
    bitset<30> b(n);

    int cnt = 0;
    while(b.count() > k) {
        b = ++n;
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}