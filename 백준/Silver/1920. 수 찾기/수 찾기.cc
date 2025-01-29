#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x;
        cout << binary_search(v.begin(), v.end(), x) << '\n';
    }
    return 0;
}