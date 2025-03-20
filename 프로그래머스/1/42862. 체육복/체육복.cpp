#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 그냥 앞에서부터 순서대로 빌릴 수 있으면 빌리는게
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    
    vector<bool> reserved(31, 0);
    vector<bool> not_lost(31, 0);
    
    for(int i : reserve) {
        reserved[i] = 1;
    }
    sort(lost.begin(), lost.end());
    
    for(int i : lost) {
        if(reserved[i]) {
            reserved[i] = 0;
            not_lost[i] = 1;
        }
    }
    
    for(int i : lost) {
        if(not_lost[i]) continue;
        if(0<= i-1 && reserved[i-1]) {
            reserved[i-1] = 0;
        } else if(i+1 <= n && reserved[i+1]) {
            reserved[i+1] = 0;
        } else {
            answer--;
        }
    }
    return answer;
}