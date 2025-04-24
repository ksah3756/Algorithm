#include <bits/stdc++.h>

using namespace std;
const int MUL = 65536;
// 3:10
// 각 문자열의 두글자씩을 hashmap에 넣고 서로 상대방에 같은 요소가 있다면 각각 몇개인지 체크, 상대방에 같은 요소가 없다면 분모에 한개로 들어감
int solution(string str1, string str2) {
    int answer = 0;
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    unordered_map<string,int> map1, map2;
    
    bool isAdd;
    for(int i = 0; i < str1.size()-1; i++) {
        string s = str1.substr(i, 2);
        isAdd = 1;
        for(int j = 0; j < 2; j++) {
            if(!('a' <= s[j] && s[j] <= 'z')) isAdd = 0;
        }
        if(isAdd) map1[s]++;
    }
    for(int i = 0; i < str2.size()-1; i++) {
        string s = str2.substr(i, 2);
        isAdd = 1;
        for(int j = 0; j < 2; j++) {
             if(!('a' <= s[j] && s[j] <= 'z')) isAdd = 0;
        }
        if(isAdd) map2[s]++;
    }
    
    if(map1.size() == 0 && map2.size() == 0) return MUL;
    
    // x: 분자, y: 분모
    double x = 0, y = 0;
    for(auto p : map1) {
        string word = p.first;
        int cnt1 = p.second;
        if(map2.find(word) == map2.end()) y += cnt1;
        else {
            int cnt2 = map2[word];
            if(cnt1 > cnt2) swap(cnt1,cnt2);
            x += cnt1;
            y += cnt2;
        }
    }
    
    for(auto p : map2) {
        string word = p.first;
        int cnt1 = p.second;
        if(map1.find(word) == map1.end()) y += cnt1;
    }
    
    answer = x / y * MUL;
    
    return answer;
}