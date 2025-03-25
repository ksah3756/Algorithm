#include <bits/stdc++.h>n

using namespace std;
// 10:34
// 합산하면 10%를 통해 결과가 달라지므로 합산하면 안됨
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    unordered_map<string, string> parent;
    unordered_map<string, int> money, sell;
    
    for(int i = 0; i < enroll.size(); i++) {
        string child = enroll[i];
        string pa = referral[i];
        parent[child] = pa;
    }
        
    for(int i = 0; i < seller.size(); i++){
        string cur = seller[i];
        int m = amount[i] * 100;
        while(cur.compare("-")) {
            if(m == 0) break;
            int give = m / 10;
            money[cur] += (m - give);
            m = give;
            cur = parent[cur];
        }
    }
    
    for(const string& s : enroll) {
        answer.push_back(money[s]);
    }
    return answer;
}