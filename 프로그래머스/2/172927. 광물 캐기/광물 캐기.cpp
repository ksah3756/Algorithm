#include <string>
#include <vector>

using namespace std;
// 6:10
// 다이아가 무조건 제일 좋긴한데
// 일단 한번 사용하면 무조건 광물 5개를 이걸로 캐야하고
// 일단 그리디는 아니고
// 광물 개수가 많지 않아서 depth가 최대 10회니까 완전탐색해도 될듯 
const int INF = 25 * 50 + 1;
int ans = INF;

vector<int> mins;
int table[3][3] = {1,1,1,5,1,1,25,5,1};
void solve(vector<int>& picks, int idx, int cost) {
    if(idx >= mins.size() ||
      (picks[0] == 0 && picks[1] == 0 && picks[2] == 0)) {
        ans = min(ans, cost);
        return;
    }

    for(int i = 0; i < 3; i++) {
        int nxtCost = cost;
        if(picks[i]) {
            for(int j = 0; j < 5 && idx+j < mins.size(); j++) {
                nxtCost += table[i][mins[idx+j]];
            }
            picks[i]--;
            solve(picks, idx+5, nxtCost);
            picks[i]++;
        }
    }
    
}
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    for(const string& s : minerals) {
        if(s.compare("diamond") == 0) {
            mins.push_back(0);
        } else if(s.compare("iron") == 0) {
            mins.push_back(1);
        } else {
            mins.push_back(2);
        }
    }
    
    solve(picks, 0, 0);
    
    ans != INF ? answer = ans : answer = 0;
    return answer;
}



