#include <bits/stdc++.h>

using namespace std;
int n;
string s1, s2, s3;
int check(int,int,int);
int dp[201][201];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> s1 >> s2 >> s3;
        fill_n(&dp[0][0], 201*201, -1);
        cout << "Data set " << i << ": ";
        check(0,0,0) == true ? cout << "yes" << '\n' : cout << "no" << '\n';
    }
    return 0;
}

int check(int p1, int p2, int p3) {
    int& ret = dp[p1][p2];
    if(ret != -1) return ret;
    if(p3 == s3.size()) {
        return ret = 1;
    }

    char cur = s3[p3];
    if(cur == s1[p1] && cur == s2[p2]) {
        return ret = check(p1+1, p2, p3+1) || check(p1, p2+1, p3+1);
    } else if(cur == s1[p1]) {
        return ret = check(p1+1, p2, p3+1);
    } else if(cur == s2[p2]) {
        return ret = check(p1, p2+1, p3+1);
    } else {
        return ret = 0;
    }
}

