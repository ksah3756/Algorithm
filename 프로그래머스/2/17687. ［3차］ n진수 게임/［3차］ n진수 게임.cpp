#include <bits/stdc++.h>

using namespace std;
// 3:20
// p-1+(m*i) 번 마다 말해야 함 (i = 0...t-1)
// 0110111001011101111000
// 0123456789ABCDEF101112
string solution(int n, int t, int m, int p) {
    string answer = "";
    
    auto toDigit = [&](int i) -> string {
        string ret;
        while(i) {
            int tmp = i % n;
            if(tmp < 10) ret += to_string(tmp);
            else ret += 'A' + tmp - 10;
            i /= n;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    };
    
    string s = "0";
    int i = 1;
    while(s.size() < p + m*t) {
        s += toDigit(i++);
    }
    
    for(int i = 0; i < t; i++) {
        answer += s[p-1 + m*i];
    }
    
    return answer;
}
