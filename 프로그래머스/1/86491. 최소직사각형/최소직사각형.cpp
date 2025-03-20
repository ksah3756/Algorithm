#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    // 가로, 세로 통틀어 가장 긴 길이는 무조건 포함되고 다른 한 변이 문제
    // 가장 긴 길이가 있는 쪽에 길이가 긴거 다 때려박고 맞은편에는 최대한 작게
    int min_val = 0, max_val = 0;
    // 근데 같은 행으로 가로세로는 불가능
    for(auto v : sizes) {
        if(v[0] > v[1]) swap(v[0], v[1]);
        max_val = max(max_val, v[1]);
        min_val = max(min_val, v[0]);
    }
    answer = max_val * min_val;
    return answer;
}