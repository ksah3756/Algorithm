#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
int arr[10001];
ll ans;
void solve(int,int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) break;
        solve(i, -arr[i]);
    }
    
    cout << ans << '\n';
    return 0;
}


void solve(int idx, int target) {
    int l = idx+1, r = n-1;
    while(l < r) {
        int sum = arr[l] + arr[r];
        if(sum < target) l++;
        else if(sum > target) r--;
        else {
            if(arr[l] == arr[r]) {
                int cnt = r-l+1;
                ans += cnt * (cnt-1) / 2;
                break;
            } else {
                int l_cnt = 1;
                while(arr[l] == arr[l+1]) {
                    l_cnt++;
                    l++;
                }
                l++;
                int r_cnt = 1;
                while(arr[r-1] == arr[r]) {
                    r_cnt++;
                    r--;
                }
                r--;
                ans += l_cnt * r_cnt;
            }  
        }
    }
}