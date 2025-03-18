#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int cur, need;
    cur = need = 0;
    int cnt = 0;
    int size = players.size();
    vector<int> down(size, 0);
    
    for(int i = 0 ; i < size; i++) {
        // 필요한 서버 수
        need = players[i] / m;
        // 현재 서버 수 계산
        if(down[i]) {
            if(cur - down[i] > 0) cur -= down[i];
            else cur = 0;
        }
        // 필요한 서버 수 - 현재 서버 수 > 0 이면 그만큼 증설 횟수 추가
        if(need > cur) {
            cnt += (need-cur);
            if(i+k < size) down[i+k] = need-cur;
            cur = need;
        }
    }
    
    answer = cnt;
    return answer;
}