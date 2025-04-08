#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 6:55
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int,int> m;
    
    for(int i : tangerine) {
        m[i]++;
    }
    
    vector<int> cnt;
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        cnt.push_back(iter->second);
    }
    
    sort(cnt.begin(), cnt.end(), greater<int>());
    
    int sum = 0;
    for(int i = 0; i < cnt.size(); i++) {
        sum += cnt[i];
        if(sum >= k) {
            answer = i+1;
            break;
        }
    }
    return answer;
}