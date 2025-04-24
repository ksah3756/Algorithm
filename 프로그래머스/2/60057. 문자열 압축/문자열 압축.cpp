#include <bits/stdc++.h>

using namespace std;
// 11:28
// substr
int solution(string s) {
    int answer = 1001;
    
    int len = 1;
    while(len <= s.size()) {
        string ss = s;
        string pat = ss.substr(0, len);
        ss.erase(0, len);
        int cnt = 1;
        string ans = "";
        while(ss.size()) {
            // 패턴 추출 후 자르기
            string cur = ss.substr(0, len);
            ss.erase(0, len);
            if(pat.compare(cur) == 0) cnt++;
            else {
                if(cnt != 1) ans += (to_string(cnt));
                ans += pat;
                pat = cur;
                cnt = 1;
            }
        }
        if(cnt != 1) ans += (to_string(cnt));
        if(!pat.empty()) ans += pat;
        // cout << len << ' ' << ans << '\n';
        answer = min(answer, (int)ans.size());
        len++;
    }
    
    return answer;
}