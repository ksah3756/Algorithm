#include <string>
#include <vector>

using namespace std;
// 1:30
// 4 10
// 2 2 3 3 -> 36
vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n > s) return answer = {-1};
    // 기본 share
    int share = s / n;
    for(int i = 0; i < n; i++) {
        answer.push_back(share);
    }
    
    int remaining = s - share * n;
    for(int i = 0; i < remaining; i++) {
        answer[answer.size()-1-i]++;
    }
    

    return answer;
}