#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll changeToNumber(string s);
string changeToString(ll n);

string solution(long long n, vector<string> bans) {
    
    vector<ll> nums;
    for(string ban : bans) {
        nums.push_back(changeToNumber(ban));
    }
    
    sort(nums.begin(), nums.end());

    ll tmp = n;
    for(ll num : nums) {
        if(tmp >= num) tmp++;
    }

    string answer = changeToString(tmp);
    
    return answer;
}

ll changeToNumber(string s) {
    ll ans = 0;
    for(char c : s) {
        ll tmp = c-'a'+1;
        ans = ans*26 + tmp;
    }
    return ans;
}

string changeToString(ll n) {
    string ans = "";
    while(n--) {
        char c = 'a' + n % 26;
        ans = c + ans;
        n /= 26;
    }
    
    return ans;
}