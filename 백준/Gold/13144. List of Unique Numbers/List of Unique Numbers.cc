#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;
int arr[100001];
bool check[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
 
    int start = 0, end = 1;
    check[arr[start]] = 1;
    ll sum = 0;
    for(int start = 0; start < n; start++){
        while(end < n){
            if(!check[arr[end]]) check[arr[end++]] = 1;
            else break;
        }
        sum += (end-start);
        if(start == end) end++;
        check[arr[start]] = 0;
    }

    cout << sum << '\n';
}