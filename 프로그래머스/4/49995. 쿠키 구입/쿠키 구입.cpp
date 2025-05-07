#include <string>
#include <vector>

using namespace std;
// 11:05
// l, r 정해놓고 m은 이분탐색으로?
int solution(vector<int> cookie) {
    int answer = -1;
    int size = cookie.size();
    vector<int> sum(size, 0);
    
    int prev = 0;
    for(int i = 0; i < size; i++) {
        sum[i] = prev + cookie[i];
        prev = sum[i];
    }
    
    for(int l = 0; l < size; l++) {
        for(int r = size-1; r > l; r--) {
            int tmpL = l, tmpR = r;
            while(tmpL < tmpR) {
                int m = (tmpL+tmpR) / 2;
                int lSum = sum[m] - sum[l-1];
                int rSum = sum[r] - sum[m];
                if(lSum == rSum) {
                    answer = max(answer, lSum);
                    break;
                }
                if(lSum > rSum) tmpR = m;
                else tmpL = m+1;
            }
        }
    }
    if(answer == -1) answer = 0;
    return answer;
}