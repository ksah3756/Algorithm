#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
int arr[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    ll sum, cnt, ans = 0;
    for(int i = 0; i < n-2; i++) {
        for(int j = i+1; j < n-1; j++) {
            sum = arr[i] + arr[j];
            cnt = upper_bound(arr+j+1, arr+n, -sum) - lower_bound(arr+j+1, arr+n, -sum);
            ans += cnt;
        }
    }
    
    cout << ans << '\n';
    return 0;
}