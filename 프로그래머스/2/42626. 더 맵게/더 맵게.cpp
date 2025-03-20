#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int> pq;
    for(int s : scoville) {
        pq.push(-s);
    }
    
    bool isPossible = 0;
    int cnt = 0;
    while(!pq.empty()) {
        int s1 = -pq.top(); pq.pop();
        
        if(s1 >= K) {
            isPossible = 1;
            break;
        }
        if(pq.empty()) break;
        int s2 = -pq.top(); pq.pop();
        
        cnt++;
        int ns = s1 + s2 * 2;
        pq.push(-ns);
    }
    
    isPossible ? answer = cnt : answer = -1;
    
    return answer;
}