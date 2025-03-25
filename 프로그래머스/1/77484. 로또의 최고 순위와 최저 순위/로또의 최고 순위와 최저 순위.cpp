#include <string>
#include <vector>

using namespace std;

// 9:44
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<bool> nums(47, 0);
    for(int n : win_nums) nums[n] = 1;
    int sameCnt = 0, zeroCnt = 0;
    for(int n : lottos) {
        if(n == 0) zeroCnt++;
        else if(nums[n]) sameCnt++;
    }
    
    int ans1 = 7 - (sameCnt + zeroCnt);
    if(ans1 == 7) ans1 = 6;
    int ans2 = 7 - sameCnt;
    if(ans2 == 7) ans2 = 6;
    
    answer = {ans1, ans2};
    
    return answer;
}