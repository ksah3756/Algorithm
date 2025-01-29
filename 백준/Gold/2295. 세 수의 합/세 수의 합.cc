#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int n;
int arr[1001];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    // x,y,z,k 가 서로 같아도 되기 때문에 
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            v.push_back(arr[i] + arr[j]);
        }
    }

    sort(v.begin(), v.end());

    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            if(binary_search(v.begin(), v.end(), arr[i]-arr[j])) {
                cout << arr[i] << '\n';
                return 0;
            }
        }
    }
}
