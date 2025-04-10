#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
// 1:48
// 그냥 set1, set2 두고 원소 하나씩 set1에 넣고 set2에 빼서 사이즈 같아지면 종료
int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_map<int, int> m;
    for(int t : topping) {
        m[t]++;
    }
    
    int size = m.size();
    unordered_set<int> s;
    
    for(int t : topping) {
        s.insert(t);
        if(--m[t] == 0) size--;
        if(s.size() == size) answer++;
    }
    return answer;
}