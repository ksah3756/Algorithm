#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    int size = citations.size();
    
    int l = 0, r = 10000, mid;
    while(l < r) {
        mid = (l+r+1) / 2;
        int idx = lower_bound(citations.begin(), citations.end(), mid) - citations.begin();
        if(size - idx >= mid) l = mid;
        else r = mid-1;
    }
    
    answer = l;
    return answer;
}