#include <vector>
#include <unordered_set>
using namespace std;

// 그냥 set에 넣고 set size, N/2 min 값
int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> us;
    
    for(int n : nums) {
        us.insert(n);
    }
    
    answer = min(us.size(), nums.size() / 2);
    
    return answer;
}