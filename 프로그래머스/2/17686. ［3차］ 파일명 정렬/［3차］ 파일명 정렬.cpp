#include <bits/stdc++.h>

using namespace std;
typedef pair<string,int> psi;
// 3:48
// 우선 cmp를 따로 정의해줘야 할거같고
// head 떼와서 대소문자 같은걸로 취급
// number는 stoi로 정수로 바꿔서 비교
vector<string> solution(vector<string> files) {
    
    auto cmp = [&](const psi& p1, const psi& p2) -> bool {
        int numIdx1 = 0, numIdx2 = 0;
        string s1 = p1.first, s2 = p2.first;
        
        while(numIdx1 < s1.size()) {
            if('0' <= s1[numIdx1] && s1[numIdx1] <= '9') break;
            numIdx1++;
        }
        while(numIdx2 < s2.size()) {
            if('0' <= s2[numIdx2] && s2[numIdx2] <= '9') break;
            numIdx2++;
        }
        
        string head1, head2;
        int num1, num2;
        head1 = s1.substr(0,numIdx1);
        head2 = s2.substr(0,numIdx2);
        num1 = stoi(&s1[numIdx1]);
        num2 = stoi(&s2[numIdx2]);
        
        for(int i = 0; i < head1.size(); i++) {
            if('A' <= head1[i] && head1[i] <= 'Z')
                head1[i] = head1[i] - 'A' + 'a';
        }
        for(int i = 0; i < head2.size(); i++) {
            if('A' <= head2[i] && head2[i] <= 'Z')
                head2[i] = head2[i] - 'A' + 'a';
        }
        
        if(head1.compare(head2) == 0) {
            if(num1 == num2) return p1.second < p2.second;
            return num1 < num2;
        }
        return head1 < head2;
    };
    
    vector<psi> v;
    for(int i = 0; i < files.size(); i++) {
        v.push_back({files[i], i});
    }
    sort(v.begin(), v.end(), cmp);
    vector<string> answer;
    for(auto iter = v.begin(); iter != v.end(); iter++) {
        answer.push_back(iter->first);
    }
    return answer;
}